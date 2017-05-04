#include "BasicExpressionCombiner.h"
#include "../../exceptions/TypeException.h"
#include "../TypeInferer.h"
#include "../ExpressionParser.h"
#include "../../TypeInformation/LambdaTypeInformation.h"
#include "../../exceptions/ParameterException.h"
#include "../FunctionBuilder.h"


using namespace RattleLang;


BasicExpressionCombiner::BasicExpressionCombiner(RattleLang::Context *m_context)
        : DefaultExpressionCombiner(m_context) {
    ref = new StateMachineParserDecorator<DefaultExpressionCombiner>(this);

}

ExpressionCombinerResult BasicExpressionCombiner::combine_statement(const SimpleNode *node, operands operand) {
    expected_output = get_type_info(node);
    res.expressions.push_back("");
    // Do an initial pass for this, ensuring that we first elaborate on any functions.
    ChildrenAccept(node);

    // Do the expression pass
    state = EXPRESSION_PASS;
    do_each_expression(node);
    const_cast<SimpleNode*>(node)->isDone = true;

    return res;

}

void BasicExpressionCombiner::do_each_expression(const SimpleNode *node) {
    size_t children_size = get_number_children(node);
    for (size_t i = 0; i < children_size; ++i) {
        res.expressions.push_back("");
        node->jjtGetChild(i)->jjtAccept(ref, nullptr);
    }
}


void BasicExpressionCombiner::visit_fn_pass(const ASTTupleDefine *node, void *data) {
}

void BasicExpressionCombiner::visit_expression_pass(const ASTOr *node, void *data) {
    do_expression(node, "||");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTAnd *node, void *data) {
    do_expression(node, "&&");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTCompEqual *node, void *data) {
    do_expression(node, "==");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTCompNequal *node, void *data) {
    do_expression(node, "!=");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTCompGTE *node, void *data) {
    do_expression(node, ">=");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTCompLTE *node, void *data) {
    do_expression(node, "<=");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTCompGT *node, void *data) {
    do_expression(node, ">");
}

void BasicExpressionCombiner::do_expression(const SimpleNode *n, const string &expression) {
    TypeInfoPtr expression_info = get_type_info(n);

    string preample = needs_converting(expression_info) ? "to_string(" : "";
    append_to_result(preample);

    // Wrap the typename to ensure we don't get instances where we're getting an int instead
    // of "number" (or double)
    append_to_result(expression_info->get_c_typename() + "(");
    convert_if_needed(get_child_as<SimpleNode>(n, 0));
    append_to_result(expression);
    convert_if_needed(get_child_as<SimpleNode>(n, 1));
    append_to_result(")");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTCompLT *node, void *data) {
    do_expression(node, "<");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTAdd *node, void *data) {
    do_expression(node, "+");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTSubtract *node, void *data) {
    do_expression(node, "-");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTTimes *node, void *data) {
    do_expression(node, "*");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTDivide *node, void *data) {
    do_expression(node, "/");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTUnaryNot *node, void *data) {
    append_to_result("!");
    ChildAccept(node, 0, data);
}

void BasicExpressionCombiner::visit_expression_pass(const ASTUnaryPlus *node, void *data) {
    append_to_result("+");
    ChildAccept(node, 0, data);
}

void BasicExpressionCombiner::visit_expression_pass(const ASTUnaryMinus *node, void *data) {
    append_to_result("-");
    ChildAccept(node, 0, data);
}

void BasicExpressionCombiner::visit_expression_pass(const ASTIdentifier *node, void *data) {
    if (data) {
        int val = *(static_cast<int *>(data));
        append_to_result("get<" + to_string(val) + ">" + "(");
    }
    append_to_result(get_token_of_node(node) + (data ? ")" : ""));
}

void BasicExpressionCombiner::visit_expression_pass(const ASTDereference *node, void *data) {
    ChildAccept(node, 0, data);
}

void BasicExpressionCombiner::visit_expression_pass(const ASTExpression *node, void *data) {
    append_to_result("(");
    ChildrenAccept(node, data);
    append_to_result(")");
    const_cast<ASTExpression*>(node)->isDone = true;
}

void BasicExpressionCombiner::visit_fn_pass(const ASTExpression *node, void* data) {
    ChildrenAccept(node, data);
    const_cast<ASTExpression*>(node)->isDone = true;
}

void BasicExpressionCombiner::visit_fn_pass(const ASTFnInvoke *node, void *data) {
    string name = get_token_of_child(node,  0);
    const_cast<ASTFnInvoke *>(node)->isDone = true;

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
    m_fn_call_name[node] = uniqueName;

    if (!type_info->is_void()) {
        append_to_preamble(type_info->get_c_typename() + " " + uniqueName + ";\n");
        fnCall.insert(0, "\n" + uniqueName + "=");
    }

    ChildAccept(node, 1, data);
    append_to_preamble(fnCall);

    // Perform an iteration expanding out all the nodes
    state = EXPRESSION_PASS;
    ChildAccept(node, 1, data);
    state = FN_PASS;

    append_to_preamble(");\n");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTFnInvoke *node, void *data) {
    string name = get_token_of_child(node, 0);
    int start_index = data ? *((int*)data) : 0;
    TypeInfoPtr fn_info = m_context->get_function(name);

    if (!fn_info->is_void()) {
        append_to_result("get<" + to_string(start_index) + ">(" + m_fn_call_name[node] + ")");
        for (int i = 1; i < fn_info->num_return(); i++) {
            string multi("get<" + to_string(i) + ">(" + m_fn_call_name[node] + ")");

            if (!data) {
                res.expressions.push_back(multi);
            } else {
                append_to_result(multi);
            }
        }
    }
}


void BasicExpressionCombiner::visit_expression_pass(const ASTCharacter *node, void *data) {
    print_node(node);
}

void BasicExpressionCombiner::visit_expression_pass(const ASTString *node, void *data) {
    append_to_result("string(");
    print_node(node);
    append_to_result(")");
}

void BasicExpressionCombiner::visit_expression_pass(const ASTNumber *node, void *data) {
    print_node(node);
}

void BasicExpressionCombiner::visit_expression_pass(const ASTTrue *node, void *data) {
    append_to_result("true");
}

void BasicExpressionCombiner::print_node(const SimpleNode *node) {
    append_to_result(get_token_of_node(node));

}

void BasicExpressionCombiner::visit_expression_pass(const ASTFalse *node, void *data) {
    append_to_result("false");
}

// Pass down the expected index for the function return.
void BasicExpressionCombiner::visit_expression_pass(const ASTIndexedExpression *node, void *data) {
    ASTNumber* index_node = get_child_as<ASTNumber>(node, 1);
    int value = atoi(get_token_of_node(index_node).c_str());
    ChildAccept(node, 0 ,&value);
}

void BasicExpressionCombiner::visit_fn_pass(const ASTIndexedExpression *node, void *data) {
    ChildAccept(node, 0 ,data);
}

void BasicExpressionCombiner::visit_expression_pass(const ASTTupleDefine *node, void *data) {
    size_t node_children_size = get_number_children(node);
    vector<string> allNames;
    append_to_preamble(SCOPE_OPEN);

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
            append_to_preamble(info->typenames[j].get_corresponding_type_string() + " " + unique_name + ";\n");

            names.push_back(unique_name);
            allNames.push_back(unique_name);
        }

        append_to_preamble(GetParserResults(ExpressionParser(ExpressionOp(ExpressionOp::ASSIGNMENT, names), m_context), exp));
    }

    append_to_result("make_tuple(");
    append_to_result(StringHelper::combine_str(allNames, ','));
    append_to_result(");");

    append_to_result(SCOPE_CLOSE);

}

void BasicExpressionCombiner::visit_expression_pass(const ASTLambdaDefine *node, void *data) {
    FunctionBuilder builder(m_context);
    SimpleNode* parent = get_parent_as<SimpleNode>(node, 2);
    builder.StartParsing(node, get_token_of_child(parent, 0));
    append_to_result(builder.get_c_output());
}

void BasicExpressionCombiner::visit_fn_pass(const ASTArgList *node, void *data) {
    int children_size = get_number_children(node);
    string fn_name = get_token_of_node(node->jjtGetParent()->jjtGetChild(0));
    TypeInfoPtr fn_type = m_context->get_function(fn_name);

    // We shouldn't get here, but if we do throw an exception.
    if (TypeInformation::is_empty(fn_type)) {
        throw TypeException(get_line_num(node));
    }

    int expected_params = fn_type->inner_vars.size();
    int total_params = 0;

    string function_c_name = m_fn_call_name[node->jjtGetParent()];
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
                append_to_preamble(expression_type->get_c_return_types() + " " + function_c_name + "param" +
                                 to_string(total_params) + ";\n");
                total_params++;
            } else {
                for (size_t j = 0; j < resultSize; ++j, ++total_params) {
                    param_names.push_back(function_c_name + "param" + to_string(total_params));
                    append_to_preamble(expression_type->typenames[j].get_corresponding_type_string() + " "
                                     + function_c_name + "param" + to_string(total_params) + ";\n");
                }
            }

            append_to_preamble(GetParserResults(ExpressionParser(ExpressionOp(ExpressionOp::ASSIGNMENT, param_names), m_context), exp));
        }

        if (total_params != expected_params) {
            //throw ParameterException(get_line_num(node));
        }
        res.expressions.back().pop_back();
    }
}

void BasicExpressionCombiner::visit_expression_pass(const ASTArgList *node, void *data) {
    string function_c_name = m_fn_call_name[node->jjtGetParent()];
    string function_rattle_name = get_token_of_node((node->jjtGetParent()->jjtGetChild(0)));
    int param_size = m_context->get_function(function_rattle_name)->inner_vars.size();

    if (param_size > 0) {
        for (size_t i = 0; i < param_size; ++i) {
            append_to_preamble(function_c_name + "param" + to_string(i));
            append_to_preamble(",");
        }
        res.preample.pop_back();
    }
}

TypeInfoPtr BasicExpressionCombiner::get_type_info(const SimpleNode *node) {
    ASTExpression* exp = new ASTExpression(0);
    exp->jjtAddChild(const_cast<SimpleNode*>(node),0);
    return TypeInferer::get_instance()->StartParsing(exp, m_context);}

bool BasicExpressionCombiner::needs_converting(TypeInfoPtr expression_info) {
    return (expected_output->num_return() == 1 && expected_output->typenames[0].type_name == STRING) &&
           (expression_info->num_return() == 1 && expression_info->typenames[0].type_name == NUMBER);
}

void BasicExpressionCombiner::convert_if_needed(SimpleNode *node) {
    TypeInfoPtr expression_info = get_type_info(node);
    TypeInfoPtr old = expected_output;
    bool convert = needs_converting(expression_info);
    expected_output = expression_info;

    if (convert) {
        append_to_result("to_string(");
        Accept(node, nullptr);
        append_to_result(")");
    } else {
        Accept(node, nullptr);
    }

    expected_output = old;
}

