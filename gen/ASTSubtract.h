/* Generated By:JJTree: Do not edit this line. ASTSubtract.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTSubtract_H_
#define ASTSubtract_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTSubtract : public SimpleNode {
public: 
           ASTSubtract(int id);
           ASTSubtract(Rattle *parser, int id);
  virtual ~ASTSubtract();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
