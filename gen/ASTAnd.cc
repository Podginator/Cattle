/* Generated By:JJTree: Do not edit this line. ASTAnd.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTAnd.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTAnd::ASTAnd(int id) : SimpleNode(id) {
  }
  ASTAnd::ASTAnd(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTAnd::~ASTAnd() {
  }

  /** Accept the visitor. **/
  void  ASTAnd::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}
