/* Generated By:JavaCC: Do not edit this line. RattleVisitor.h Version 7.0.0 */
#ifndef RATTLEVISITOR_H
#define RATTLEVISITOR_H

#include "JavaCC.h"
#include "RattleTree.h"


#define SCOPE_OPEN "\n{\n"
#define SCOPE_CLOSE "\n}\n"
namespace RattleLang {
class RattleVisitor
{
  public:
  virtual void  visit(const SimpleNode *node, void * data) = 0;
  virtual void  visit(const ASTCode *node, void * data) = 0;
  virtual void  visit(const ASTEOF *node, void * data) = 0;
  virtual void  visit(const ASTStatement *node, void * data) = 0;
  virtual void  visit(const ASTBlock *node, void * data) = 0;
  virtual void  visit(const ASTParmlist *node, void * data) = 0;
  virtual void  visit(const ASTClassDef *node, void * data) = 0;
  virtual void  visit(const ASTFnBody *node, void * data) = 0;
  virtual void  visit(const ASTFnTypeList *node, void * data) = 0;
  virtual void  visit(const ASTMethodDef *node, void * data) = 0;
  virtual void  visit(const ASTFnDef *node, void * data) = 0;
  virtual void  visit(const ASTReturnExpression *node, void * data) = 0;
  virtual void  visit(const ASTMemDeclaration *node, void * data) = 0;
  virtual void  visit(const ASTAssignment *node, void * data) = 0;
  virtual void  visit(const ASTIfStatement *node, void * data) = 0;
  virtual void  visit(const ASTObjCreate *node, void * data) = 0;
  virtual void  visit(const ASTMemInstantiate *node, void * data) = 0;
  virtual void  visit(const ASTMethodInstantiate *node, void * data) = 0;
  virtual void  visit(const ASTLabmdaDefine *node, void * data) = 0;
  virtual void  visit(const ASTForLoop *node, void * data) = 0;
  virtual void  visit(const ASTWhileLoop *node, void * data) = 0;
  virtual void  visit(const ASTWrite *node, void * data) = 0;
  virtual void  visit(const ASTArgList *node, void * data) = 0;
  virtual void  visit(const ASTExpression *node, void * data) = 0;
  virtual void  visit(const ASTOr *node, void * data) = 0;
  virtual void  visit(const ASTAnd *node, void * data) = 0;
  virtual void  visit(const ASTCompEqual *node, void * data) = 0;
  virtual void  visit(const ASTCompNequal *node, void * data) = 0;
  virtual void  visit(const ASTCompGTE *node, void * data) = 0;
  virtual void  visit(const ASTCompLTE *node, void * data) = 0;
  virtual void  visit(const ASTCompGT *node, void * data) = 0;
  virtual void  visit(const ASTCompLT *node, void * data) = 0;
  virtual void  visit(const ASTAdd *node, void * data) = 0;
  virtual void  visit(const ASTSubtract *node, void * data) = 0;
  virtual void  visit(const ASTTimes *node, void * data) = 0;
  virtual void  visit(const ASTDivide *node, void * data) = 0;
  virtual void  visit(const ASTUnaryNot *node, void * data) = 0;
  virtual void  visit(const ASTUnaryPlus *node, void * data) = 0;
  virtual void  visit(const ASTUnaryMinus *node, void * data) = 0;
  virtual void  visit(const ASTIndexedExpression *node, void * data) = 0;
  virtual void  visit(const ASTTupleDefine *node, void * data) = 0;
  virtual void  visit(const ASTFnInvoke *node, void * data) = 0;
  virtual void  visit(const ASTMethodInvoke *node, void * data) = 0;
  virtual void  visit(const ASTIdentifier *node, void * data) = 0;
  virtual void  visit(const ASTMemIdentifier *node, void * data) = 0;
  virtual void  visit(const ASTDereference *node, void * data) = 0;
  virtual void  visit(const ASTCharacter *node, void * data) = 0;
  virtual void  visit(const ASTString *node, void * data) = 0;
  virtual void  visit(const ASTNumber *node, void * data) = 0;
  virtual void  visit(const ASTTrue *node, void * data) = 0;
  virtual void  visit(const ASTFalse *node, void * data) = 0;
  virtual void  visit(const ASTLambdaPass *node, void * data) = 0;
    virtual void  visit(const ASTLambdaIds *node, void * data) = 0;




    virtual ~RattleVisitor() { }
};
class RattleDefaultVisitor : public RattleVisitor {
public:
  virtual void  defaultVisit(const SimpleNode *node, void * data) = 0;
  virtual void  visit(const SimpleNode *node, void * data) {
    defaultVisit(node, data);
}
  virtual void  visit(const ASTCode *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTEOF *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTStatement *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTBlock *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTParmlist *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTClassDef *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTFnBody *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTFnTypeList *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTMethodDef *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTFnDef *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTReturnExpression *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTMemDeclaration *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTAssignment *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTIfStatement *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTObjCreate *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTMemInstantiate *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTMethodInstantiate *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTLabmdaDefine *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTForLoop *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTWhileLoop *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTWrite *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTArgList *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTExpression *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTOr *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTAnd *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTCompEqual *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTCompNequal *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTCompGTE *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTCompLTE *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTCompGT *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTCompLT *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTAdd *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTSubtract *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTTimes *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTDivide *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTUnaryNot *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTUnaryPlus *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTUnaryMinus *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTIndexedExpression *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTTupleDefine *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTFnInvoke *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTMethodInvoke *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTIdentifier *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTMemIdentifier *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTDereference *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTCharacter *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTString *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTNumber *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTTrue *node, void * data) {
    defaultVisit(node, data);
  }
  virtual void  visit(const ASTFalse *node, void * data) {
    defaultVisit(node, data);
  }

  virtual void visit (const ASTLambdaPass *node, void* data) {
    defaultVisit(node, data);
  }
    virtual void  visit(const ASTLambdaIds *node, void * data) {
      defaultVisit(node, data);
    }

    ~RattleDefaultVisitor() { }

protected:

    static std::string  get_token_of_child(const SimpleNode* node, size_t index) {
      return dynamic_cast<SimpleNode*>(node->jjtGetChild(index))->tokenValue;
    }

    static int get_index_of_expressions_in_assignment(const ASTAssignment* node) {
      // Iterate through all the nodes.
      for (int i = 0; i < node->jjtGetNumChildren(); i++) {
        // When the node is no longer an Identifier or Member_Identifer, end.
        ASTExpression* exp = dynamic_cast<ASTExpression*>(node->jjtGetChild(i));

        if (exp) {
          return i;
        }
      }

      return -1;
    }

    std::string get_unique_name(const std::string& prefix = "default") {
      static std::map<std::string, int> prefix_map;
      int num = 0;
      if (prefix_map.find(prefix) != prefix_map.end()) {
        num = prefix_map[prefix];
      }
      prefix_map[prefix] = num + 1;

      // TODO: Check if this variable is declared anyway.

      return "__" + std::to_string(num) + prefix;


    }

};
}
#endif
/* JavaCC - OriginalChecksum=aef53ae7c807c2053347270803bad9b1 (do not edit this line) */
