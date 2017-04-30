
#include "FunctionBuilder.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"
#include "ScopeParser.h"
#include "TypeInferer.h"
#include "../TypeInformation/LambdaTypeInformation.h"

using namespace RattleLang;
using namespace std;

FunctionBuilder::FunctionBuilder(Context* context) {
    m_context = context;
}

void FunctionBuilder::StartParsing(const SimpleNode *node, const string& fnName) {
    const ASTLabmdaDefine* def = nullptr;
    m_output.clear();

    if (!dynamic_cast<const ASTFnDef*>(node) &&  !(def = dynamic_cast<const ASTLabmdaDefine*>(node))) {
        throw ParsingException("Cannot deduce function from node type");
    }

    // If LambdaDefine is not nullptr then we are a named function.
    build_function(node, fnName, def);
}

// We need to declare the function first.
shared_ptr<TypeInformation> FunctionBuilder::declare_function(const SimpleNode *node, const string &fnName, bool is_lambda) {
    size_t startIndex = 1;
    size_t paramIndex = is_lambda ? 0 : 2;
    shared_ptr<TypeInformation> information(is_lambda ? new LambdaTypeInformation({}, m_context) : new TypeInformation({}, m_context));

    // Do type list.
    ASTFnTypeList* retTypeList = dynamic_cast<ASTFnTypeList*>(node->jjtGetChild(startIndex));
    if (retTypeList) {
        visit(retTypeList, information.get());
        if (!information || information->isEmpty()) {
            throw TypeException();
        }
    } else {
        paramIndex = is_lambda ? paramIndex : 1;
        information->typenames.push_back(type(VOID, 0));
    }

    // Handle Param List
    ASTParmlist* parmlist = dynamic_cast<ASTParmlist*>(node->jjtGetChild(paramIndex));
    if (!parmlist) {
        throw ParsingException("Cannot Find Parameter List, Fatal Error. ");
    }
    vector<pair<string, type>> params;
    visit(parmlist, &params);

    Context* fnContext = new Context(m_context);
    if (params.size() != 0) {
        for (const auto &param : params) {
            shared_ptr<TypeInformation> varInfo(new TypeInformation({param.second}, fnContext));
            fnContext->add_variable(param.first, varInfo);
            information->inner_vars[param.first] = varInfo;
        }
    }

    // To do?
    m_context->add_function(fnName, information);
    return information;
}

void FunctionBuilder::build_function(const SimpleNode* node, const string& fnName,  bool is_lambda) {
    size_t startIndex = 1;
    size_t paramIndex = is_lambda ? 0 : 2;
    shared_ptr<TypeInformation> information = m_context->get_function(fnName);

    if (!information) {
        information = declare_function(node, fnName, is_lambda);
    }

    // Do type list.
    ASTFnTypeList* retTypeList = dynamic_cast<ASTFnTypeList*>(node->jjtGetChild(startIndex));
    string retType = information->get_typenames();
    paramIndex = retTypeList ? paramIndex : paramIndex - 1;

    // Handle Param List
    ASTParmlist* parmlist = dynamic_cast<ASTParmlist*>(node->jjtGetChild(paramIndex));
    if (!parmlist) {
        throw ParsingException("Cannot Find Parameter List, Fatal Error. ");
    }

    string paramList = "";
    paramList += "(";

    map<string, shared_ptr<TypeInformation>> params = information->inner_vars;
    Context* fnContext = nullptr;
    if (params.size() != 0) {
        for (const auto &param : params) {
            fnContext = param.second->scope;
            paramList += param.second->get_typenames();
            paramList += " " + param.first + ",";
        }
        paramList.pop_back();
    }
    paramList += ")";
    fnContext = fnContext ? fnContext : new Context(m_context);

    m_output = is_lambda ? "[=]" + paramList : retType + " " + fnName + paramList;
    m_output += SCOPE_OPEN;

    ASTFnBody* fnBody = dynamic_cast<ASTFnBody*>(node->jjtGetChild(paramIndex + 1));
    visit(fnBody, fnContext);

    pair<shared_ptr<TypeInformation>, Context*> typeContext = make_pair(information, fnContext);
    if (node->fnHasReturn) {
        ASTReturnExpression* fnReturn = dynamic_cast<ASTReturnExpression*>(node->jjtGetChild(is_lambda ? 3 : paramIndex + 2 ));
        visit(fnReturn, &typeContext);
    }
    m_output += SCOPE_CLOSE;
}

void RattleLang::FunctionBuilder::visit(const RattleLang::ASTFnBody *node, void *data) {
    if (node && data) {
        ScopeParser parser(static_cast<Context *>(data));
        StateMachineParserDecorator<ScopeParser> scopedParser(&parser);
        scopedParser.StartParsing(node);
        m_output += parser.get_c_output();
    }
}

void FunctionBuilder::visit(const ASTReturnExpression *node, void *data) {
    pair<shared_ptr<TypeInformation>, Context*>* typeAndContext =
            static_cast<pair<shared_ptr<TypeInformation>, Context*>*>(data);
    Context* fnContext = typeAndContext->second;
    shared_ptr<TypeInformation> returnValues = typeAndContext->first;
    vector<string> names;
    // How many expressions in
    size_t numChildren = node->jjtGetNumChildren();

    int i = 0;
    bool done = false;
    for (int j = 0; j < numChildren && !done; ++j) {
        ASTExpression* expNode = static_cast<ASTExpression *>(node->jjtGetChild(j));
        shared_ptr<TypeInformation> exp = TypeInferer::get_instance()->StartParsing(expNode, fnContext);
        vector<string> localNames;

        // We've got our types
        for (int k = 0; k < exp->num_return() && !(done = i >= returnValues->num_return()); ++k, ++i) {
            string varname = "_" + to_string(i) +  "fnRetVal";
            m_output += returnValues->typenames[i].get_corresponding_type_string() + " " + varname + ";\n";
            names.push_back(varname);
            localNames.push_back(varname);
        }
        ExpressionOp op(ExpressionOp::ASSIGNMENT, localNames);
        m_output += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, fnContext), expNode);
    }

    m_output += "\nreturn ";
    m_output += numChildren > 1 ? "make_tuple(" : "";
    for (const auto& name : names) {
        m_output += name + ",";
    }
    m_output.pop_back();
    m_output += numChildren > 1 ?");" : ";";
}

void FunctionBuilder::visit(const ASTParmlist *node, void *data) {
    if (node && data) {
        vector<pair<string, type>>* info = static_cast< vector<pair<string, type>>*>(data);
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

void RattleLang::FunctionBuilder::visit(const RattleLang::ASTFnTypeList *node, void *data) {
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

void FunctionBuilder::defaultVisit(const SimpleNode *node, void *data) {

}
