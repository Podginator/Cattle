#include <iostream>
#include "ExpressionParser.h"
#include "ExpressionCombiner/ExpressionCombinerFactory.h"

using namespace RattleLang;
using namespace std;

void ExpressionParser::StartParsing(const SimpleNode* n) {
    this->has_fn_calls = find_instance_of<ASTFnInvoke>(n);
    res.append(has_fn_calls ? SCOPE_OPEN : "");
    ExpressionCombinerResult result = ExpressionCombinerFactory::do_expression(n, m_context);

    res += result.preample;
    for (int i = 1; i < result.expressions.size(); i++) {
        if (parent.parents.size() > i - 1) {
            res.append(parent.parents[i - 1] + " = ");
        }
        res.append(result.expressions[i] + ";\n");
    }

    res.append(has_fn_calls ? SCOPE_CLOSE : "");
}