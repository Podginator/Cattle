//
// Created by Thomas Rogers on 04/05/2017.
//

#ifndef RATTLE_CPP_TUPLECOMBINER_H
#define RATTLE_CPP_TUPLECOMBINER_H


#include "DefaultStateExpressionGenerator.h"

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

        void get_expression(const SimpleNode* node, bool need_multiple);

    };
}

#endif //RATTLE_CPP_TUPLECOMBINER_H
