//
// Created by Thomas Rogers on 04/04/2017.
//

#ifndef RATTLE_CPP_STATEABLEPARSER_H
#define RATTLE_CPP_STATEABLEPARSER_H
#include "../gen/RattleTree.h"
#include "../gen/RattleVisitor.h"
#include "StateMachineParserDecorator.h"


namespace RattleLang {

    template <class T>
    class StateMachineParser : public RattleDefaultVisitor {

    public:
        virtual void SetStateParser(StateMachineParserDecorator<T> *parser) {
            ref = parser;
        }


        virtual void ChildAccept(const SimpleNode *n, size_t childNum, void *data = nullptr) {
            n->jjtGetChild(childNum)->jjtAccept(ref, data);
        }

        virtual void ChildrenAccept(const SimpleNode* n, void* data = nullptr) {
            n->childrenAccept(ref, data);
        }

        virtual void Accept(const SimpleNode* n, void* data = nullptr) {
            n->jjtAccept(ref, data);
        }
    protected:
        StateMachineParserDecorator<T> *ref;
    };

}

#endif //RATTLE_CPP_STATEABLEPARSER_H
