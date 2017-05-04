#ifndef SIMPLEEXPR_H
#define SIMPLEEXPR_H

#include "../gen/RattleTree.h"
#include "../TypeInformation/TypeStorage.h"
#include "../TypeInformation/TypeInformation.h"
#include "../gen/RattleVisitor.h"
#include "StateMachineParser.h"
#include <string>

using namespace std;

namespace RattleLang{ 

    class ExpressionParser : public RattleDefaultVisitor {
    public:

        ExpressionParser(vector<string> names, Context* context)
                : assignments(names){
            m_context = context;
        }

        void StartParsing(const SimpleNode* n);

        string get_c_output() { return res; }

        void defaultVisit(const SimpleNode *node, void *data) override {}


    private:
        string res;

        vector<string> assignments;

        Context* m_context;

        bool has_fn_calls;

    };
}

#endif