#ifndef RATTLE_CPP_BASICEXPRESSIONCOMBINER_H
#define RATTLE_CPP_BASICEXPRESSIONCOMBINER_H


#include "DefaultExpressionGenerator.h"

namespace RattleLang {
    // The expression combiner for simple statements like a = 2 + 4
    class BasicExpressionGenerator : public DefaultExpressionGenerator {
    public:
        BasicExpressionGenerator(Context *m_context);

        ExpressionGeneratorResult combine_statement(const SimpleNode *node, operands operand, bool is_multi_assign) override;

        void defaultVisit(const SimpleNode *node, void *data) override {}


    protected:
        void  visit_expression_pass(const ASTOr *node, void * data) override;

        void  visit_expression_pass(const ASTAnd *node, void * data) override;

        void  visit_expression_pass(const ASTCompEqual *node, void * data) override;

        void  visit_expression_pass(const ASTCompNequal *node, void * data) override;

        void  visit_expression_pass(const ASTCompGTE *node, void * data) override;

        void  visit_expression_pass(const ASTCompLTE *node, void * data) override;

        void  visit_expression_pass(const ASTCompGT *node, void * data) override;

        void  visit_expression_pass(const ASTCompLT *node, void * data) override;

        void  visit_expression_pass(const ASTAdd *node, void * data) override;

        void  visit_expression_pass(const ASTSubtract *node, void * data) override;

        void  visit_expression_pass(const ASTTimes *node, void * data) override;

        void  visit_expression_pass(const ASTDivide *node, void * data) override;

        void  visit_expression_pass(const ASTUnaryNot *node, void * data) override;

        void  visit_expression_pass(const ASTUnaryPlus *node, void * data) override;

        void  visit_expression_pass(const ASTUnaryMinus *node, void * data) override;

        void visit_expression_pass(const ASTDereference* node, void* data) override;

        void  visit_expression_pass(const ASTExpression* node, void* data) override;
        void  visit_fn_pass(const ASTExpression* node, void* data) override;

        // A function invoke should
        void  visit_expression_pass(const ASTFnInvoke *node, void * data) override;
        void  visit_fn_pass(const ASTFnInvoke *node, void * data) override;

        void visit_fn_pass(const ASTArgList* node, void* data) override;
        void  visit_expression_pass(const ASTArgList *node, void * data) override;

        void  visit_expression_pass(const ASTCharacter *node, void * data) override;

        void  visit_expression_pass(const ASTString *node, void * data) override;

        void  visit_expression_pass(const ASTNumber *node, void * data) override;

        void  visit_expression_pass(const ASTTrue *node, void * data) override;

        void  visit_expression_pass(const ASTFalse *node, void * data) override;

        void visit_expression_pass(const ASTIdentifier* node, void* data) override;

        void visit_fn_pass(const ASTIndexedExpression* node, void* data) override;

        void visit_expression_pass(const ASTIndexedExpression* node, void* data) override;

        void visit_fn_pass(const ASTTupleDefine* node, void* data) override;

        void visit_expression_pass(const ASTTupleDefine* node, void* data) override;

        void visit_expression_pass(const ASTLambdaDefine* node, void* data) override;
    private:
        map<const Node*, string> m_fn_call_name;

        TypeInfoPtr expected_output;

        bool multi_assign = false;

        void print_node(const SimpleNode* node);

        void do_expression(const SimpleNode *n, const string &expression);

        void do_each_expression(const SimpleNode *node);

        TypeInfoPtr get_type_info(const SimpleNode *node);

        bool needs_converting(TypeInfoPtr expression_info);

        void convert_if_needed(SimpleNode *node);

    };
}


#endif //RATTLE_CPP_BASICEXPRESSIONCOMBINER_H
