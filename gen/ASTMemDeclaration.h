/* Generated By:JJTree: Do not edit this line. ASTMemDeclaration.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=false,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef ASTMemDeclaration_H_
#define ASTMemDeclaration_H_
#include "SimpleNode.h"


namespace RattleLang {
class Rattle;


class ASTMemDeclaration : public SimpleNode {
public: 
           ASTMemDeclaration(int id);
           ASTMemDeclaration(Rattle *parser, int id);
  virtual ~ASTMemDeclaration();

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
};

}

#endif