#ifndef RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H
#define RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H


#include "ExpressionCombiner.h"
#include "../StateMachineParser.h"
#include "../../exceptions/ParsingException.h"

using namespace std;
namespace RattleLang {


    class DefaultExpressionCombiner : public ExpressionCombiner, public StateMachineParser<DefaultExpressionCombiner> {
    public:

        enum ExpressionState {
            FN_PASS,
            EXPRESSION_PASS,
        };


        DefaultExpressionCombiner(Context *m_context) {
            //res = {0};
            this->m_context = m_context;
        }

        template <class T>
        void defVisit(const T* node, void* data) {

            switch (state) {
                case FN_PASS:
                    visit_fn_pass(node, data);
                    break;
                case EXPRESSION_PASS:
                    visit_expression_pass(node, data);
                    break;
                default:
                    break;
            }
        }

    protected:
        Context* m_context;

        ExpressionState state = FN_PASS;

        ExpressionCombinerResult res;

        // Defaults.
        virtual void visit_fn_pass(const SimpleNode* node,  void* data){
            ChildrenAccept(node, data);
        }

        virtual void visit_expression_pass(const SimpleNode* node,  void* data){
            ChildrenAccept(node, data);
        }

        virtual void  visit_expression_pass(const ASTOr *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTAnd *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTCompEqual *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTCompNequal *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTCompGTE *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTCompLTE *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTCompGT *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTCompLT *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTAdd *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTSubtract *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTTimes *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTDivide *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTUnaryNot *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTUnaryPlus *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTUnaryMinus *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void visit_expression_pass(const ASTDereference* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTExpression* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }
        virtual void  visit_fn_pass(const ASTExpression* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        // A function invoke should
        virtual void  visit_expression_pass(const ASTFnInvoke *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }
        virtual void  visit_fn_pass(const ASTFnInvoke *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void visit_fn_pass(const ASTArgList* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTArgList *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTCharacter *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTString *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTNumber *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTTrue *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void  visit_expression_pass(const ASTFalse *node,  void * data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void visit_expression_pass(const ASTIdentifier* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void visit_fn_pass(const ASTIndexedExpression* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void visit_expression_pass(const ASTIndexedExpression* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void visit_fn_pass(const ASTTupleDefine* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void visit_expression_pass(const ASTTupleDefine* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }

        virtual void visit_expression_pass(const ASTLambdaDefine* node,  void* data) {
            //throw ParsingException("Invalid Command", get_line_num(node));
        }


        void append_to_preamble(const string &str) {
            res.preample.append(str);
        }

        void append_to_result(const string &str) {
            res.expressions.back().append(str);
        }

        ~DefaultExpressionCombiner(){
            // Do nothing?
        }

    };
}


#endif //RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H
