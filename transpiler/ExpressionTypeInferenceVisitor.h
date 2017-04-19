//
// Created by Thomas Rogers on 07/04/2017.
//

#ifndef RATTLE_CPP_EXPRESSIONTYPEINFERENCEVISITOR_H
#define RATTLE_CPP_EXPRESSIONTYPEINFERENCEVISITOR_H

#include "../gen/RattleVisitor.h"
#include "../TypeInformation/type.h"
#include "../TypeInformation/TypeInformation.h"

namespace RattleLang {
    class ExpressionTypeInferenceVisitor : public RattleDefaultVisitor {
    public:
        void defaultVisit(const SimpleNode *node, void *data) override;

    public:
        ExpressionTypeInferenceVisitor(Context* context);

        RattleLang::TypeInformation StartParsing(const ASTExpression *node);

        //Binary Expressions.
        virtual  void visit(const ASTOr *node, void *data);

        virtual void visit(const ASTAnd *node, void *data);

        virtual void visit(const ASTCompEqual *node, void *data);

        virtual void visit(const ASTCompNequal *node, void *data);

        virtual void visit(const ASTCompGTE *node, void *data);

        virtual void visit(const ASTCompLTE *node, void *data);

        virtual void visit(const ASTCompGT *node, void *data);

        virtual void visit(const ASTCompLT *node, void *data);

        // Number type operands
        virtual void visit(const ASTAdd *node, void *data);

        virtual void visit(const ASTSubtract *node, void *data);


        virtual void visit(const ASTString* node, void* data);

        virtual void visit(const ASTTimes *node, void *data);

        virtual void visit(const ASTDivide *node, void *data);

        virtual void visit(const ASTUnaryNot *node, void *data);

        virtual void visit(const ASTUnaryPlus *node, void *data);

        virtual void visit(const ASTUnaryMinus *node, void *data);

        //Return types in their own right.
        virtual void visit(const ASTExpression *node, void *data);

        virtual void visit(const ASTFnInvoke *node, void *data);

        virtual void visit(const ASTMethodInvoke *node, void *data);

        virtual void visit(const ASTIdentifier *node, void *data);

        virtual void visit(const ASTDereference *node, void* data);

        virtual void visit(const ASTMemIdentifier *node, void *data);

        // These return types.
        virtual void visit(const ASTCharacter *node, void *data);

        virtual void visit(const ASTNumber *node, void *data);

        virtual void visit(const ASTTrue *node, void *data);

        virtual void visit(const ASTFalse *node, void *data);

        virtual void visit(const ASTIndexedExpression* node, void* data);


    private:
        RattleLang::type retType;
        Context* m_context;

        // On the initial pass we determine what type of operands are possible.
        // so if we do a + b - c / 4 * 48
        // Then we have done + - / *
        // Which means our initial_pass member should have been set as follows.
        // 000000001111
        // now if we encounter a bool we can do (000000001111 & 001111000000) which would be 0 so we'd fire an error as


        RattleLang::type getTypeFromNode(const SimpleNode* node);

        RattleLang::type getTypeFromOperation(const SimpleNode* node, RattleLang::operands operand);

        // So what if we just get (expression).

    };



}





#endif //RATTLE_CPP_EXPRESSIONTYPEINFERENCEVISITOR_H
