/* Generated By:JJTree: Do not edit this line. SimpleNode.h Version 7.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=true,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=BaseASTNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#ifndef SIMPLENODE_H
#define SIMPLENODE_H
#include <vector>
#include "JavaCC.h"
#include "Token.h"
#include "Node.h"
#include "RattleTreeConstants.h"
#include "BaseASTNode.h"

namespace RattleLang {
class RattleVisitor;

class SimpleNode : public BaseASTNode, public Node {
protected: 
  std::vector<Node*> children;
  Node *             parent = nullptr;
  void *             value  = nullptr;
//int                numChildren;
  Token *            firstToken = nullptr;
  Token *            lastToken  = nullptr;
  Rattle*    parser = nullptr;
  int                id;

public: 
           SimpleNode(int id);
           SimpleNode(Rattle *parser, int id);
  virtual ~SimpleNode();

//#if !NODE_FACTORY
//\#define jjtCreate(id) new SimpleNode(id)
//\#define jjtCreate(p, id) new SimpleNode(p, id)
//#fi

    void                 setDone() { this->isDone = true;}
  virtual void           jjtOpen() const;
  virtual void           jjtClose() const;
  virtual void           jjtSetParent(Node *n);
  virtual Node *         jjtGetParent() const;
  virtual void           jjtAddChild(Node *n, size_t i);
  virtual Node *         jjtGetChild(size_t i) const;
  virtual size_t         jjtGetNumChildren() const;
  virtual void           jjtSetValue(void * value);
  virtual void *         jjtGetValue() const;

  virtual Token *        jjtGetFirstToken() const;
  virtual Token *        jjtGetLastToken() const;
  virtual void           jjtSetFirstToken(Token* token);
  virtual void           jjtSetLastToken(Token* token);

  /** Accept the visitor. **/
  virtual void  jjtAccept(RattleVisitor *visitor, void * data) const;

  /** Accept the visitor. **/
  virtual void           childrenAccept(RattleVisitor *visitor, void * data) const;

  /* You can override these two methods in subclasses of SimpleNode to
     customize the way the node appears when the tree is dumped.  If
     your output uses more than one line you should override
     toString(string), otherwise overriding toString() is probably all
     you need to do. */
  virtual JJString toString() const;
  virtual JJString toString(const JJString& prefix) const;

  /* Override this method if you want to customize how the node dumps
     out its children. */
  virtual void          dump(const JJString& prefix) const;
  virtual void          dumpToBuffer(const JJString& prefix, const JJString& separator, JJString *sb) const;
  virtual int           getId() const { return id;  }
};
}

#endif
/* JavaCC - OriginalChecksum=d5199b5b435a1f216a3651cc0c2ded4b (do not edit this line) */
