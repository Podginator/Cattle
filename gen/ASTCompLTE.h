/* Generated By:JJTree: Do not edit this line. ASTCompLTE.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTCompLTE_H_
#define ASTCompLTE_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTCompLTE : public SimpleNode {
public: 
           ASTCompLTE(int id);
           ASTCompLTE(Rattle *parser, int id);
  virtual ~ASTCompLTE();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
