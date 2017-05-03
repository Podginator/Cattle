#ifndef RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H
#define RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H

namespace RattleLang {
    class ExpressionCombinerFactory {
    public:

        static ExpressionCombinerPtr get_expression_combiner(const SimpleNode *node) {


        }

        static string do_expression(const SimpleNode *node);

    private:

        // Could use a map but screw it.
        static operands get_operand_from_node(const SimpleNode *node) {
            if (get_node_as<ASTAdd>(node)) {
                return ADD_OP;
            } else if (get_node_as<ASTTimes>(node)) {
                return MUL_OP;
            } else if (get_node_as<ASTDivide>(node)) {
                return DIV_OP;
            } else if (get_node_as<ASTSubtract>(node)) {
                return SUB_OP;
            } else if (get_node_as<ASTUnaryMinus>(node)) {
                return UN_MIN_OP;
            } else if (get_node_as<ASTUnaryPlus>(node)) {
                return UN_PLUS_OP;
            } else if (get_node_as<ASTUnaryNot>(node)) {
                return NOT_OP;
            } else if (get_node_as<ASTOr>(node)) {
                return OR_OP;
            } else if (get_node_as<ASTAnd>(node)) {
                return AND_OP;
            } else if (get_node_as<ASTCompGT>(node)) {
                return GT_OP;
            } else if (get_node_as<ASTCompGTE>(node)) {
                return GTE_OP;
            }  else if (get_node_as<ASTCompLT>(node)) {
                return LT_OP;
            } else if (get_node_as<ASTCompGTE>(node)) {
                return LTE_OP;
            }  else if (get_node_as<ASTCompEqual>(node)) {
                return EQ_OP;
            } else if (get_node_as<ASTCompNequal>(node)) {
                return NEQ_OP;
            }


            return NONE;
        }


    };
}


#endif //RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H
