#ifndef SIMPLEEXPR_H
#define SIMPLEEXPR_H

#include "../gen/RattleTree.h"
#include "../TypeInformation/TypeStorage.h"
#include "../TypeInformation/TypeInformation.h"
#include "../gen/RattleVisitor.h"
#include "StateMachineParser.h"
#include "../TypeInformation/ExpressionOp.h"
#include <string>

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


        std::string get_c_output() { return res; }

        template <class T>
        void defVisit(const T* node, void* data) {

            switch (state) {
                case FN_PASS:
                    visit_fnPass(node, data);
                    break;
                case EXPRESSION_PASS:
                    visit_expressionPass(node, data);
                    break;
                default:
                    break;
            }
        }

        // A Simple Expression is Literal or Expression + - / < > >= <= || &&
        virtual void defaultVisit(const SimpleNode *node, void * data);


        // Defaults.
        void visit_fnPass(const SimpleNode* node, void* data){
            ChildrenAccept(node, data);
        }

        void visit_expressionPass(const SimpleNode* node, void* data){
            ChildrenAccept(node, data);
        }

        // Should only exist for
        void  visit_expressionPass(const ASTOr *node, void * data);

        void  visit_expressionPass(const ASTAnd *node, void * data);

        void  visit_expressionPass(const ASTCompEqual *node, void * data);

        void  visit_expressionPass(const ASTCompNequal *node, void * data);

        void  visit_expressionPass(const ASTCompGTE *node, void * data);

        void  visit_expressionPass(const ASTCompLTE *node, void * data);

        void  visit_expressionPass(const ASTCompGT *node, void * data);

        void  visit_expressionPass(const ASTCompLT *node, void * data);

        void  visit_expressionPass(const ASTAdd *node, void * data);

        void  visit_expressionPass(const ASTSubtract *node, void * data);

        void  visit_expressionPass(const ASTTimes *node, void * data);

        void  visit_expressionPass(const ASTDivide *node, void * data);

        void  visit_expressionPass(const ASTUnaryNot *node, void * data);

        void  visit_expressionPass(const ASTUnaryPlus *node, void * data);

        void  visit_expressionPass(const ASTUnaryMinus *node, void * data);

        void visit_expressionPass(const ASTDereference* node, void* data);

        void  visit_expressionPass(const ASTExpression* node, void* data);
        void  visit_fnPass(const ASTExpression* node, void* data);

        // A function invoke should
        void  visit_expressionPass(const ASTFnInvoke *node, void * data);
        void  visit_fnPass(const ASTFnInvoke *node, void * data);

        void visit_fnPass(const ASTArgList* node, void* data);
        void  visit_expressionPass(const ASTArgList *node, void * data);

        void  visit_expressionPass(const ASTCharacter *node, void * data);

        void  visit_expressionPass(const ASTString *node, void * data);

        void  visit_expressionPass(const ASTNumber *node, void * data);

        void  visit_expressionPass(const ASTTrue *node, void * data);

        void  visit_expressionPass(const ASTFalse *node, void * data);

        void visit_expressionPass(const ASTIdentifier* node, void* data);

        void visit_fnPass(const ASTIndexedExpression* node, void* data);

        void visit_expressionPass(const ASTIndexedExpression* node, void* data);

        void visit_fnPass(const ASTTupleDefine* node, void* data);

        void visit_expressionPass(const ASTTupleDefine* node, void* data);

        void visit_expressionPass(const ASTLambdaDefine* node, void* data);

    private:
        std::string res;
        ExpressionState state = FN_PASS;
        std::vector<std::string> returnedExpressions;
        std::map<const Node*, std::string> m_fnCallName;
        ExpressionOp parent;
        Context* m_context;
        TypeInfoPtr expectedOutput;
        bool isMultiAssign = false;
        bool hasFnCalls = false;

        void PrintNode(const SimpleNode* node);

        void doExpression(const SimpleNode* n, const std::string& expression);

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