#ifndef RATTLE_CPP_FUNCTIONBUILDER_H
#define RATTLE_CPP_FUNCTIONBUILDER_H

#include "../gen/RattleTree.h"
#include "../gen/RattleVisitor.h"
#include "../TypeInformation/Context.h"


namespace RattleLang {

    //  Builds up Functions from their components.
    class FunctionBuilder : public RattleDefaultVisitor {

    public:

        FunctionBuilder(Context* context);
        void StartParsing(const SimpleNode* node, const std::string& name);
        void defaultVisit(const SimpleNode *node, void *data) override;
        void visit(const ASTFnBody *node, void *data) override;
        void visit(const ASTFnTypeList *node, void *data) override;
        void visit(const ASTParmlist *node, void *data) override;
        void visit(const ASTLambdaPass *node, void *data) override;
        void visit(const ASTIdentifier *node, void *data) override;
        void visit(const ASTReturnExpression *node, void *data) override;
        std::string get_c_output() { return m_output; }
        TypeInfoPtr declare_function(const SimpleNode* node, const std::string& name,  bool is_lambda);

    private:

        void build_function(const SimpleNode* node, const std::string& name,  bool is_named);
        void build_type_from_return(const ASTReturnExpression *node, Context* fnContext, TypeInfoPtr& type);

        std::string m_output;
        Context* m_context;

    };
}



#endif //RATTLE_CPP_FUNCTIONBUILDER_H
