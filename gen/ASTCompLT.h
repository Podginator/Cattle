/* Generated By:JJTree: Do not edit this line. ASTCompLT.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTCompLT_H_
#define ASTCompLT_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTCompLT : public SimpleNode {
public: 
           ASTCompLT(int id);
           ASTCompLT(Rattle *parser, int id);
  virtual ~ASTCompLT();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
