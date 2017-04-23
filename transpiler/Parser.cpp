//
// Created by podgi on 4/12/2017.
//
#include <iostream>
#include "Parser.h"
#include "ScopeParser.h"
#include "../TypeInformation/Context.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"

using namespace RattleLang;


Parser::Parser(ASTCode *code) {
    codeNode = code;
    state = DECLARE;
    cOutput = create_preample();
    context = &Context::global_scope;
}

std::string Parser::get_c_output() {
    return cOutput;
}


void Parser::StartParsing(const SimpleNode *node) {
    ChildrenAccept(node);
}

void Parser::defaultVisit(const SimpleNode *node, void *data) {
    // Do nothing.
}

void Parser::declare(const SimpleNode *node, void *data) {
    node->jjtAccept(this, data);
}


void Parser::implement(const SimpleNode *node, void *data) {
    node->jjtAccept(this, data);
}

void Parser::main(const SimpleNode *node, void *data) {
    node->jjtAccept(this, data);
}

void Parser::visit(const ASTEOF *node, void *data) {
    transitionState(static_cast<RattleCompilerState>(++stateNum));
}


// Declare a class, which means just class : public class;
// We add it to the context, and continue.
void Parser::declare(const ASTClassDef *node, void *data) {
    std::string className = get_token_of_child(node, 0);
    cOutput += "class " + className;

    if (node->polymorphic) {
        cOutput += " : ";
        size_t amtOfChildren = node->jjtGetNumChildren();
        for (int i = 1; i < amtOfChildren ; ++i) {

            if (!dynamic_cast<ASTIdentifier*>(node->jjtGetChild(i))) {
                break;
            }

            auto subclass_name = get_token_of_child(node, i);
            TypeInformation subclass_info = context->get_class_definition(subclass_name );
            if (!subclass_info.isEmpty()) {
                cOutput += " public " + get_token_of_child(node, i) + ",";
            } else {
                throw TypeException();
            }
        }
        // Remove last ","
        cOutput.pop_back();
    }
    type class_type = type(className, EQ_OP);
    TypeInformation class_information({class_type}, context);
    TypeStorage::get_instance()->add_type(class_type);
    context->add_class(className, class_information);
    cOutput += ";\n";
}

void Parser::transitionState(Parser::RattleCompilerState nextState) {
    state = nextState;
    switch(state) {
        case DECLARE:
            StartParsing(codeNode);
        case IMPLEMENT:
            StartParsing(codeNode);
            break;
        case MAIN:
            cOutput += "\n// Main \n";
            cOutput += "int main(int argc, char **argv) ";
            cOutput += SCOPE_OPEN;

            cOutput += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(&Context::global_scope), codeNode);


            cOutput += SCOPE_CLOSE;

            std::cout<<cOutput<<std::endl;
            return;
    }
}

// Should do this better probably..
std::string Parser::create_preample() {
    return  "#include <fstream>\n"
            "#include <iomanip>\n"
            "#include <iostream>\n"
            "#include <tuple>\n"
            "#include <string>\n"
            "using namespace std;\n";
}

void Parser::visit(const SimpleNode *node, void *data) {
    defVisit<SimpleNode>(node, data);
}


void Parser::declare(const ASTAssignment *node, void *data) {
    cOutput += StateMachineParserDecorator<ScopeParser>::GetParserSingleNodeResult(ScopeParser(&Context::global_scope),
                                                                                   node);
}

void Parser::declare(const ASTFnDef *node, void *data) {
    // We want to declare a function.
    std::string fnName = get_token_of_child(node, 0);
    size_t paramIndex = 2;
    ASTFnTypeList* retTypeList = dynamic_cast<ASTFnTypeList*>(node->jjtGetChild(1));
    std::string retType = "";

    TypeInformation information;
    if (retTypeList) {

        declare(retTypeList, &information);
        if (information.isEmpty()) {
            throw TypeException();
        }
        int infoSize = information.typenames.size();
        retType = infoSize > 1 ? "std::tuple<" : "";

        size_t types = information.num_return();
        for (int i = 0; i < types; ++i) {
            retType += information.typenames[i].get_corresponding_type_string() + ",";
        }
        retType.pop_back();
        retType += infoSize > 1 ? ">" : "";
    } else {
        paramIndex = 1;
        information = TypeInformation({type(VOID, 0)}, context);
        retType = "void";
    }

    // Add the function.
    cOutput += retType + " " + fnName;


    // Handle Param List
    ASTParmlist* parmlist = dynamic_cast<ASTParmlist*>(node->jjtGetChild(paramIndex));
    if (!parmlist) {
        throw ParsingException("Cannot Find Parameter List, Fatal Error. ");
    }
    std::vector<std::pair<std::string, type>> params;
    declare(parmlist, &params);
    cOutput+= "(";

    Context* fnContext = new Context(context);
    if (params.size() != 0) {
        for (const auto &param : params) {
            cOutput += param.second.get_corresponding_type_string();
            cOutput += " " + param.first + ",";

            TypeInformation varInfo({param.second}, fnContext);
            fnContext->add_variable(param.first, varInfo);
            information.inner_vars[param.first] = varInfo;
        }
        cOutput.pop_back();
    }
    cOutput+=")";
    cOutput += SCOPE_OPEN;
    context->add_function(fnName, information);

    ASTFnBody* fnBody = dynamic_cast<ASTFnBody*>(node->jjtGetChild(paramIndex + 1));
    declare(fnBody, fnContext);

    if (node->fnHasReturn) {
        ASTReturnExpression* fnReturn = dynamic_cast<ASTReturnExpression*>(node->jjtGetChild(paramIndex + 2));
        declare(fnReturn, fnContext);
    }
    cOutput += SCOPE_CLOSE;

}

void Parser::declare(const ASTFnBody *node, void *data) {
    if (node && data) {
        ScopeParser parser(static_cast<Context *>(data));
        StateMachineParserDecorator<ScopeParser> scopedParser(&parser);
        scopedParser.StartParsing(node);
        cOutput += parser.get_c_output();
    }
}

void Parser::declare(const ASTParmlist *node, void *data) {
    if (node && data) {
        std::vector<std::pair<std::string, type>>* info = static_cast< std::vector<std::pair<std::string, type>>*>(data);
        size_t numChildren = node->jjtGetNumChildren();
        if (numChildren == 0) {
            // It takes no parameters, this is fine.
            return;
        }

        if (numChildren % 2 != 0) {
            throw ParsingException("Parameter should be formatted as id : type, FATAL ERROR.");
        }

        // Get The Parameter Name and Type.
        for (int i = 0; i < numChildren; i += 2) {
            ASTIdentifier* name = static_cast<ASTIdentifier*>(node->jjtGetChild(i));
            ASTIdentifier* type = static_cast<ASTIdentifier*>(node->jjtGetChild(i + 1));

            RattleLang::type param_Type = TypeStorage::get_instance()->get_type(type->tokenValue);
            if (param_Type.type_name == NONE) {
                throw TypeException();
            }

            info->push_back({name->tokenValue, param_Type});
        }
    }
}

// Go through and push all the types
void Parser::declare(const ASTFnTypeList *node, void *data) {
    if (node && data) {
        TypeInformation* typeInfo = static_cast<TypeInformation*>(data);
        size_t childrenSize = node->jjtGetNumChildren();

        for (int i = 0; i < childrenSize ; ++i) {
            ASTIdentifier* id = static_cast<ASTIdentifier*>(node->jjtGetChild(i));
            type currentType = TypeStorage::get_instance()->get_type(id->tokenValue);

            if (currentType.type_name == NONE) {
                throw TypeException();
            }

            typeInfo->typenames.push_back(currentType);
        }
    }
}

void Parser::declare(const ASTReturnExpression *node, void *data) {
    std::string fnName = get_token_of_child(static_cast<SimpleNode *>(node->jjtGetParent()), 0);
    Context* fnContext = static_cast<Context *>(data);
    TypeInformation returnValues = context->get_function(fnName);

    std::vector<std::string> names;
    // How many expressions in
    size_t numChildren = node->jjtGetNumChildren();

    int i = 0;
    bool done = false;
    for (int j = 0; j < numChildren && !done; ++j) {
        ASTExpression* expNode = static_cast<ASTExpression *>(node->jjtGetChild(j));
        TypeInformation exp = TypeInferer::get_instance()->StartParsing(expNode, fnContext);
        std::vector<std::string> localNames;
        // We've got our types
        for (int k = 0; k < exp.num_return() && !(done = i >= returnValues.num_return()); ++k, ++i) {
            std::string varname = "_" + std::to_string(i) + fnName + "ret";
            cOutput += returnValues.typenames[i].get_corresponding_type_string() + " " + varname + ";\n";
            names.push_back(varname);
            localNames.push_back(varname);
        }
        ExpressionOp op(ExpressionOp::ASSIGNMENT, localNames);
        cOutput += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, fnContext), expNode);
    }

    cOutput += "\nreturn ";
    cOutput += numChildren > 1 ? "std::make_tuple(" : "";
    for (const auto& name : names) {
        cOutput += name + ",";
    }
    cOutput.pop_back();
    cOutput += numChildren > 1 ?");" : ";";
}