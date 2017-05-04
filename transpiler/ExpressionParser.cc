#include <iostream>
#include "ExpressionParser.h"
#include "ExpressionCombiner/ExpressionCombinerFactory.h"

using namespace RattleLang;
using namespace std;

void ExpressionParser::StartParsing(const SimpleNode* n) {
    has_fn_calls = find_instance_of<ASTFnInvoke>(n);
    res.append(has_fn_calls ? SCOPE_OPEN : "");
    ExpressionCombinerResult result = ExpressionCombinerFactory::do_expression(n, m_context);

    res += result.preample;
    for (int i = 0; i < result.expressions.size(); i++) {
        if (assignments.size() > i) {
            res.append(assignments[i] + " = ");
            res.append(result.expressions[i] + ";\n");
        }
        if (assignments.size() == 0) {
            res.append(result.expressions[i] + ";\n");
        }
    }

    res.append(has_fn_calls ? SCOPE_CLOSE : "");
}