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

    // A bare bones parser that simply visits pre-defines all the variables
    // functions and classes - Then declares the main function.
    class MainParser : public RattleDefaultVisitor {
    public:


        MainParser(ASTCode* code);
        void StartParsing(const SimpleNode* node);
        std::string get_c_output();

        void defaultVisit(const SimpleNode *node, void * data);
        // Declarations
        void visit(const ASTClassDef *node, void *data) override;
        void visit(const ASTFnDef* node, void* data) override;
        void visit(const ASTAssignment* node, void* data) override;

       ~Parser() { }

        void visit(const ASTStatement *node, void *data) override;


    private: 
        std::string cOutput;
        ASTCode* codeNode;
        std::string create_preample();

        Context* context;
    };


}


#endif
/* JavaCC - OriginalChecksum=db58fff3e9cd6809f7829270fa63d602 (do not edit this line) */
