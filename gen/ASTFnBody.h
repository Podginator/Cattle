/* Generated By:JJTree: Do not edit this line. ASTFnBody.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTFnBody_H_
#define ASTFnBody_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTFnBody : public SimpleNode {
public: 
           ASTFnBody(int id);
           ASTFnBody(Rattle *parser, int id);
  virtual ~ASTFnBody();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
