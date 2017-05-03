#include <iostream>
#include "ExpressionParser.h"
#include "../exceptions/TypeException.h"
#include "TypeInferer.h"
#include "../exceptions/ParameterException.h"
#include "FunctionBuilder.h"
#include "../TypeInformation/LambdaTypeInformation.h"

using namespace RattleLang;
using namespace std;

void ExpressionParser::StartParsing(const SimpleNode* n) {
    isMultiAssign = isMultiAssignment(n);
    expectedOutput = TypeInferer::get_instance()->StartParsing(dynamic_cast<const ASTExpression*>(n), m_context);

    // Do an initial pass for this, ensuring that we first elaborate on any functions.
    ChildrenAccept(n);
    res.append(returnedExpressions[0]);

    // Do the expression pass
    state = EXPRESSION_PASS;
    DoEachExpression(n);
    const_cast<SimpleNode*>(n)->isDone = true;
    for (int i = 1; i < returnedExpressions.size(); i++) {
        if (parent.parents.size() > i-1) {
            res.append(parent.parents[i - 1] + " = ");
        }
        res.append(returnedExpressions[i] + ";\n");
    }

    if (hasFnCalls) {
        res.append(SCOPE_CLOSE);
    }
}

void ExpressionParser::visit_fnPass(const ASTTupleDefine *node, void *data) {
}

void ExpressionParser::defaultVisit(const SimpleNode *node, void *data) {
    // Do nothing.
}

void ExpressionParser::visit_expressionPass(const ASTOr *node, void *data) {
    doExpression(node, "||");
}

void ExpressionParser::visit_expressionPass(const ASTAnd *node, void *data) {
    doExpression(node, "&&");
}

void ExpressionParser::visit_expressionPass(const ASTCompEqual *node, void *data) {
    doExpression(node, "==");
}

void ExpressionParser::visit_expressionPass(const ASTCompNequal *node, void *data) {
    doExpression(node, "!=");
}

void ExpressionParser::visit_expressionPass(const ASTCompGTE *node, void *data) {
    doExpression(node, ">=");
}

void ExpressionParser::visit_expressionPass(const ASTCompLTE *node, void *data) {
    doExpression(node, "<=");
}

void ExpressionParser::visit_expressionPass(const ASTCompGT *node, void *data) {
    doExpression(node, ">");
}

void ExpressionParser::visit_expressionPass(const ASTCompLT *node, void *data) {
    doExpression(node, "<");
}

void ExpressionParser::visit_expressionPass(const ASTAdd *node, void *data) {
    doExpression(node, "+");
}

void ExpressionParser::visit_expressionPass(const ASTSubtract *node, void *data) {
    doExpression(node, "-");
}

void ExpressionParser::visit_expressionPass(const ASTTimes *node, void *data) {
    doExpression(node, "*");
}

void ExpressionParser::visit_expressionPass(const ASTDivide *node, void *data) {
    doExpression(node, "/");
}

void ExpressionParser::visit_expressionPass(const ASTUnaryNot *node, void *data) {
    AppendToResult("!");
    ChildAccept(node, 0, data);
}

void ExpressionParser::visit_expressionPass(const ASTUnaryPlus *node, void *data) {
    AppendToResult("+");
    ChildAccept(node, 0, data);
}

void ExpressionParser::visit_expressionPass(const ASTUnaryMinus *node, void *data) {
    AppendToResult("-");
    ChildAccept(node, 0, data);
}

void ExpressionParser::visit_expressionPass(const ASTIdentifier *node, void *data) {
    if (data) {
        int val = *(static_cast<int *>(data));
        AppendToResult("get<" + to_string(val) + ">" + "(");
    }
    AppendToResult(get_token_of_node(node) + (data ? ")" : ""));
}

void ExpressionParser::visit_expressionPass(const ASTDereference *node, void *data) {
    if (isMultiAssign) {
        string name(get_token_of_child(node, 0));
        AppendToResult("get<0>(" + name + ")");
        for (int i = 1; i < parent.parents.size(); i++) {
            string name(((SimpleNode *) node->jjtGetChild(0))->tokenValue);
            returnedExpressions.push_back("get<" + to_string(i) + ">(" + name + ")");
        }
    } else {
        ChildAccept(node, 0, data);
    }
}

void ExpressionParser::visit_expressionPass(const ASTExpression *node, void *data) {
    returnedExpressions.back() += "(";
    ChildrenAccept(node, data);
    returnedExpressions.back() += ")";
    const_cast<ASTExpression*>(node)->isDone = true;
}

void ExpressionParser::visit_fnPass(const ASTExpression *node, void* data) {
    ChildrenAccept(node, data);
    const_cast<ASTExpression*>(node)->isDone = true;
}

void ExpressionParser::visit_fnPass(const ASTFnInvoke *node, void *data) {

    string name = get_token_of_child(node,  0);
    const_cast<ASTFnInvoke *>(node)->isDone = true;

    if (!hasFnCalls) {
        AppendToResult(SCOPE_OPEN);
        hasFnCalls = true;
    }

    // Get the function name.
    // Check how many return values there are.
    // Unnecessary unless we're doing a multi assign.
    TypeInfoPtr type_info = m_context->get_function(name);
    if (TypeInformation::is_empty(type_info)) {
        throw TypeException(get_line_num(node));
    }

    vector<type> types = type_info->typenames;
    string fnCall = name + "(";
    string uniqueName = get_unique_name(name);
    m_fnCallName[node] = uniqueName;

    if (!type_info->is_void()) {
        AppendToResult(type_info->get_c_typename() + " " + uniqueName + ";\n");
        fnCall.insert(0, "\n" + uniqueName + "=");
    }

    ChildAccept(node, 1, data);
    AppendToResult(fnCall);

    // Perform an iteration expanding out all the nodes
    state = EXPRESSION_PASS;
    ChildAccept(node, 1, data);
    state = FN_PASS;

    AppendToResult(");\n");


}

void ExpressionParser::visit_expressionPass(const ASTFnInvoke *node, void *data) {
    string name = get_token_of_child(node, 0);
    int start_index = data ? *((int*)data) : 0;
    TypeInfoPtr fn_info = m_context->get_function(name);

    if (!fn_info->is_void()) {
        if (!isMultiAssign && !data) {
            AppendToResult(m_fnCallName[node]);
            return;
        }

        AppendToResult("get<" + to_string(start_index) + ">(" + m_fnCallName[node] + ")");
        if (returnedExpressions.size() - 1 != parent.parents.size()) {
            for (int i = 1; i < parent.parents.size(); i++) {
                string multi("get<" + to_string(i) + ">(" + m_fnCallName[node] + ")");

                if (!data) {
                    returnedExpressions.push_back(multi);
                } else {
                    AppendToResult(multi);
                }
            }
        }
    }
}

void ExpressionParser::visit_expressionPass(const ASTCharacter *node, void *data) {
    PrintNode(node);
}

void ExpressionParser::visit_expressionPass(const ASTString *node, void *data) {
    AppendToResult("string(");
    PrintNode(node);
    AppendToResult(")");
}

void ExpressionParser::visit_expressionPass(const ASTNumber *node, void *data) {
    PrintNode(node);
}

void ExpressionParser::visit_expressionPass(const ASTTrue *node, void *data) {
    AppendToResult("true");
}

void ExpressionParser::visit_expressionPass(const ASTFalse *node, void *data) {
    AppendToResult("false");
}

void ExpressionParser::PrintNode(const SimpleNode *node) {
    AppendToResult(get_token_of_node(node));
}

// An expression might not be a "Base Expression" "1" + 2 but might instead be "1" + 2+3+4
void ExpressionParser::doExpression(const SimpleNode *n, const string &expression) {
    TypeInfoPtr expression_info = get_type_info(n);

    string preample = needs_converting(expression_info) ? "to_string(" : "";
    AppendToResult(preample);

    // Wrap the typename to ensure we don't get instances where we're getting an int instead
    // of "number" (or double)
    AppendToResult(expression_info->get_c_typename()+"(");
    convert_if_needed(get_child_as<SimpleNode>(n, 0));
    AppendToResult(expression);
    convert_if_needed(get_child_as<SimpleNode>(n, 1));
    AppendToResult(")");
}


shared_ptr<TypeInformation> ExpressionParser::get_type_info(const SimpleNode *node) {
    ASTExpression* exp = new ASTExpression(0);
    exp->jjtAddChild(const_cast<SimpleNode*>(node),0);
    return TypeInferer::get_instance()->StartParsing(exp, m_context);
}

void ExpressionParser::convert_if_needed(SimpleNode *node) {
    TypeInfoPtr expression_info = get_type_info(node);
    TypeInfoPtr old = this->expectedOutput;
    bool convert = needs_converting(expression_info);
    expectedOutput = expression_info;

    if (convert) {
        AppendToResult("to_string(");
        Accept(node, nullptr);
        AppendToResult(")");
    } else {
        Accept(node, nullptr);
    }

    expectedOutput = old;
}

bool ExpressionParser::needs_converting(SimpleNode *node) {
    ASTExpression* exp = new ASTExpression(0);
    exp->jjtAddChild(node,0);
    TypeInfoPtr expression_info = TypeInferer::get_instance()->StartParsing(exp, m_context);

    return needs_converting(expression_info);
}

bool ExpressionParser::needs_converting(TypeInfoPtr expression_info) {
    return (expectedOutput->num_return() == 1 && expectedOutput->typenames[0].type_name == STRING) &&
    (expression_info->num_return() == 1 && expression_info->typenames[0].type_name == NUMBER);
}

bool ExpressionParser::isMultiAssignment(const SimpleNode *exp) {
    return parent.parents.size() != 1 && (get_child_as<ASTFnInvoke>(exp, 0) || get_child_as<ASTDereference>(exp,0));
}

void ExpressionParser::visit_fnPass(const ASTArgList *node, void *data) {
    int children_size = get_number_children(node);
    string fn_name = get_token_of_node(node->jjtGetParent()->jjtGetChild(0));
    TypeInfoPtr fn_type = m_context->get_function(fn_name);

    // We shouldn't get here, but if we do throw an exception.
    if (TypeInformation::is_empty(fn_type)) {
        throw TypeException(get_line_num(node));
    }

    int expected_params = fn_type->inner_vars.size();
    int total_params = 0;

    string function_c_name = m_fnCallName[node->jjtGetParent()];
    if (children_size > 0) {
        for (size_t i = 0; i < children_size; ++i) {
            ASTExpression *exp = get_child_as<ASTExpression>(node, i);
            TypeInfoPtr expression_type = TypeInferer::get_instance()->StartParsing(exp, fn_type->scope);
            if (TypeInformation::is_empty(expression_type)) {
                throw TypeException(get_line_num(node));
            }

            vector<string> param_names;
            size_t resultSize = expression_type->num_return();

            if (dynamic_pointer_cast<LambdaTypeInformation>(expression_type)) {
                param_names.push_back(function_c_name + "param" + to_string(total_params));
                AppendToResult(expression_type->get_c_return_types() + " " + function_c_name + "param" +
                               to_string(total_params) + ";\n");
                total_params++;
            } else {
                for (size_t j = 0; j < resultSize; ++j, ++total_params) {
                    param_names.push_back(function_c_name + "param" + to_string(total_params));
                    AppendToResult(expression_type->typenames[j].get_corresponding_type_string() + " "
                                   + function_c_name + "param" +  to_string(total_params) + ";\n");
                }
            }

            AppendToResult(StateMachineParserDecorator<ExpressionParser>::GetParserResults(
                    ExpressionParser(ExpressionOp(ExpressionOp::ASSIGNMENT, param_names), m_context), exp));
        }

        if (total_params != expected_params) {
            throw ParameterException(get_line_num(node));
        }
        returnedExpressions.back().pop_back();
    }
}

void ExpressionParser::visit_expressionPass(const ASTArgList *node, void *data) {
    string function_c_name = m_fnCallName[node->jjtGetParent()];
    string function_rattle_name = get_token_of_node((node->jjtGetParent()->jjtGetChild(0)));
    int param_size = m_context->get_function(function_rattle_name)->num_return();

    if (param_size > 0) {
        for (size_t i = 0; i < param_size; ++i) {
            AppendToResult(function_c_name + "param" + to_string(i));
            AppendToResult(",");
        }
        returnedExpressions.back().pop_back();
    }
}

void ExpressionParser::AppendToResult(const string &res) {
    returnedExpressions.back().append(res);
}

void ExpressionParser::DoEachExpression(const SimpleNode *node) {
    size_t children_size = get_number_children(node);

    for (size_t i = 0; i < children_size; ++i) {
        returnedExpressions.push_back("");
        node->jjtGetChild(i)->jjtAccept(ref, nullptr);
    }
}

// Pass down the expected index for the function return.
void ExpressionParser::visit_expressionPass(const ASTIndexedExpression *node, void *data) {
    ASTNumber* index_node = get_child_as<ASTNumber>(node, 1);
    int value = atoi(get_token_of_node(index_node).c_str());
    ChildAccept(node, 0 ,&value);
}

void ExpressionParser::visit_fnPass(const ASTIndexedExpression *node, void *data) {
    ChildAccept(node, 0 ,data);
}

void ExpressionParser::visit_expressionPass(const ASTTupleDefine *node, void *data) {
    size_t node_children_size = get_number_children(node);
    vector<string> allNames;
    res.append(SCOPE_OPEN);

    for (int i = 0; i < node_children_size; ++i) {
        ASTExpression* exp = get_child_as<ASTExpression>(node, i);
        TypeInfoPtr info = TypeInferer::get_instance()->StartParsing(exp, m_context);

        if (TypeInformation::is_empty(info)) {
            throw TypeException(get_line_num(node));
        }

        vector<string> names;
        size_t amount_returned = info->num_return();
        for (int j = 0; j < amount_returned; ++j) {
            string unique_name = get_unique_name("tuple_assign");
            res.append(info->typenames[j].get_corresponding_type_string() + " " + unique_name + ";\n");

            names.push_back(unique_name);
            allNames.push_back(unique_name);
        }

        res.append(StateMachineParserDecorator<ExpressionParser>::GetParserResults(
                ExpressionParser(ExpressionOp(ExpressionOp::ASSIGNMENT, names), m_context), exp));
    }

    AppendToResult("make_tuple(");
    AppendToResult(StringHelper::combine_str(allNames, ','));
    AppendToResult(");");

    AppendToResult(SCOPE_CLOSE);

}

void ExpressionParser::visit_expressionPass(const ASTLambdaDefine *node, void *data) {
    FunctionBuilder builder(m_context);
    SimpleNode* parent = get_parent_as<SimpleNode>(node, 2);
    builder.StartParsing(node, get_token_of_child(parent, 0));
    AppendToResult(builder.get_c_output());
}
