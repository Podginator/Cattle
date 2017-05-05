#ifndef RATTLE_CPP_EXPRESSIONCOMBINER_H
#define RATTLE_CPP_EXPRESSIONCOMBINER_H
#include <string>
#include "../../gen/SimpleNode.h"
#include "../../TypeInformation/type.h"
#include "../../TypeInformation/TypeInformation.h"


using namespace std;


namespace RattleLang {

    class ExpressionGeneratorResult {
    public:
        // IE: Any need to get multiple results
        string preample;
        // The Actual Expressions.
        vector<string> expressions;

    };


    // Interface for an expression combiner.
    class ExpressionGenerator {
    public:

        virtual ExpressionGeneratorResult combine_statement(const SimpleNode *node, operands operand, bool is_multi_assign) = 0;

    protected:
        Context* m_context;
        ExpressionGeneratorResult res;

        void append_to_preamble(const string &str) {
            res.preample.append(str);
        }

        void append_to_result(const string &str) {
            res.expressions.back().append(str);
        }




    };

    typedef shared_ptr<ExpressionGenerator> ExpressionCombinerPtr;
}


#endif //RATTLE_CPP_EXPRESSIONCOMBINER_H
