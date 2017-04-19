/* Generated By:JJTree: Do not edit this line. ASTStatement.cc Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTStatement.h"
#include "RattleVisitor.h"

namespace RattleLang {
  
  ASTStatement::ASTStatement(int id) : SimpleNode(id) {
  }
  ASTStatement::ASTStatement(Rattle *parser, int id) : SimpleNode(parser, id) {
  }
  ASTStatement::~ASTStatement() {
  }

  /** Accept the visitor. **/
  void  ASTStatement::jjtAccept(RattleVisitor *visitor, void * data) const {
    return 
    visitor->visit(this, data);
  }

}
