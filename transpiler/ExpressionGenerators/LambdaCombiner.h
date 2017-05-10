#ifndef RATTLE_CPP_LAMBDACOMBINER_H
#define RATTLE_CPP_LAMBDACOMBINER_H

#include "../../gen/RattleVisitor.h"
#include "ExpressionGenerator.h"
using namespace std;
namespace RattleLang {

    // For this one I literally just want to allow the PARSER to generate a Tree from the parameters passed.
    // so this class will take the derefences ( a + b + c ) and use those
    // it currently does not work for in place lambda definitions, this is perhaps a todo, but since we are running
    // out of time on this it might be better to ignore it for now.
    class LambdaCombiner : public ExpressionGenerator, public RattleDefaultVisitor {
    public:
        ExpressionGeneratorResult
        combine_statement(const SimpleNode *node, operands operand, bool is_multi_assign) override;

        LambdaCombiner(Context *context);

        void defaultVisit(const SimpleNode *node, void *data) override;

        void visit(const ASTAdd *node, void *data) override;

        void visit(const ASTDereference *node, void *data) override;

        void visit(const ASTIdentifier *node, void *data) override;


    private:

        string parameters;

        string ret_statement;

        bool seen_first = false;

        TypeInfoPtr last_ret_type;

        ASTExpression* get_expression(const SimpleNode* node);

    };
}


#endif //RATTLE_CPP_LAMBDACOMBINER_H
