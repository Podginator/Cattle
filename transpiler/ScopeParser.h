#ifndef RATTLE_CPP_BLOCKPARSER_H
#define RATTLE_CPP_BLOCKPARSER_H


#include <iostream>
#include "../TypeInformation/Context.h"
#include "StateMachineParser.h"
#include "ExpressionParser.h"

namespace RattleLang {
    // Parses based on scope.
    class ScopeParser : public StateMachineParser<ScopeParser> {
    public:

        enum BlockState {
            DECLARATION= 0,
            IMPLEMENTATION =1,
            LAST = IMPLEMENTATION
        };

        // We want to expose the context for our Block Parser.
        ScopeParser(Context* context, bool excluseScope = false);

        void StartParsing(const SimpleNode* n);

        template <class T>
        void defVisit(const T* node, void* data) {

            switch (state) {
                case DECLARATION:
                    declare(node, data);
                    break;
                case IMPLEMENTATION:
                    implement(node, data);
                    break;
                default:
                    break;
            }
        }

        std::string get_c_output() { return cOut; }

        void  defaultVisit(const SimpleNode *node, void * data) override {}

        // Allow us to set the state manually.
        void setState(BlockState state) { this->state = state;}

    private:

        bool m_exclusive_scope;

        BlockState state;

        std::string cOut;

        Context* m_context;

        std::map<ASTExpression*, size_t> m_expression_count;

        void declare(const SimpleNode* node, void* data) { /* do nothing*/ }

        void implement(const SimpleNode* node, void* data) { /*do nothing*/ }

        void declare(const ASTStatement* node, void* data) { ChildrenAccept(node, data); }

        void implement(const ASTStatement* node, void* data) { ChildrenAccept(node, data); }

        void declare(const ASTBlock* node, void* data) { ChildrenAccept(node, data); }

        void implement(const ASTBlock* node, void* data) { ChildrenAccept(node, data); }

        void declare (const ASTAssignment* node, void *data);

        void declare(const ASTExpression *node, void* data);


        void implement(const ASTAssignment* node, void* data);

        void implement(const ASTExpression* node, void* data);


        void implement(const ASTWhileLoop* node, void* data);

        void implement(const ASTForLoop* node, void* data);

        void implement(const ASTIfStatement* node, void* data);

        void implement(const ASTWrite* node, void* data);

        void implement(const ASTFnInvoke* node, void* data);
    };
}


#endif //RATTLE_CPP_BLOCKPARSER_H
