#ifndef SIMPLEEXPR_H
#define SIMPLEEXPR_H

#include "../gen/RattleTree.h"
#include "../TypeInformation/TypeStorage.h"
#include "../TypeInformation/TypeInformation.h"
#include "../gen/RattleVisitor.h"
#include "StateMachineParser.h"
#include "../TypeInformation/ExpressionOp.h"
#include <string>

using namespace std;

namespace RattleLang{ 

    // There is a lot of side effects in this code.
    class ExpressionParser : public StateMachineParser<ExpressionParser> {
    public:

        enum ExpressionState {
            FN_PASS,
            EXPRESSION_PASS,
        };

        ExpressionParser(ExpressionOp op, Context* context)
                : parent(op), state(FN_PASS), m_context(context)
        {
            returnedExpressions.push_back("");
        }

        void StartParsing(const SimpleNode* n);


        string get_c_output() { return res; }

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

        // A Simple Expression is Literal or Expression + - / < > >= <= || &&
        virtual void defaultVisit(const SimpleNode *node, void * data);


        // Defaults.
        void visit_fn_pass(const SimpleNode* node, void* data){
            ChildrenAccept(node, data);
        }

        void visit_expression_pass(const SimpleNode* node, void* data){
            ChildrenAccept(node, data);
        }

        // Should only exist for
        void  visit_expression_pass(const ASTOr *node, void * data);

        void  visit_expression_pass(const ASTAnd *node, void * data);

        void  visit_expression_pass(const ASTCompEqual *node, void * data);

        void  visit_expression_pass(const ASTCompNequal *node, void * data);

        void  visit_expression_pass(const ASTCompGTE *node, void * data);

        void  visit_expression_pass(const ASTCompLTE *node, void * data);

        void  visit_expression_pass(const ASTCompGT *node, void * data);

        void  visit_expression_pass(const ASTCompLT *node, void * data);

        void  visit_expression_pass(const ASTAdd *node, void * data);

        void  visit_expression_pass(const ASTSubtract *node, void * data);

        void  visit_expression_pass(const ASTTimes *node, void * data);

        void  visit_expression_pass(const ASTDivide *node, void * data);

        void  visit_expression_pass(const ASTUnaryNot *node, void * data);

        void  visit_expression_pass(const ASTUnaryPlus *node, void * data);

        void  visit_expression_pass(const ASTUnaryMinus *node, void * data);

        void visit_expression_pass(const ASTDereference* node, void* data);

        void  visit_expression_pass(const ASTExpression* node, void* data);
        void  visit_fn_pass(const ASTExpression* node, void* data);

        // A function invoke should
        void  visit_expression_pass(const ASTFnInvoke *node, void * data);
        void  visit_fn_pass(const ASTFnInvoke *node, void * data);

        void visit_fn_pass(const ASTArgList* node, void* data);
        void  visit_expression_pass(const ASTArgList *node, void * data);

        void  visit_expression_pass(const ASTCharacter *node, void * data);

        void  visit_expression_pass(const ASTString *node, void * data);

        void  visit_expression_pass(const ASTNumber *node, void * data);

        void  visit_expression_pass(const ASTTrue *node, void * data);

        void  visit_expression_pass(const ASTFalse *node, void * data);

        void visit_expression_pass(const ASTIdentifier* node, void* data);

        void visit_fn_pass(const ASTIndexedExpression* node, void* data);

        void visit_expression_pass(const ASTIndexedExpression* node, void* data);

        void visit_fn_pass(const ASTTupleDefine* node, void* data);

        void visit_expression_pass(const ASTTupleDefine* node, void* data);

        void visit_expression_pass(const ASTLambdaDefine* node, void* data);

    private:
        string res;

        ExpressionState state = FN_PASS;

        std::vector<string> returnedExpressions;

        map<const Node*, string> m_fnCallName;

        ExpressionOp parent;

        Context* m_context;

        TypeInfoPtr expectedOutput;

        bool isMultiAssign = false;

        bool hasFnCalls = false;

        void print_node(const SimpleNode *node);

        void do_expression(const SimpleNode *n, const string &expression);

        void do_expression(const SimpleNode *n);

        bool isMultiAssignment(const SimpleNode* exp);

        void AppendToResult(const std::string& string);

        // Do each Child and add a new returned value.
        void DoEachExpression(const SimpleNode* node);

        TypeInfoPtr get_type_info(const SimpleNode *node);

        bool needs_converting(SimpleNode *node);

        bool needs_converting(TypeInfoPtr expression_info);

        void convert_if_needed(SimpleNode *node);
    };
}

#endif