#include "ScopeParser.h"
#include "TypeInferer.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"
#include "../TypeInformation/LambdaTypeInformation.h"
using namespace std;
using namespace RattleLang;

ScopeParser::ScopeParser(Context *context, bool exclusiveScope) {
    m_context = context;
    m_exclusive_scope = exclusiveScope;
    state = DECLARATION;
}

void ScopeParser::StartParsing(const SimpleNode *n) {
    ChildrenAccept(n);

    int current_state = static_cast<int>(state);
    if (current_state == static_cast<int>(LAST)) {
        return;
    }

    state = static_cast<BlockState>(++current_state);
    StartParsing(n);
}

void ScopeParser::declare(const ASTAssignment *node, void *data) {
    size_t index_of_expressions = get_index_of_expressions_in_assignment(node);
    size_t i = 0;
    size_t j = 0;
    size_t node_children = get_number_children(node);

    ExpressionOp op(ExpressionOp::ASSIGNMENT, {});
    while ((i < index_of_expressions) && ((index_of_expressions + j) < node_children)) {
        vector<string> operators;
        int current_expression = index_of_expressions + j;

        // Made up of 1 or more expressions.
        ASTExpression *exp = get_child_as<ASTExpression>(node, current_expression);
        TypeInfoPtr expression_type(new TypeInformation());
        declare(exp, &expression_type);
        size_t typename_returned = expression_type->num_return();
        m_expression_count[exp] = typename_returned;

        for (int k = 0; (k < typename_returned) && (i < index_of_expressions); k++, i++) {
            string variable_name = get_token_of_child(node, i);
            TypeInfoPtr variable_info = m_context->get_variable(variable_name);

            // The variable exists in a scope other than this one.
            if (!TypeInformation::is_empty(variable_info)) {
                if (!m_exclusive_scope) {
                    // Throw a parsing exception if the types do not match.
                    bool typematch = (variable_info->get_c_typename() == expression_type->get_c_typename())
                                     || (variable_info->get_c_typename() == expression_type->typenames[k].get_corresponding_type_string());
                    if (!typematch) {
                        throw ParsingException("Type Mismatch, cannot convert " + variable_info->get_rattle_typename()
                                               + " to " + expression_type->get_rattle_typename(), get_line_num(node));
                    }

                    // Otherwise continue, as we've already declared a variable of this type.
                    continue;
                }
            }

            // Find the subinformation
            if (!variable_info || m_context != variable_info->scope) {
                TypeInfoPtr declared_info;
                if (((index_of_expressions == 1) && (typename_returned > 1)) ||
                    get_child_as<ASTLambdaDefine>(node->jjtGetChild(1), 0)) {
                    declared_info = TypeInfoPtr(expression_type);
                } else {
                    declared_info = TypeInfoPtr(new TypeInformation({expression_type->typenames[k]}, m_context));
                }

                m_context->add_variable(get_token_of_child(node, i), declared_info);
                cOut += declared_info->get_c_return_types() + " " + variable_name + ";\n";
            }
        }
        ++j;
    }
}

// Parse an Expression to find out it's type.
void ScopeParser::declare(const ASTExpression *node, void *data) {
    if (data) {
        TypeInfoPtr* type = (reinterpret_cast< TypeInfoPtr*>(data));

        if (type) {
            *type = TypeInfoPtr(TypeInferer::get_instance()->StartParsing(node,m_context));
        }
    }
}

void ScopeParser::implement(const ASTExpression *node, void *data) {
    if (!node->isDone) {
        ExpressionOp op = data ? *(static_cast<ExpressionOp *>(data)) : ExpressionOp(ExpressionOp::ANONYMOUS, {});
        cOut += GetParserResults(ExpressionParser(op, m_context), node);
    }
}

void ScopeParser::implement(const ASTAssignment *node, void *data) {
    int index_of_expressions = get_index_of_expressions_in_assignment(node);
    size_t num_children = get_number_children(node);
    int i = 0;
    int j = 0;

    while ((i < index_of_expressions) && ((index_of_expressions + j) < num_children)) {
        ExpressionOp op(ExpressionOp::ASSIGNMENT, {});
        vector<string> operators;
        int current_expression = index_of_expressions + j;

        // Made up of 1 or more expressions.
        ASTExpression *exp = get_child_as<ASTExpression>(node, current_expression);
        size_t count = m_expression_count[exp];
        for (int k = 0; (k < count) && (i < index_of_expressions); ++k, ++i) {
            op.parents.push_back(get_token_of_child(node, i));
        }
        implement(exp, &op);
        ++j;
    }
}

// Implement a while loop.
void ScopeParser::implement(const ASTWhileLoop *node, void *data) {
    ASTExpression *exp = get_child_as<ASTExpression>(node, 0);
    TypeInfoPtr bool_type;
    declare(exp, &bool_type);

    if (bool_type->typenames[0].type_name == BOOLEAN) {
        cOut += "while(true)";
        cOut += SCOPE_OPEN;

        // Perform Operation to ensure that we break out of a loop.
        string unique_name = get_unique_name("while");
        ExpressionOp op(ExpressionOp::ASSIGNMENT, {unique_name});

        cOut += "bool " + unique_name + ";\n";
        cOut += GetParserResults(ExpressionParser(op, m_context), exp);
        cOut += "\nif (!" + unique_name + ") break;\n";

        // Then perform the inner statement.
        shared_ptr<Context> whileParserContext = make_shared<Context>(m_context);
        cOut += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(whileParserContext.get()),
                                                                           get_child_as<ASTStatement>(node, 1));
        cOut += SCOPE_CLOSE;
        return;
    };

    throw ParsingException("boolean expression require for while loop", get_line_num(node));

}

// Implement a For loop.
void ScopeParser::implement(const ASTForLoop *node, void *data) {
    cOut += SCOPE_OPEN;
    ASTAssignment *assignment = get_child_as<ASTAssignment>(node, 0);
    declare(assignment, data);
    implement(assignment, data);

    ASTExpression *exp = get_child_as<ASTExpression>(node, 1);
    TypeInfoPtr booltype;
    declare(exp, &booltype);

    // Check we're a bool
    if (booltype->typenames[0].type_name == BOOLEAN) {
        cOut += "while(true) {\n";

        // Perform some kind of break logic.
        string unique_name = get_unique_name("for");
        ExpressionOp op(ExpressionOp::ASSIGNMENT, {unique_name});
        cOut += "bool " + unique_name + ";\n";

        cOut += GetParserResults(ExpressionParser(op, m_context), exp);
        cOut += "\nif (!" + unique_name + ") break;\n";

        // Then perform the inner statement
        shared_ptr<Context> forParserContext = make_shared<Context>(m_context);
        cOut += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(forParserContext.get()),
                                                                           static_cast<ASTStatement *>(node->jjtGetChild(3)));


        ASTAssignment* innerAssingment = get_child_as<ASTAssignment>(node, 2);
        declare(innerAssingment, data);
        implement(innerAssingment, data);

        cOut += SCOPE_CLOSE;
        cOut += SCOPE_CLOSE;
    };

}

void ScopeParser::implement(const ASTIfStatement *node, void *data) {
    // If statements consist of an expression and 1 or 2 statements
    ASTExpression *exp = static_cast<ASTExpression *>(node->jjtGetChild(0));
    TypeInfoPtr booltype;
    declare(exp, &booltype);

    // Check we're a bool
    if (booltype->typenames[0].type_name == BOOLEAN) {
        string unique_name = get_unique_name("if");
        ExpressionOp op(ExpressionOp::ASSIGNMENT, {unique_name});
        cOut += SCOPE_OPEN;
        cOut += "bool " + unique_name + ";\n";
        cOut += GetParserResults(ExpressionParser(op, m_context), exp);
        cOut += "\nif (" + unique_name + ")";
        cOut += SCOPE_OPEN;

        // Then perform the inner statement.
        shared_ptr<Context> ifParserContext(new Context(m_context));
        cOut += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(ifParserContext.get()),
                                                                           static_cast<ASTStatement *>(node->jjtGetChild(1)));
        cOut += SCOPE_CLOSE;

        if (node->ifHasElse) {
            // do the same.
            cOut += "else ";
            cOut += SCOPE_OPEN;
            shared_ptr<Context> elseParserContext = make_shared<Context>(m_context);
            cOut += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(elseParserContext.get()),
                                                                               static_cast<ASTStatement *>(node->jjtGetChild(2)));
            cOut += SCOPE_CLOSE;
        }
        cOut += SCOPE_CLOSE;
    };


}

void ScopeParser::implement(const ASTFnInvoke *node, void *data) {
    ASTExpression *exp = new ASTExpression(0);
    exp->jjtAddChild((Node *) node, 0);

    ExpressionOp op(ExpressionOp::ANONYMOUS, {});
    cOut += GetParserResults(ExpressionParser(op, m_context), exp);
    delete exp;
}

// Get the print Statement
void ScopeParser::implement(const ASTWrite *node, void *data) {
    ASTExpression *exp = static_cast<ASTExpression *>(node->jjtGetChild(0));
    TypeInfoPtr typeinfo = make_shared<TypeInformation>();
    declare(exp, &typeinfo);

    // We should only have one type.
    if (typeinfo->typenames.size() > 1) {
        throw TypeException(get_line_num(node));
    };

    string unique_name = get_unique_name("print");
    ExpressionOp op(ExpressionOp::ASSIGNMENT, {unique_name});
    cOut += SCOPE_OPEN;
    cOut += typeinfo->typenames[0].get_corresponding_type_string() + " " + unique_name + ";\n";
    cOut += GetParserResults(ExpressionParser(op, m_context), exp);
    cOut += "cout << " + unique_name + "<< endl;";
    cOut += SCOPE_CLOSE;

}
