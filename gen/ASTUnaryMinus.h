/* Generated By:JJTree: Do not edit this line. ASTUnaryMinus.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTUnaryMinus_H_
#define ASTUnaryMinus_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTUnaryMinus : public SimpleNode {
public: 
           ASTUnaryMinus(int id);
           ASTUnaryMinus(Rattle *parser, int id);
  virtual ~ASTUnaryMinus();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif