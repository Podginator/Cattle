/* Generated By:JJTree: Do not edit this line. ASTObjCreate.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTObjCreate_H_
#define ASTObjCreate_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTObjCreate : public SimpleNode {
public: 
           ASTObjCreate(int id);
           ASTObjCreate(Rattle *parser, int id);
  virtual ~ASTObjCreate();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif