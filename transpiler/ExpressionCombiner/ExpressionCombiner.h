#ifndef RATTLE_CPP_EXPRESSIONCOMBINER_H
#define RATTLE_CPP_EXPRESSIONCOMBINER_H
#include <string>
#include "../../gen/SimpleNode.h"
#include "../../TypeInformation/type.h"
#include "../../TypeInformation/TypeInformation.h"


using namespace std;


namespace RattleLang {

    struct ExpressionCombinerResult {
        // IE: Any need to get multiple results
        string preample;
        // IE: Actual Expression
        string expression;
    };


    // Interface for an expression combiner.
    class ExpressionCombiner {
    public:

        ExpressionCombiner(Context* m_context);

        virtual ExpressionCombinerResult combine_statement(const SimpleNode *node, operands operand) = 0;



    };

    typedef shared_ptr<ExpressionCombiner> ExpressionCombinerPtr;
}


#endif //RATTLE_CPP_EXPRESSIONCOMBINER_H
