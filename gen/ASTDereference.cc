/* Generated By:JJTree: Do not edit this line. ASTDereference.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTDereference.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTDereference::ASTDereference(int id) : SimpleNode(id) {
  }
  ASTDereference::ASTDereference(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTDereference::~ASTDereference() {
  }

  /** Accept the visitor. **/
  void  ASTDereference::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}