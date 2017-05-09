#include "TupleCombiner.h"
#include "ExpressionGeneratorFactory.h"


using namespace RattleLang;
using namespace std;
TupleCombiner::TupleCombiner(Context *context) {
    m_context = context;
}

// We combine the nodes to create a new tuple.
ExpressionGeneratorResult TupleCombiner::combine_statement(const SimpleNode *node, operands operand,  bool is_multi_assign) {
    res.expressions.push_back("");
    if (operand != ADD_OP) {
        throw ParsingException("Cannot perform operation on this series of tuples", get_line_num(node));
    }

    append_to_result("make_tuple(");
    do_children(node, nullptr);
    append_to_result(")");

    return res;
}

void TupleCombiner::defaultVisit(const SimpleNode *node, void *data) {
    get_expression(node, true);
}

// The Add Expression is a little different.
void TupleCombiner::visit(const ASTAdd *node, void *data) {
    // This is a fun one.
    TypeInfoPtr type = TypeInferer::get_instance()->StartParsing(ExpressionGeneratorFactory::get_expression(node), m_context);

    // this must be a a+b tuple situation,
    // we want to get the individual elements from the sub nodes in this instance.
    if (type->source == TUPLE) {
        node->jjtGetChild(0)->jjtAccept(this, data);
        node->jjtGetChild(1)->jjtAccept(this, data);
        return;
    }

    defaultVisit(node, data);
}


// We don't want to take all the results from the Indexed Expression, we just want one - So we override the
// default visit. - Basically the same behaviour but without the need for multiple.
void TupleCombiner::visit(const ASTIndexedExpression *node, void *data) {
    get_expression(node, false);
}

void TupleCombiner::do_children(const SimpleNode *node, void *data) {
    node->childrenAccept(this, nullptr);
    res.expressions.back().pop_back();
}


void TupleCombiner::get_expression(const SimpleNode *node, bool need_multiple) {
    ExpressionGeneratorResult expression_result = ExpressionGeneratorFactory::do_expression(
            ExpressionGeneratorFactory::get_expression(node), m_context, need_multiple);
    append_to_preamble(expression_result.preample);
    append_to_result(StringHelper::combine_str(expression_result.expressions, ',', false));
}
