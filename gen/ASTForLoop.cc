/* Generated By:JJTree: Do not edit this line. ASTForLoop.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTForLoop.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTForLoop::ASTForLoop(int id) : SimpleNode(id) {
  }
  ASTForLoop::ASTForLoop(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTForLoop::~ASTForLoop() {
  }

  /** Accept the visitor. **/
  void  ASTForLoop::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}
