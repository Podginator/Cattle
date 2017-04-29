
#include "FunctionBuilder.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"
#include "ScopeParser.h"
#include "TypeInferer.h"

using namespace RattleLang;

FunctionBuilder::FunctionBuilder(Context* context) {
    m_context = context;
}

void FunctionBuilder::StartParsing(const SimpleNode *node, const std::string& fnName) {
    const ASTLabmdaDefine* def = nullptr;
    if (!dynamic_cast<const ASTFnDef*>(node) ||  (def = dynamic_cast<const ASTLabmdaDefine*>(node))) {
        throw ParsingException("Cannot deduce function from node type");
    }

    // If LambdaDefine is not nullptr then we are a named function.
    build_function(node, fnName, def);
}

void FunctionBuilder::build_function(const SimpleNode* node, const std::string& fnName,  bool is_lambda) {
    size_t startIndex = is_lambda ? 0 : 1;
    size_t paramIndex = startIndex + 1;

    // Do type list.
    ASTFnTypeList* retTypeList = dynamic_cast<ASTFnTypeList*>(node->jjtGetChild(startIndex));
    std::string retType = "";
    std::shared_ptr<TypeInformation> information(new TypeInformation());
    if (retTypeList) {
        visit(retTypeList, information.get());
        if (!information || information->isEmpty()) {
            throw TypeException();
        }

        retType = information->get_typenames();
    } else {
        paramIndex -= 1;
        information = std::shared_ptr<TypeInformation>(new TypeInformation({type(VOID, 0)}, m_context));
        retType = "void";
    }

    // Add the function.
    m_output += retType + " " + fnName;

    // Handle Param List
    ASTParmlist* parmlist = dynamic_cast<ASTParmlist*>(node->jjtGetChild(paramIndex));
    if (!parmlist) {
        throw ParsingException("Cannot Find Parameter List, Fatal Error. ");
    }
    std::vector<std::pair<std::string, type>> params;
    visit(parmlist, &params);
    m_output += "(";

    Context* fnContext = new Context(m_context);
    if (params.size() != 0) {
        for (const auto &param : params) {
            m_output += param.second.get_corresponding_type_string();
            m_output += " " + param.first + ",";

            std::shared_ptr<TypeInformation> varInfo(new TypeInformation({param.second}, fnContext));
            fnContext->add_variable(param.first, varInfo);
            information->inner_vars[param.first] = varInfo;
        }
        m_output.pop_back();
    }
    m_output += ")";
    m_output += SCOPE_OPEN;
    m_context->add_function(fnName, information);

    ASTFnBody* fnBody = dynamic_cast<ASTFnBody*>(node->jjtGetChild(paramIndex + 1));
    visit(fnBody, fnContext);

    if (node->fnHasReturn) {
        ASTReturnExpression* fnReturn = dynamic_cast<ASTReturnExpression*>(node->jjtGetChild(paramIndex + 2));
        visit(fnReturn, fnContext);
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
    std::string fnName = get_token_of_child(static_cast<SimpleNode *>(node->jjtGetParent()), 0);
    Context* fnContext = static_cast<Context *>(data);
    std::shared_ptr<TypeInformation> returnValues = m_context->get_function(fnName);

    std::vector<std::string> names;
    // How many expressions in
    size_t numChildren = node->jjtGetNumChildren();

    int i = 0;
    bool done = false;
    for (int j = 0; j < numChildren && !done; ++j) {
        ASTExpression* expNode = static_cast<ASTExpression *>(node->jjtGetChild(j));
        std::shared_ptr<TypeInformation> exp = TypeInferer::get_instance()->StartParsing(expNode, fnContext);
        std::vector<std::string> localNames;

        // We've got our types
        for (int k = 0; k < exp->num_return() && !(done = i >= returnValues->num_return()); ++k, ++i) {
            std::string varname = "_" + std::to_string(i) + fnName + "ret";
            m_output += returnValues->typenames[i].get_corresponding_type_string() + " " + varname + ";\n";
            names.push_back(varname);
            localNames.push_back(varname);
        }
        ExpressionOp op(ExpressionOp::ASSIGNMENT, localNames);
        m_output += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, fnContext), expNode);
    }

    m_output += "\nreturn ";
    m_output += numChildren > 1 ? "std::make_tuple(" : "";
    for (const auto& name : names) {
        m_output += name + ",";
    }
    m_output.pop_back();
    m_output += numChildren > 1 ?");" : ";";
}

void FunctionBuilder::visit(const ASTParmlist *node, void *data) {
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

        data = typeInfo;
    }
}

void FunctionBuilder::defaultVisit(const SimpleNode *node, void *data) {

}
