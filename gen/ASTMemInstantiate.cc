/* Generated By:JJTree: Do not edit this line. ASTMemInstantiate.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTMemInstantiate.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTMemInstantiate::ASTMemInstantiate(int id) : SimpleNode(id) {
  }
  ASTMemInstantiate::ASTMemInstantiate(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTMemInstantiate::~ASTMemInstantiate() {
  }

  /** Accept the visitor. **/
  void  ASTMemInstantiate::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}
