#ifndef RATTLE_CPP_EXPRESSIONCOMBINER_H
#define RATTLE_CPP_EXPRESSIONCOMBINER_H
#include <string>
#include "../../gen/SimpleNode.h"
#include "../../TypeInformation/type.h"
#include "../../TypeInformation/TypeInformation.h"


using namespace std;


namespace RattleLang {

    typedef shared_ptr<ExpressionCombiner> ExpressionCombinerPtr;
    // Interface for an expression combiner.
    class ExpressionCombiner {
    public:

        ExpressionCombiner(TypeInfoPtr expected_output);

        virtual string combine_statement(SimpleNode *node, SimpleNode *node2, operands operand) = 0;

    private:
        TypeInfoPtr m_expected_output;



    };
}


#endif //RATTLE_CPP_EXPRESSIONCOMBINER_H
