/* Generated By:JJTree: Do not edit this line. ASTAnd.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTAnd_H_
#define ASTAnd_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTAnd : public SimpleNode {
public: 
           ASTAnd(int id);
           ASTAnd(Rattle *parser, int id);
  virtual ~ASTAnd();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
