/* Generated By:JJTree: Do not edit this line. ASTTrue.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTTrue_H_
#define ASTTrue_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTTrue : public SimpleNode {
public: 
           ASTTrue(int id);
           ASTTrue(Rattle *parser, int id);
  virtual ~ASTTrue();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
