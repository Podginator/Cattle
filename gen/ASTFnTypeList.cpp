//
// Created by podgi on 4/13/2017.
//
#include "ASTFnTypeList.h"
#include "RattleVisitor.h"

namespace RattleLang {

    ASTFnTypeList::ASTFnTypeList(int id) : SimpleNode(id) {
    }
    ASTFnTypeList::ASTFnTypeList(Rattle *parser, int id) : SimpleNode(parser, id) {
    }
    ASTFnTypeList::~ASTFnTypeList() {
    }

    /** Accept the visitor. **/
    void  ASTFnTypeList::jjtAccept(RattleVisitor *visitor, void * data) const {
        return
                visitor->visit(this, data);
    }

}
