/* Generated By:JJTree: Do not edit this line. ASTCompNequal.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTCompNequal.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTCompNequal::ASTCompNequal(int id) : SimpleNode(id) {
  }
  ASTCompNequal::ASTCompNequal(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTCompNequal::~ASTCompNequal() {
  }

  /** Accept the visitor. **/
  void  ASTCompNequal::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}