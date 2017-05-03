#ifndef RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H
#define RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H


#include "ExpressionCombiner.h"
#include "../StateMachineParser.h"

using namespace std;
namespace RattleLang {


    class DefaultExpressionCombiner : public ExpressionCombiner, public StateMachineParser<DefaultExpressionCombiner> {
    public:

        enum ExpressionState {
            FN_PASS,
            EXPRESSION_PASS,
        };


        DefaultExpressionCombiner(Context *m_context) : ExpressionCombiner(m_context) {}

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

    private:
        Context* m_context;

        ExpressionState state = FN_PASS;

        // Defaults.
        void visit_fn_pass(const SimpleNode* node, void* data){
            ChildrenAccept(node, data);
        }

        void visit_expression_pass(const SimpleNode* node, void* data){
            ChildrenAccept(node, data);
        }

    };
}


#endif //RATTLE_CPP_DEFAULTEXPRESSIONCOMBINER_H
