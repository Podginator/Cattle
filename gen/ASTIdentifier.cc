/* Generated By:JJTree: Do not edit this line. ASTIdentifier.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTIdentifier.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTIdentifier::ASTIdentifier(int id) : SimpleNode(id) {
  }
  ASTIdentifier::ASTIdentifier(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTIdentifier::~ASTIdentifier() {
  }

  /** Accept the visitor. **/
  void  ASTIdentifier::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}
