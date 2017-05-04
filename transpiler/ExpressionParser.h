#ifndef SIMPLEEXPR_H
#define SIMPLEEXPR_H

#include "../gen/RattleTree.h"
#include "../TypeInformation/TypeStorage.h"
#include "../TypeInformation/TypeInformation.h"
#include "../gen/RattleVisitor.h"
#include "StateMachineParser.h"
#include "../TypeInformation/ExpressionOp.h"
#include <string>

using namespace std;

namespace RattleLang{ 

    // There is a lot of side effects in this code.
    class ExpressionParser : public RattleDefaultVisitor {
    public:


        ExpressionParser(ExpressionOp op, Context* context)
                : parent(op), m_context(context){}

        void StartParsing(const SimpleNode* n);

        string get_c_output() { return res; }

        void defaultVisit(const SimpleNode *node, void *data) override {}


    private:
        string res;

        ExpressionOp parent;

        Context* m_context;

        bool has_fn_calls;

    };
}

#endif