/* Generated By:JJTree: Do not edit this line. ASTFnInvoke.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTFnInvoke.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTFnInvoke::ASTFnInvoke(int id) : SimpleNode(id) {
  }
  ASTFnInvoke::ASTFnInvoke(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTFnInvoke::~ASTFnInvoke() {
  }

  /** Accept the visitor. **/
  void  ASTFnInvoke::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}
