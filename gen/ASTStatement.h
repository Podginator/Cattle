/* Generated By:JJTree: Do not edit this line. ASTStatement.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTStatement_H_
#define ASTStatement_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTStatement : public SimpleNode {
public: 
           ASTStatement(int id);
           ASTStatement(Rattle *parser, int id);
  virtual ~ASTStatement();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
