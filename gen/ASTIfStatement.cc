/* Generated By:JJTree: Do not edit this line. ASTIfStatement.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTIfStatement.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTIfStatement::ASTIfStatement(int id) : SimpleNode(id) {
  }
  ASTIfStatement::ASTIfStatement(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTIfStatement::~ASTIfStatement() {
  }

  /** Accept the visitor. **/
  void  ASTIfStatement::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}
