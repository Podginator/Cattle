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

         void defaultVisit(const SimpleNode *node, void *data) override  {

        }


        template <class N>
        void defVisit(const N *node, void *data){
            parser-> template defVisit<N>(node, data);
        }

         void visit(const SimpleNode *node, void *data) override  {
            defVisit<SimpleNode>(node, data);
        }

         void visit(const ASTCode *node, void *data) override  {
            defVisit<ASTCode>(node, data);
        }

         void visit(const ASTStatement *node, void *data) override  {
            defVisit<ASTStatement>(node, data);
        }

         void visit(const ASTBlock *node, void *data) override  {
            defVisit<ASTBlock>(node, data);
        }

         void visit(const ASTParmlist *node, void *data) override  {
            defVisit<ASTParmlist>(node, data);
        }

         void visit(const ASTTupleDefine *node, void *data) override  {
            defVisit<ASTTupleDefine>(node, data);
        }


         void visit(const ASTClassDef *node, void *data) override  {
            defVisit<ASTClassDef>(node, data);
        }


         void visit(const ASTFnBody *node, void *data) override  {
            defVisit<ASTFnBody>(node, data);
        }

         void visit(const ASTFnDef *node, void *data) override  {
            defVisit<ASTFnDef>(node, data);
        }

         void visit(const ASTReturnExpression *node, void *data) override  {
            defVisit<ASTReturnExpression>(node, data);
        }

         void visit(const ASTMemDeclaration *node, void *data) override  {
            defVisit<ASTMemDeclaration>(node, data);
        }

         void visit(const ASTAssignment *node, void *data) override  {
            defVisit<ASTAssignment>(node, data);
        }

         void visit(const ASTIfStatement *node, void *data) override  {
            defVisit<ASTIfStatement>(node, data);
        }

         void visit(const ASTIndexedExpression* node, void* data) override  {
            defVisit<ASTIndexedExpression>(node, data);
        }

         void visit(const ASTObjCreate *node, void *data) override  {
            defVisit<ASTObjCreate>(node, data);
        }

         void visit(const ASTMemInstantiate *node, void *data) override  {
            defVisit<ASTMemInstantiate>(node, data);
        }

         void visit(const ASTMethodInstantiate *node, void *data) override  {
            defVisit<ASTMethodInstantiate>(node, data);
        }

         void visit(const ASTLambdaDefine *node, void *data) override  {
            defVisit<ASTLambdaDefine>(node, data);
        }

         void visit(const ASTForLoop *node, void *data) override  {
            defVisit<ASTForLoop>(node, data);
        }

         void visit(const ASTWhileLoop *node, void *data) override  {
            defVisit<ASTWhileLoop>(node, data);
        }

         void visit(const ASTWrite *node, void *data) override  {
            defVisit<ASTWrite>(node, data);
        }

         void visit(const ASTArgList *node, void *data) override  {
            defVisit<ASTArgList>(node, data);
        }

         void visit(const ASTOr *node, void *data) override  {
            defVisit<ASTOr>(node, data);
        }

         void visit(const ASTAnd *node, void *data) override  {
            defVisit<ASTAnd>(node, data);
        }

         void visit(const ASTCompEqual *node, void *data) override  {
            defVisit<ASTCompEqual>(node, data);
        }

         void visit(const ASTCompNequal *node, void *data) override  {
            defVisit<ASTCompNequal>(node, data);
        }

         void visit(const ASTCompGTE *node, void *data) override  {
            defVisit<ASTCompGTE>(node, data);
        }

         void visit(const ASTCompLTE *node, void *data) override  {
            defVisit<ASTCompLTE>(node, data);
        }

         void visit(const ASTCompGT *node, void *data) override  {
            defVisit<ASTCompGT>(node, data);
        }

         void visit(const ASTCompLT *node, void *data) override  {
            defVisit<ASTCompLT>(node, data);
        }

         void visit(const ASTAdd *node, void *data) override  {
            defVisit<ASTAdd>(node, data);
        }

         void visit(const ASTSubtract *node, void *data) override  {
            defVisit<ASTSubtract>(node, data);
        }

         void visit(const ASTTimes *node, void *data) override  {
            defVisit<ASTTimes>(node, data);
        }

         void visit(const ASTDivide *node, void *data) override  {
            defVisit<ASTDivide>(node, data);
        }

         void visit(const ASTUnaryNot *node, void *data) override  {
            defVisit<ASTUnaryNot>(node, data);
        }

         void visit(const ASTUnaryPlus *node, void *data) override  {
            defVisit<ASTUnaryPlus>(node, data);
        }

         void visit(const ASTUnaryMinus *node, void *data) override  {
            defVisit<ASTUnaryMinus>(node, data);
        }

         void visit(const ASTFnInvoke *node, void *data) override  {
            defVisit<ASTFnInvoke>(node, data);
        }

         void visit(const ASTString *node, void *data) override  {
            defVisit<ASTString>(node, data);
        }

         void visit(const ASTMethodInvoke *node, void *data) override  {
            defVisit<ASTMethodInvoke>(node, data);
        }

         void visit(const ASTIdentifier *node, void *data) override  {
            defVisit<ASTIdentifier>(node, data);
        }

         void visit(const ASTMemIdentifier *node, void *data) override  {
            defVisit<ASTMemIdentifier>(node, data);
        }

         void visit(const ASTDereference *node, void *data) override  {
            defVisit<ASTDereference>(node, data);
        }

         void visit(const ASTCharacter *node, void *data) override  {
            defVisit<ASTCharacter>(node, data);
        }

         void visit(const ASTNumber *node, void *data) override  {
            defVisit<ASTNumber>(node, data);
        }

         void visit(const ASTTrue *node, void *data) override  {
            defVisit<ASTTrue>(node, data);
        }

         void visit(const ASTFalse *node, void *data) override  {
            defVisit<ASTFalse>(node, data);
        }

        virtual void visit(const ASTEOF *node, void *data){
            defVisit<ASTEOF>(node, data);
        }

         void visit(const ASTExpression *node, void *data) override  {
            defVisit<ASTExpression>(node, data);
        }
    };

}





#endif //RATTLE_CPP_STATEEXPRESSIONPARSER_H
