/* Generated By:JJTree: Do not edit this line. ASTAssignment.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTAssignment_H_
#define ASTAssignment_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTAssignment : public SimpleNode {
public: 
           ASTAssignment(int id);
           ASTAssignment(Rattle *parser, int id);
  virtual ~ASTAssignment();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
