//
// Created by Thomas Rogers on 03/04/2017.
//

#ifndef RATTLE_CPP_STATEEXPRESSIONPARSER_H
#define RATTLE_CPP_STATEEXPRESSIONPARSER_H

#include "../gen/RattleTree.h"
#include "../gen/RattleVisitor.h"


namespace RattleLang {

    template <class T>
    class StateMachineParserDecorator : public RattleDefaultVisitor {
    public:

        T* parser;

        StateMachineParserDecorator(T* t) : parser(t) {
            parser->SetStateParser(this);
        }

        static std::string GetParserResults(T t, const SimpleNode* node) {
            StateMachineParserDecorator<T> parser(&t);
            parser.StartParsing(node);
            return t.get_c_output();
        }

        static std::string GetParserSingleNodeResult(T t, const SimpleNode *node) {
            StateMachineParserDecorator<T> parser(&t);
            t.Accept(node);
            return t.get_c_output();
        }

        void StartParsing(const SimpleNode* node) {
            parser->StartParsing(node);
        }

        virtual void defaultVisit(const SimpleNode *node, void *data) {

        }


        template <class N>
        void defVisit(const N *node, void *data){
            parser-> template defVisit<N>(node, data);
        }

        virtual void visit(const SimpleNode *node, void *data) {
            defVisit<SimpleNode>(node, data);
        }

        virtual void visit(const ASTCode *node, void *data) {
            defVisit<ASTCode>(node, data);
        }

        virtual void visit(const ASTStatement *node, void *data) {
            defVisit<ASTStatement>(node, data);
        }

        virtual void visit(const ASTBlock *node, void *data) {
            defVisit<ASTBlock>(node, data);
        }

        virtual void visit(const ASTParmlist *node, void *data) {
            defVisit<ASTParmlist>(node, data);
        }


        virtual void visit(const ASTClassDef *node, void *data) {
            defVisit<ASTClassDef>(node, data);
        }


        virtual void visit(const ASTFnBody *node, void *data) {
            defVisit<ASTFnBody>(node, data);
        }

        virtual void visit(const ASTFnDef *node, void *data) {
            defVisit<ASTFnDef>(node, data);
        }

        virtual void visit(const ASTReturnExpression *node, void *data) {
            defVisit<ASTReturnExpression>(node, data);
        }

        virtual void visit(const ASTMemDeclaration *node, void *data) {
            defVisit<ASTMemDeclaration>(node, data);
        }

        virtual void visit(const ASTAssignment *node, void *data) {
            defVisit<ASTAssignment>(node, data);
        }

        virtual void visit(const ASTIfStatement *node, void *data) {
            defVisit<ASTIfStatement>(node, data);
        }

        virtual void visit(const ASTIndexedExpression* node, void* data) {
            defVisit<ASTIndexedExpression>(node, data);
        }

        virtual void visit(const ASTObjCreate *node, void *data) {
            defVisit<ASTObjCreate>(node, data);
        }

        virtual void visit(const ASTMemInstantiate *node, void *data) {
            defVisit<ASTMemInstantiate>(node, data);
        }

        virtual void visit(const ASTMethodInstantiate *node, void *data) {
            defVisit<ASTMethodInstantiate>(node, data);
        }

        virtual void visit(const ASTLabmdaDefine *node, void *data) {
            defVisit<ASTLabmdaDefine>(node, data);
        }

        virtual void visit(const ASTForLoop *node, void *data) {
            defVisit<ASTForLoop>(node, data);
        }

        virtual void visit(const ASTWhileLoop *node, void *data) {
            defVisit<ASTWhileLoop>(node, data);
        }

        virtual void visit(const ASTWrite *node, void *data) {
            defVisit<ASTWrite>(node, data);
        }

        virtual void visit(const ASTArgList *node, void *data) {
            defVisit<ASTArgList>(node, data);
        }

        virtual void visit(const ASTOr *node, void *data) {
            defVisit<ASTOr>(node, data);
        }

        virtual void visit(const ASTAnd *node, void *data) {
            defVisit<ASTAnd>(node, data);
        }

        virtual void visit(const ASTCompEqual *node, void *data) {
            defVisit<ASTCompEqual>(node, data);
        }

        virtual void visit(const ASTCompNequal *node, void *data) {
            defVisit<ASTCompNequal>(node, data);
        }

        virtual void visit(const ASTCompGTE *node, void *data) {
            defVisit<ASTCompGTE>(node, data);
        }

        virtual void visit(const ASTCompLTE *node, void *data) {
            defVisit<ASTCompLTE>(node, data);
        }

        virtual void visit(const ASTCompGT *node, void *data) {
            defVisit<ASTCompGT>(node, data);
        }

        virtual void visit(const ASTCompLT *node, void *data) {
            defVisit<ASTCompLT>(node, data);
        }

        virtual void visit(const ASTAdd *node, void *data) {
            defVisit<ASTAdd>(node, data);
        }

        virtual void visit(const ASTSubtract *node, void *data) {
            defVisit<ASTSubtract>(node, data);
        }

        virtual void visit(const ASTTimes *node, void *data) {
            defVisit<ASTTimes>(node, data);
        }

        virtual void visit(const ASTDivide *node, void *data) {
            defVisit<ASTDivide>(node, data);
        }

        virtual void visit(const ASTUnaryNot *node, void *data) {
            defVisit<ASTUnaryNot>(node, data);
        }

        virtual void visit(const ASTUnaryPlus *node, void *data) {
            defVisit<ASTUnaryPlus>(node, data);
        }

        virtual void visit(const ASTUnaryMinus *node, void *data) {
            defVisit<ASTUnaryMinus>(node, data);
        }

        virtual void visit(const ASTFnInvoke *node, void *data) {
            defVisit<ASTFnInvoke>(node, data);
        }

        virtual void visit(const ASTString *node, void *data) {
            defVisit<ASTString>(node, data);
        }

        virtual void visit(const ASTMethodInvoke *node, void *data) {
            defVisit<ASTMethodInvoke>(node, data);
        }

        virtual void visit(const ASTIdentifier *node, void *data) {
            defVisit<ASTIdentifier>(node, data);
        }

        virtual void visit(const ASTMemIdentifier *node, void *data) {
            defVisit<ASTMemIdentifier>(node, data);
        }

        virtual void visit(const ASTDereference *node, void *data) {
            defVisit<ASTDereference>(node, data);
        }

        virtual void visit(const ASTCharacter *node, void *data) {
            defVisit<ASTCharacter>(node, data);
        }

        virtual void visit(const ASTNumber *node, void *data) {
            defVisit<ASTNumber>(node, data);
        }

        virtual void visit(const ASTTrue *node, void *data) {
            defVisit<ASTTrue>(node, data);
        }

        virtual void visit(const ASTFalse *node, void *data) {
            defVisit<ASTFalse>(node, data);
        }

        virtual void visit(const ASTEOF *node, void *data){
            defVisit<ASTEOF>(node, data);
        }

        virtual void visit(const ASTExpression *node, void *data) {
            defVisit<ASTExpression>(node, data);
        }
    };

}





#endif //RATTLE_CPP_STATEEXPRESSIONPARSER_H
