
#include "FunctionBuilder.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"
#include "ScopeParser.h"
#include "TypeInferer.h"
#include "../TypeInformation/LambdaTypeInformation.h"
#include "../misc/StringHelper.h"

using namespace RattleLang;
using namespace std;

FunctionBuilder::FunctionBuilder(Context* context) {
    m_context = context;
}

void FunctionBuilder::StartParsing(const SimpleNode *node, const string& fnName) {
    m_output.clear();

    const ASTLambdaDefine* def = nullptr;
    if (!get_node_as<ASTFnDef>(node) &&  !(def = get_node_as<ASTLambdaDefine>(node))) {
        throw ParsingException("No function found ", get_line_num(node));
    }

    // If LambdaDefine is not nullptr then we are a named function.
    build_function(node, fnName, def != nullptr);
}

// We need to declare the function first.
TypeInfoPtr FunctionBuilder::declare_function(const SimpleNode *node, const string &fnName, bool is_lambda) {
    size_t paramIndex = is_lambda ? 0 : 2;
    TypeInfoPtr information(is_lambda ? new LambdaTypeInformation({}, m_context) : new TypeInformation({}, m_context));

    // Do type list.
    ASTFnTypeList* retTypeList = get_child_as<ASTFnTypeList>(node, 1);
    if (retTypeList) {
        visit(retTypeList, &information);
        if (TypeInformation::is_empty(information)) {
            throw TypeException(get_line_num(node));
        }
    } else {
        paramIndex = is_lambda ? paramIndex : 1;
        information->typenames.push_back(type(VOID, 0));
    }

    // Handle Param List
    ASTParmlist* parmlist = get_child_as<ASTParmlist>(node, paramIndex);
    if (!parmlist) {
        throw ParsingException("Cannot Find Parameter List, Fatal Error. ", get_line_num(node));
    }

    Context* fnContext = new Context(m_context);
    vector<NamedVariableInfo> params;
    visit(parmlist, &params);
    if (params.size() != 0) {
        for (const auto &param : params) {
            param.second->set_scope(fnContext);
            fnContext->add_variable(param.first, param.second);
            information->inner_vars.push_back(param);
        }
    }

    m_context->add_function(fnName, information);
    return information;
}

void FunctionBuilder::build_function(const SimpleNode* node, const string& fnName,  bool is_lambda) {
    size_t paramIndex = is_lambda ? 0 : 2;
    TypeInfoPtr information = m_context->get_function(fnName);

    if (!information) {
        information = declare_function(node, fnName, is_lambda);
    }

    // Do type list.
    ASTFnTypeList* retTypeList = get_child_as<ASTFnTypeList>(node, 1);
    string retType = information->get_c_typename();
    paramIndex = retTypeList ? paramIndex : paramIndex - 1;

    // Handle Param List
    ASTParmlist* parmlist = get_child_as<ASTParmlist>(node, paramIndex);
    if (!parmlist) {
        throw ParsingException("Cannot Find Parameter List, Fatal Error. ", get_line_num(node));
    }

    vector<NamedVariableInfo> params = information->inner_vars;
    Context* fnContext = new Context(m_context);
    string paramList = "(";
    if (params.size() != 0) {
        for (const auto &param : params) {
            fnContext = param.second->scope;
            paramList += param.second->get_c_return_types() + " " + param.first + ",";
        }
        paramList.pop_back();
    }
    paramList += ")";

    m_output = is_lambda ? ("[=]" + paramList) : (retType + " " + fnName + paramList);
    m_output += SCOPE_OPEN;

    ASTFnBody* fnBody = get_child_as<ASTFnBody>(node, paramIndex+1);
    visit(fnBody, fnContext);
    pair<TypeInfoPtr, Context*> typeContext = make_pair(information, fnContext);
    if (node->fnHasReturn) {
        size_t returnIndex = is_lambda ? 3 : paramIndex + 2;
        ASTReturnExpression* fnReturn = get_child_as<ASTReturnExpression>(node, returnIndex);
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
    pair<TypeInfoPtr, Context*>* typeAndContext =
            static_cast< pair<TypeInfoPtr, Context*>* >(data);
    Context* fnContext = typeAndContext->second;
    TypeInfoPtr returnValues = typeAndContext->first;
    vector<string> names;
    size_t numChildren = node->jjtGetNumChildren();

    int i = 0;
    bool done = false;
    for (int j = 0; j < numChildren && !done; ++j) {
        ASTExpression* expNode = get_child_as<ASTExpression>(node, j);
        TypeInfoPtr exp = TypeInferer::get_instance()->StartParsing(expNode, fnContext);
        vector<string> localNames;

        // We've got our types
        for (int k = 0; k < exp->num_return() && !(done = i >= returnValues->num_return()); ++k, ++i) {
            string varname = "_" + to_string(i) +  "fnRetVal";
            m_output += returnValues->typenames[i].get_corresponding_type_string() + " " + varname + ";\n";
            names.push_back(varname);
            localNames.push_back(varname);
        }
        ExpressionOp op(ExpressionOp::ASSIGNMENT, localNames);
        m_output += GetParserResults(ExpressionParser(op, fnContext), expNode);
    }

    m_output += "\nreturn ";
    m_output += numChildren > 1 ? "make_tuple(" : "";
    m_output += StringHelper::combine_str(names, ',');
    m_output += numChildren > 1 ?");" : ";";
}

void FunctionBuilder::visit(const ASTParmlist *node, void *data) {
    vector<pair<string, TypeInfoPtr>>* info =
            static_cast<vector<pair<string, TypeInfoPtr>>*>(data);
    size_t numChildren = node->jjtGetNumChildren();

    // We can be parameterless.
    if (numChildren == 0) {
        return;
    }

    // We expect our parameters in the form (name : type) - So if it were just (a) this would be incorrect.
    if (numChildren % 2 != 0) {
        throw ParsingException("Parameter should be formatted as id : type, FATAL ERROR.", get_line_num(node));
    }

    // Get The Parameter Name and Type.
    for (int i = 0; i < numChildren; i += 2) {
        ASTIdentifier* name = get_child_as<ASTIdentifier>(node, i);
        TypeInfoPtr parameter_info;
        node->jjtGetChild(i+1)->jjtAccept(this, &parameter_info);
        info->push_back({name->tokenValue, parameter_info});
    }
}

void FunctionBuilder::visit(const ASTIdentifier *node, void *data) {
    auto parameter_info = static_cast<TypeInfoPtr*>(data);
    RattleLang::type param_Type = TypeStorage::get_instance()->get_type(node->tokenValue);
    if (param_Type.type_name == NONE) {
        throw ParsingException("Unrecognized type passed as function parameter", get_line_num(node));
    }
    *parameter_info = TypeInfoPtr(new TypeInformation({param_Type}, nullptr));
}

void FunctionBuilder::visit(const ASTLambdaPass *node, void *data) {
    auto parameter_info = static_cast<TypeInfoPtr*>(data);
    *parameter_info = TypeInfoPtr(new LambdaTypeInformation());

    size_t children = node->jjtGetNumChildren();
    // FN<type, type, type>(type,type,type)
    for (int j = 0; j < children - 1; ++j) {
        ASTIdentifier* id = static_cast<ASTIdentifier*>(node->jjtGetChild(j));
        RattleLang::type param_Type = TypeStorage::get_instance()->get_type(id->tokenValue);
        if (param_Type.type_name == NONE) {
            throw ParsingException("Unrecognized type passed as function parameter", get_line_num(node));
        }
        (*parameter_info)->typenames.push_back(param_Type);
    }

    ASTLambdaIds* lambda_identifiers = static_cast<ASTLambdaIds*>(node->jjtGetChild(children-1));
    children = lambda_identifiers->jjtGetNumChildren();
    for (int j = 0; j < children; ++j) {
        ASTIdentifier* id = static_cast<ASTIdentifier*>(lambda_identifiers->jjtGetChild(j));
        RattleLang::type param_Type = TypeStorage::get_instance()->get_type(id->tokenValue);

        if (param_Type.type_name == NONE) {
            throw ParsingException("Unrecognized type passed as function parameter", get_line_num(node));
        }

        pair<string, TypeInfoPtr> retPair = make_pair(to_string(j), TypeInfoPtr(new TypeInformation({param_Type})));
        (*parameter_info)->inner_vars.push_back(retPair);
    }
}

void RattleLang::FunctionBuilder::visit(const RattleLang::ASTFnTypeList *node, void *data) {
    if (node && data) {
        TypeInfoPtr* typeInfo = static_cast<TypeInfoPtr*>(data);
        size_t childrenSize = node->jjtGetNumChildren();

        for (int i = 0; i < childrenSize ; ++i) {
            ASTIdentifier* id = get_child_as<ASTIdentifier>(node, i);
            type currentType = TypeStorage::get_instance()->get_type(id->tokenValue);

            if (currentType.type_name == NONE) {
                throw TypeException(get_line_num(node));
            }

            (*typeInfo)->typenames.push_back(currentType);
        }
    }
}

void FunctionBuilder::defaultVisit(const SimpleNode *node, void *data) {

}
