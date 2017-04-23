//
// Created by podgi on 4/12/2017.
//

#include "ScopeParser.h"
#include "TypeInferer.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"

RattleLang::ScopeParser::ScopeParser(RattleLang::Context *context, bool exclusiveScope) {
    m_context = context;
    m_exclusive_scope = exclusiveScope;
    state = DECLARATION;
}

void RattleLang::ScopeParser::StartParsing(const RattleLang::SimpleNode *n) {
    // Iunno.
    ChildrenAccept(n);

    int stateNum = static_cast<int>(state);
    if (stateNum == static_cast<int>(LAST)) {
        return;
    }

    state = static_cast<BlockState >(++stateNum);
    StartParsing(n);
}

void RattleLang::ScopeParser::declare(const RattleLang::ASTAssignment *node, void *data) {
    // Currently if an assignment is type declared, then it means there's only 1 assignment

    if (node->typeDeclared) {
        std::string type_name = dynamic_cast<SimpleNode *>(node->jjtGetChild(1))->tokenValue;
        RattleLang::type varType = TypeStorage::get_instance()->get_type(type_name);

        if (varType.type_name != NONE) {
            //Declare the variable.
            std::string varName = dynamic_cast<SimpleNode *>(node->jjtGetChild(0))->tokenValue;
            cOut += type_name + " " + varName + ";";
            TypeInformation typeInfo({varType}, m_context);
            m_context->add_variable(type_name, typeInfo);
        } else {
            throw TypeException();
        }
    } else {
        int indexOfExpressions = get_index_of_expressions_in_assignment(node);
        int i = 0;
        int j = 0;

        ExpressionOp op(ExpressionOp::ASSIGNMENT, {});
        while (i < indexOfExpressions && (indexOfExpressions + j) < node->jjtGetNumChildren()) {

            std::vector<std::string> operators;
            int currentExpression = indexOfExpressions + j;

            // Made up of 1 or more expressions.
            ASTExpression *exp = dynamic_cast<ASTExpression *>(node->jjtGetChild(currentExpression));
            TypeInformation typeFound;
            declare(exp, &typeFound);

            if (typeFound.isEmpty()) {
                throw ParsingException("Variable Doesn't exist in this scope");
            }

            size_t typenamesSize = typeFound.typenames.size();
            m_expression_count[exp] = typenamesSize;

            for (int k = 0; k < typeFound.typenames.size() && i < indexOfExpressions; k++, i++) {
                std::string varName = get_token_of_child(node, i);
                TypeInformation varInfo = m_context->get_variable(varName);
                // The variable exists in a scope other than this one.
                if (!varInfo.isEmpty()) {
                    if (!m_exclusive_scope) {
                        continue;
                    }
                }

                // Find the subinformation
                if (m_context != varInfo.scope) {
                    TypeInformation declared_info;
                    if (indexOfExpressions == 1 && typenamesSize > 1) {
                        cOut += "std::tuple<";
                        for (int l = 0; l < typenamesSize; ++l) {
                            cOut += typeFound.typenames[l].get_corresponding_type_string() + ",";
                        }
                        cOut.pop_back();
                        cOut += ">";
                        declared_info = typeFound;

                    } else {
                        cOut += typeFound.typenames[k].get_corresponding_type_string();
                        declared_info = TypeInformation({typeFound.typenames[k]}, m_context);
                    }

                    m_context->add_variable(get_token_of_child(node, i), declared_info);
                    cOut +=  " " + varName + ";\n";
                }

            }
            ++j;
        }
    }
}

// Parse an Expression to find out it's type.
void RattleLang::ScopeParser::declare(const RattleLang::ASTExpression *node, void *data) {
    if (data) {
        TypeInformation *type = reinterpret_cast<RattleLang::TypeInformation *>(data);

        if (type) {
            *type = TypeInferer::get_instance()->StartParsing(node,m_context);
        }
    }
}

void RattleLang::ScopeParser::implement(const RattleLang::ASTExpression *node, void *data) {
    if (!node->isDone) {
        ExpressionOp op = data ? *(static_cast<ExpressionOp *>(data)) : ExpressionOp(ExpressionOp::ANONYMOUS, {});
        cOut += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, m_context), node);
    }
}

void RattleLang::ScopeParser::implement(const RattleLang::ASTAssignment *node, void *data) {
    int indexOfExpressions = get_index_of_expressions_in_assignment(node);
    int i = 0;
    int j = 0;

    while (i < indexOfExpressions && (indexOfExpressions + j) < node->jjtGetNumChildren()) {
        ExpressionOp op(ExpressionOp::ASSIGNMENT, {});
        std::vector<std::string> operators;
        int currentExpression = indexOfExpressions + j;

        // Made up of 1 or more expressions.
        ASTExpression *exp = dynamic_cast<ASTExpression *>(node->jjtGetChild(currentExpression));
        size_t count = m_expression_count[exp];
        for (int k = 0; k < count && i < indexOfExpressions; ++k, ++i) {
            op.parents.push_back(get_token_of_child(node, i));
        }
        implement(exp, &op);
        ++j;
    }
}

// Implement a while loop.
void RattleLang::ScopeParser::implement(const ASTWhileLoop *node, void *data) {
    ASTExpression *exp = static_cast<ASTExpression *>(node->jjtGetChild(0));
    TypeInformation booltype;
    declare(exp, &booltype);

    // Check we're a bool
    if (booltype.typenames[0].type_name == BOOLEAN) {
        cOut += "while(true)";
        cOut += SCOPE_OPEN;
        // Perform some kind of break logic.
        std::string unique_name = get_unique_name("while");
        ExpressionOp op(ExpressionOp::ASSIGNMENT, {unique_name});
        cOut += SCOPE_OPEN;

        cOut += "bool " + unique_name + ";\n";
        cOut += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, m_context), exp);
        cOut += "\nif (!" + unique_name + ") break;\n";
        cOut += SCOPE_CLOSE;

        // Then perform the inner statement.
        std::shared_ptr<Context> whileParserContext = std::make_shared<Context>(m_context);
        cOut += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(whileParserContext.get()),
                                                                           static_cast<ASTStatement *>(node->jjtGetChild(1)));
        cOut += SCOPE_CLOSE;
    };

}

// Implement a while loop.
void RattleLang::ScopeParser::implement(const ASTForLoop *node, void *data) {
    cOut += SCOPE_OPEN;
    ASTAssignment *assignment = static_cast<ASTAssignment *>(node->jjtGetChild(0));
    declare(assignment, data);
    implement(assignment, data);

    ASTExpression *exp = static_cast<ASTExpression *>(node->jjtGetChild(1));
    TypeInformation booltype;
    declare(exp, &booltype);

    // Check we're a bool
    if (booltype.typenames[0].type_name == BOOLEAN) {
        cOut += "while(true) {\n";

        // Perform some kind of break logic.
        std::string unique_name = get_unique_name("for");
        ExpressionOp op(ExpressionOp::ASSIGNMENT, {unique_name});
        cOut += SCOPE_OPEN;
        cOut += "bool " + unique_name + ";\n";

        cOut += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, m_context), exp);
        cOut += "\nif (!" + unique_name + ") break;\n";
        cOut += SCOPE_CLOSE;

        // Then perform the inner statement
        std::shared_ptr<Context> forParserContext = std::make_shared<Context>(m_context);
        cOut += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(forParserContext.get()),
                                                                           static_cast<ASTStatement *>(node->jjtGetChild(3)));


        ASTAssignment* innerAssingment = static_cast<ASTAssignment*>(node->jjtGetChild(2));
        declare(innerAssingment, data);
        implement(innerAssingment, data);

        cOut += SCOPE_CLOSE;
        cOut += SCOPE_CLOSE;
    };

}

void RattleLang::ScopeParser::implement(const RattleLang::ASTIfStatement *node, void *data) {
    // If statements consist of an expression and 1 or 2 statements
    ASTExpression *exp = static_cast<ASTExpression *>(node->jjtGetChild(0));
    TypeInformation booltype;
    declare(exp, &booltype);

    // Check we're a bool
    if (booltype.typenames[0].type_name == BOOLEAN) {
        std::string unique_name = get_unique_name("if");
        ExpressionOp op(ExpressionOp::ASSIGNMENT, {unique_name});
        cOut += SCOPE_OPEN;
        cOut += "bool " + unique_name + ";\n";
        cOut += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, m_context), exp);
        cOut += "\nif (" + unique_name + ")";
        cOut += SCOPE_OPEN;

        // Then perform the inner statement.
        std::shared_ptr<Context> ifParserContext = std::make_shared<Context>(m_context);
        cOut += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(ifParserContext.get()),
                                                                           static_cast<ASTStatement *>(node->jjtGetChild(1)));
        cOut += SCOPE_CLOSE;

        if (node->ifHasElse) {
            // do the same.
            cOut += "else ";
            cOut += SCOPE_OPEN;
            std::shared_ptr<Context> elseParserContext = std::make_shared<Context>(m_context);
            cOut += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(elseParserContext.get()),
                                                                               static_cast<ASTStatement *>(node->jjtGetChild(2)));
            cOut += SCOPE_CLOSE;
        }
        cOut += SCOPE_CLOSE;
    };


}

void RattleLang::ScopeParser::implement(const RattleLang::ASTFnInvoke *node, void *data) {
    ASTExpression *exp = new ASTExpression(0);
    exp->jjtAddChild((Node *) node, 0);

    ExpressionOp op(ExpressionOp::ANONYMOUS, {});
    cOut += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, m_context), exp);
    delete exp;
}

// Get the print Statement
void RattleLang::ScopeParser::implement(const RattleLang::ASTWrite *node, void *data) {
    ASTExpression *exp = static_cast<ASTExpression *>(node->jjtGetChild(0));
    TypeInformation typeinfo;
    declare(exp, &typeinfo);

    // We should only have one type.
    if (typeinfo.typenames.size() > 1) {
        throw TypeException();
    };

    std::string unique_name = get_unique_name("print");
    ExpressionOp op(ExpressionOp::ASSIGNMENT, {unique_name});
    cOut += SCOPE_OPEN;
    cOut += typeinfo.typenames[0].get_corresponding_type_string() + " " + unique_name + ";\n";
    cOut += StateMachineParserDecorator<ExpressionParser>::GetParserResults(ExpressionParser(op, m_context), exp);
    cOut += "cout << " + unique_name + "<< endl;";
    cOut += SCOPE_CLOSE;

}
