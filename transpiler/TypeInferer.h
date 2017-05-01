#ifndef RATTLE_CPP_EXPRESSIONTYPEINFERENCEVISITOR_H
#define RATTLE_CPP_EXPRESSIONTYPEINFERENCEVISITOR_H

#include "../gen/RattleVisitor.h"
#include "../TypeInformation/type.h"
#include "../TypeInformation/TypeInformation.h"
#include "../gen/ASTTupleDefine.h"

namespace RattleLang {
    class TypeInferer : public RattleDefaultVisitor {

    public:

        static TypeInferer* get_instance();

        TypeInfoPtr StartParsing(const ASTExpression *node, Context* context);

        void defaultVisit(const SimpleNode *node, void *data) override;

        //Binary Expressions.
        void visit(const ASTOr *node, void *data) override;

        void visit(const ASTAnd *node, void *data) override;

        void visit(const ASTCompEqual *node, void *data) override;

        void visit(const ASTCompNequal *node, void *data) override;

        void visit(const ASTCompGTE *node, void *data) override;

        void visit(const ASTCompLTE *node, void *data) override;

        void visit(const ASTCompGT *node, void *data) override;

        void visit(const ASTCompLT *node, void *data) override;

        // Number type operands
        void visit(const ASTAdd *node, void *data) override;

        void visit(const ASTSubtract *node, void *data) override;


        void visit(const ASTString* node, void* data) override;

        void visit(const ASTTimes *node, void *data) override;

        void visit(const ASTDivide *node, void *data) override;

        void visit(const ASTUnaryNot *node, void *data) override;

        void visit(const ASTUnaryPlus *node, void *data) override;

        void visit(const ASTUnaryMinus *node, void *data) override;

        //Return types in their own right.
        void visit(const ASTExpression *node, void *data) override;

        void visit(const ASTFnInvoke *node, void *data) override;

        void visit(const ASTMethodInvoke *node, void *data) override;

        void visit(const ASTIdentifier *node, void *data) override;

        void visit(const ASTDereference *node, void* data) override;

        void visit(const ASTMemIdentifier *node, void *data) override;

        // These return types.
        void visit(const ASTCharacter *node, void *data) override;

        void visit(const ASTNumber *node, void *data) override;

        void visit(const ASTTrue *node, void *data) override;

        void visit(const ASTFalse *node, void *data) override;

        void visit(const ASTIndexedExpression* node, void* data) override;

        void visit(const ASTTupleDefine* node, void* visit) override;

        void visit(const ASTLabmdaDefine *node, void *data) override;

    private:

        TypeInferer();

        static TypeInferer* instance;

        std::map<const ASTExpression*, TypeInfoPtr> m_typemap;

        RattleLang::type retType;

        Context* m_context;

        // On the initial pass we determine what type of operands are possible.
        // so if we do a + b - c / 4 * 48
        // Then we have done + - / *
        // Which means our initial_pass member should have been set as follows.
        // 000000001111
        // now if we encounter a bool we can do (000000001111 & 001111000000) which would be 0 so we'd fire an error as

        std::shared_ptr<RattleLang::TypeInformation> getTypeFromNode(const SimpleNode* node);

        RattleLang::type getTypeFromOperation(const SimpleNode* node, RattleLang::operands operand);

        void doOperand(const SimpleNode *node, RattleLang::operands operand, void* info);

    };

}


#endif //RATTLE_CPP_EXPRESSIONTYPEINFERENCEVISITOR_H
