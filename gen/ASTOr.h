/* Generated By:JJTree: Do not edit this line. ASTOr.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTOr_H_
#define ASTOr_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTOr : public SimpleNode {
public: 
           ASTOr(int id);
           ASTOr(Rattle *parser, int id);
  virtual ~ASTOr();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
