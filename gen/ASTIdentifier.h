/* Generated By:JJTree: Do not edit this line. ASTIdentifier.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTIdentifier_H_
#define ASTIdentifier_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTIdentifier : public SimpleNode {
public: 
           ASTIdentifier(int id);
           ASTIdentifier(Rattle *parser, int id);
  virtual ~ASTIdentifier();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif