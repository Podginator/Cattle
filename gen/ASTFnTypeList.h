//
// Created by podgi on 4/13/2017.
//

#ifndef RATTLE_CPP_ASTFNTYPELIST_H
#define RATTLE_CPP_ASTFNTYPELIST_H

#include "SimpleNode.h"

namespace RattleLang {
    class Rattle;


    class ASTFnTypeList : public SimpleNode {
    public:
        ASTFnTypeList(int id);
        ASTFnTypeList(Rattle *parser, int id);
        virtual ~ASTFnTypeList();

        /** Accept the visitor. **/
        virtual void  jjtAccept(RattleVisitor *visitor, void * data) const ;
    };

}

#endif //RATTLE_CPP_ASTFNTYPELIST_H
