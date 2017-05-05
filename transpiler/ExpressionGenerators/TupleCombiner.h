//
// Created by Thomas Rogers on 04/05/2017.
//

#ifndef RATTLE_CPP_TUPLECOMBINER_H
#define RATTLE_CPP_TUPLECOMBINER_H


#include "DefaultExpressionGenerator.h"

namespace RattleLang {
    class TupleCombiner : public ExpressionGenerator, public RattleDefaultVisitor{

    public:
        friend class ExpressionGeneratorFactory;

        ExpressionGeneratorResult
        combine_statement(const SimpleNode *node, operands operand, bool is_multi_assign) override;

        TupleCombiner(Context *context);

        void defaultVisit(const SimpleNode *node, void *data) override;


        void visit(const ASTAdd *node, void *data) override;

        void visit(const ASTIndexedExpression *node, void *data) override;


    private:
        void do_children(const SimpleNode* node, void *data);


    };
}

#endif //RATTLE_CPP_TUPLECOMBINER_H
