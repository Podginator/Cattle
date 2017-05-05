#ifndef RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H
#define RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H

#include "ExpressionGenerator.h"
#include "../../gen/RattleTree.h"
#include "../../gen/RattleVisitor.h"
#include "../../exceptions/ParsingException.h"
#include "DefaultStateExpressionGenerator.h"
#include "BasicExpressionGenerator.h"
#include "../TypeInferer.h"
#include "../../TypeInformation/LambdaTypeInformation.h"
#include "TupleCombiner.h"

namespace RattleLang {
    class ExpressionGeneratorFactory {
    public:


        static ExpressionCombinerPtr get_expression_combiner(const SimpleNode *node, Context* context, bool is_multi_assign) {
            TypeInfoPtr expression = TypeInferer::get_instance()->StartParsing(get_expression(node), context);

            if (TypeInformation::is_empty(expression)) {
                throw ParsingException("Cannot perform this expression ", RattleVisitor::get_line_num(node));
            }

            if (dynamic_pointer_cast<LambdaTypeInformation>(expression)) {
                // Return Lambda Combiner.
                //return nullptr;
            } else if (get_operand_from_node(node) == ADD_OP && expression->source == TUPLE) {
                return ExpressionCombinerPtr(new TupleCombiner(context));
            }


            return ExpressionCombinerPtr(new BasicExpressionGenerator(context));
        }

        static ExpressionGeneratorResult do_expression(const SimpleNode *node, Context* context, bool is_multi_assign) {
            ExpressionCombinerPtr expr_comb = get_expression_combiner(node, context, is_multi_assign);

            if (!expr_comb) {
                throw ParsingException("Cannot perform this expression", RattleVisitor::get_line_num(node));
            }

            ExpressionGeneratorResult res = expr_comb->combine_statement(node, get_operand_from_node(node), is_multi_assign);
            return res;
        }

        static const ASTExpression* get_expression(const SimpleNode* node) {
            ASTExpression* ret_node = const_cast<ASTExpression*>(RattleVisitor::get_node_as<ASTExpression>(node));
            if (ret_node) {
                return ret_node;
            }
            ret_node = new ASTExpression(0);
            ret_node->jjtAddChild(const_cast<SimpleNode*>(node),0);

            return ret_node;

        }

        // Could use a map but screw it.
        static operands get_operand_from_node(const SimpleNode *node) {

            const ASTExpression*  exp = get_expression(node);
            

            if (RattleVisitor::get_child_as<ASTAdd>(exp, 0)) {
                return ADD_OP;
            } else if (RattleVisitor::get_child_as<ASTTimes>(exp, 0)) {
                return MUL_OP;
            } else if (RattleVisitor::get_child_as<ASTDivide>(exp, 0)) {
                return DIV_OP;
            } else if (RattleVisitor::get_child_as<ASTSubtract>(exp, 0)) {
                return SUB_OP;
            } else if (RattleVisitor::get_child_as<ASTUnaryMinus>(exp, 0)) {
                return UN_MIN_OP;
            } else if (RattleVisitor::get_child_as<ASTUnaryPlus>(exp, 0)) {
                return UN_PLUS_OP;
            } else if (RattleVisitor::get_child_as<ASTUnaryNot>(exp, 0)) {
                return NOT_OP;
            } else if (RattleVisitor::get_child_as<ASTOr>(exp, 0)) {
                return OR_OP;
            } else if (RattleVisitor::get_child_as<ASTAnd>(exp, 0)) {
                return AND_OP;
            } else if (RattleVisitor::get_child_as<ASTCompGT>(exp, 0)) {
                return GT_OP;
            } else if (RattleVisitor::get_child_as<ASTCompGTE>(exp, 0)) {
                return GTE_OP;
            }  else if (RattleVisitor::get_child_as<ASTCompLT>(exp, 0)) {
                return LT_OP;
            } else if (RattleVisitor::get_child_as<ASTCompGTE>(exp, 0)) {
                return LTE_OP;
            }  else if (RattleVisitor::get_child_as<ASTCompEqual>(exp, 0)) {
                return EQ_OP;
            } else if (RattleVisitor::get_child_as<ASTCompNequal>(exp, 0)) {
                return NEQ_OP;
            }


            return NONE_OP;
        }


    };
}


#endif //RATTLE_CPP_EXPRESSIONCOMBINERFACTORY_H
