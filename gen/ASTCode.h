/* Generated By:JJTree: Do not edit this line. ASTCode.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTCode_H_
#define ASTCode_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTCode : public SimpleNode {
public: 
           ASTCode(int id);
           ASTCode(Rattle *parser, int id);
  virtual ~ASTCode();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
