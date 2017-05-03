#ifndef RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H
#define RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H


#include "ExpressionCombiner.h"

namespace RattleLang {

    // The Default Expression Combiner will just perform a "node 1 + node 2".
    class DefaultExpressionCombiner : public ExpressionCombiner {
        string combine_statement(SimpleNode *node, SimpleNode *node2, operands operand) override;
    };
}


#endif //RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H
