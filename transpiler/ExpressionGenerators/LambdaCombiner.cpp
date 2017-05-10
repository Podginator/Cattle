#include "LambdaCombiner.h"
#include "../../exceptions/ParsingException.h"
#include "../../TypeInformation/LambdaTypeInformation.h"
#include "../../gen/CharStream.h"
#include "../../gen/RattleTokenManager.h"
#include "../../gen/Rattle.h"
#include "ExpressionGeneratorFactory.h"

RattleLang::ExpressionGeneratorResult
RattleLang::LambdaCombiner::combine_statement(const RattleLang::SimpleNode *node, RattleLang::operands operand,
                                              bool is_multi_assign) {
    size_t children_size = get_number_children(node);
    for (int i = 0; i < children_size; ++i) {
        node->jjtGetChild(i)->jjtAccept(this, nullptr);
    }

    ret_statement.insert(0, "return ");
    ret_statement.append("}");
    string combined = "temp = " + parameters+ret_statement + "\n";

    // Rely on the parser to generate a new AST that calls a(b(c(d(x,y))))
    // This then lets our already existing expression generator handle the complexities.
    CharStream *stream = new CharStream(combined.c_str(), combined.size() - 1, 1, 1);
    Rattle parser(new RattleTokenManager(stream));
    ASTExpression* exp = get_expression(parser.code());

    res = ExpressionGeneratorFactory::do_expression(exp, m_context, false);

    res.preample.clear();
    return res;
}

RattleLang::LambdaCombiner::LambdaCombiner(RattleLang::Context *context) {
    m_context = context;
}

RattleLang::ASTExpression *RattleLang::LambdaCombiner::get_expression(const SimpleNode* node) {
    // Code (0) -> Statement (0) -> Assignment (0) -> Expression(1)
    return get_child_as<ASTExpression>(node->jjtGetChild(0)->jjtGetChild(0), 1);
}

void RattleLang::LambdaCombiner::defaultVisit(const RattleLang::SimpleNode *node, void *data) {
    throw ParsingException("Unexpected node seen at ", get_line_num(node));
}

void RattleLang::LambdaCombiner::visit(const RattleLang::ASTAdd *node, void *data) {
    // Do children
    size_t children_size = get_number_children(node);
    for (int i = 0; i < children_size; ++i) {
        node->jjtGetChild(i)->jjtAccept(this, data);
    }
}

void RattleLang::LambdaCombiner::visit(const RattleLang::ASTDereference *node, void *data) {
    node->jjtGetChild(0)->jjtAccept(this, data);
}

void RattleLang::LambdaCombiner::visit(const RattleLang::ASTIdentifier *node, void *data) {
    string node_token = get_token_of_node(node);
    TypeInfoPtr type_info =  m_context->get_function(node_token);

    if (!dynamic_pointer_cast<LambdaTypeInformation>(type_info)) {
        throw ParsingException("Cannot perform a lambda combination on disparate types", get_line_num(node));
    }


    string statement(node_token + "(");
    // If this is the first one we've seen it is the one we'll extract parameters on.
    if (!seen_first) {
        parameters.append("(");
        for (const auto& info : type_info->inner_vars) {
            parameters.append(" " + info.first + " : ");
            parameters.append(info.second->get_rattle_typename());
            parameters.append(",");
        }
        parameters.pop_back();
        parameters.append(")->{");
        statement.append(StringHelper::combine_str_ptr(type_info->inner_vars, ',', &NamedVariableInfo::first));
        seen_first = true;
    } else {
        // Ensure that the next types are correct, if not throw an exception.
        size_t ret_num = last_ret_type->num_return();

        if (ret_num != type_info->inner_vars.size()) {
            throw ParsingException("Invalid number of parameters passed in lambda composition", get_line_num(node));
        }

        for (int i = 0; i < ret_num ; ++i) {
            // Get the return type values.
            if (type_info->inner_vars[0].second->get_rattle_typename()
                                != last_ret_type->typenames[0].get_type_name()) {

                throw ParsingException("Invalid type passed to lambda", get_line_num(node));
            }
        }


    }
    ret_statement.insert(0, statement);
    ret_statement.append(")");

    last_ret_type = type_info;

    // We wanna make sure that it is compatible.

}
