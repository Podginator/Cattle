#ifndef PARSER_H
#define PARSER_H

#include "../gen/RattleTree.h"
#include "ExpressionParser.h"
#include "../TypeInformation/ExpressionOp.h"
#include "StateMachineParserDecorator.h"
#include "StateMachineParser.h"
#include "TypeInferer.h"
#include <string>


namespace RattleLang { 

    // This is the main parser, it will also premake everything
    class Parser : public StateMachineParser<Parser> {
    public:

        enum RattleCompilerState {
            DECLARE = 0,
            IMPLEMENT = 1,
            MAIN = 2
        };

        Parser(ASTCode* code);
        void StartParsing(const SimpleNode* node);
        std::string get_c_output();
        template <class T>
        void defVisit(const T* node, void* data) {
            bool isDone = (SimpleNode*)(node)->isDone;

            if (!isDone) {
                switch (state) {
                    case DECLARE:
                        declare(node, data);
                        break;
                    case IMPLEMENT:
                        implement(node, data);
                        break;
                    case MAIN:
                        main(node, data);
                        break;
                }

                if (traverse) {
                    ChildrenAccept(node, data);
                }
            }


        }
        void defaultVisit(const SimpleNode *node, void * data);
        void visit(const SimpleNode* node, void* data);

        void declare(const SimpleNode *node, void* data);
        void implement(const SimpleNode *node, void* data);
        void main(const SimpleNode *node, void* data);
        void declare(const ASTStatement *node, void* data) { ChildAccept(node, 0);}
        void implement(const ASTStatement *node, void* data) { ChildAccept(node, 0);}
        void main(const ASTStatement *node, void* data) { ChildAccept(node, 0);}

        // Declarations
        void declare(const ASTClassDef *node, void *data);

        void declare(const ASTFnDef* node, void* data);
        void declare(const ASTFnBody* node, void* data);
        void declare(const ASTParmlist* node, void* data);
        void declare(const ASTFnTypeList* node, void* data);
        void declare(const ASTReturnExpression* node, void* data);

        void declare(const ASTAssignment* node, void* data);


        virtual void visit(const ASTEOF *node, void *data) override;

       ~Parser() { }


    private: 
        std::string cOutput;

        ASTCode* codeNode;

        bool traverse = false;

        int stateNum = 0;

        RattleCompilerState state = DECLARE;

        void transitionState(RattleCompilerState nextState);

        std::string create_preample();

        Context* context;

    };


}


#endif
/* JavaCC - OriginalChecksum=db58fff3e9cd6809f7829270fa63d602 (do not edit this line) */
