#ifndef RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H
#define RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H

#include "ExpressionCombiner.h"
#include "../../gen/RattleTree.h"
#include "../../gen/RattleVisitor.h"
#include "../../exceptions/ParsingException.h"
#include "DefaultExpressionCombiner.h"
#include "BasicExpressionCombiner.h"

namespace RattleLang {
    class ExpressionCombinerFactory {
    public:


        static ExpressionCombinerPtr get_expression_combiner(const SimpleNode *node, Context* context) {
            if (RattleVisitor::get_number_children(node) == 2) {

            }

            return ExpressionCombinerPtr(new BasicExpressionCombiner(context));
        }

        static ExpressionCombinerResult do_expression(const SimpleNode *node, Context* context) {
            ExpressionCombinerPtr expr_comb = get_expression_combiner(node, context);

            if (!expr_comb) {
                //throw ParsingException("Cannot perform this expression", RattleVisitor::get_line_num(node));
            }

            operands operand = get_operand_from_node(node);
            if (operand == NONE_OP) {
                //throw ParsingException("Cannot perform this expression", RattleVisitor::get_line_num(node));
            }

            ExpressionCombinerResult res = expr_comb->combine_statement(node, get_operand_from_node(node));
            return res;
        }

    private:

        // Could use a map but screw it.
        static operands get_operand_from_node(const SimpleNode *node) {
            if (RattleVisitor::get_node_as<ASTAdd>(node)) {
                return ADD_OP;
            } else if (RattleVisitor::get_node_as<ASTTimes>(node)) {
                return MUL_OP;
            } else if (RattleVisitor::get_node_as<ASTDivide>(node)) {
                return DIV_OP;
            } else if (RattleVisitor::get_node_as<ASTSubtract>(node)) {
                return SUB_OP;
            } else if (RattleVisitor::get_node_as<ASTUnaryMinus>(node)) {
                return UN_MIN_OP;
            } else if (RattleVisitor::get_node_as<ASTUnaryPlus>(node)) {
                return UN_PLUS_OP;
            } else if (RattleVisitor::get_node_as<ASTUnaryNot>(node)) {
                return NOT_OP;
            } else if (RattleVisitor::get_node_as<ASTOr>(node)) {
                return OR_OP;
            } else if (RattleVisitor::get_node_as<ASTAnd>(node)) {
                return AND_OP;
            } else if (RattleVisitor::get_node_as<ASTCompGT>(node)) {
                return GT_OP;
            } else if (RattleVisitor::get_node_as<ASTCompGTE>(node)) {
                return GTE_OP;
            }  else if (RattleVisitor::get_node_as<ASTCompLT>(node)) {
                return LT_OP;
            } else if (RattleVisitor::get_node_as<ASTCompGTE>(node)) {
                return LTE_OP;
            }  else if (RattleVisitor::get_node_as<ASTCompEqual>(node)) {
                return EQ_OP;
            } else if (RattleVisitor::get_node_as<ASTCompNequal>(node)) {
                return NEQ_OP;
            }


            return NONE_OP;
        }


    };
}


#endif //RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H
