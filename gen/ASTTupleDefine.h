/* Generated By:JJTree: Do not edit this line. ASTAdd.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTTuple_H_
#define ASTTuple_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTTupleDefine : public SimpleNode {
public:
    ASTTupleDefine(int id);
    ASTTupleDefine(Rattle *parser, int id);
  virtual ~ASTTupleDefine();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif
