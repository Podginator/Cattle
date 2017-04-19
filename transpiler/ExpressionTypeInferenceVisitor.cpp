//
// Created by Thomas Rogers on 07/04/2017.
//

#include "ExpressionTypeInferenceVisitor.h"
#include "../TypeInformation/TypeStorage.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"

RattleLang::ExpressionTypeInferenceVisitor::ExpressionTypeInferenceVisitor(Context* context)
        : retType(NONE, 0), m_context(context) {}

RattleLang::TypeInformation RattleLang::ExpressionTypeInferenceVisitor::StartParsing(const RattleLang::ASTExpression *node) {
    // Then do all the leaf nodes.
    size_t numChildren = node->jjtGetNumChildren();
    TypeInformation ret;
    type type;

    if (dynamic_cast<ASTFnInvoke*>(node->jjtGetChild(0))) {
        return  m_context->get_function(get_token_of_child((SimpleNode*)node->jjtGetChild(0) ,0));
    }

    for (int i = 0; i < numChildren; ++i) {
        SimpleNode* childNode = (SimpleNode*) node->jjtGetChild(i);
        childNode->jjtAccept(this, &type);
    }

    ret = TypeInformation({type}, m_context);
    return ret;
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTOr *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, OR_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTAnd *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, AND_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompEqual *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, EQ_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompNequal *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, EQ_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompGTE *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, GTE_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompLTE *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, LTE_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompGT *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, GTE_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompLT *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, LTE_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTAdd *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, ADD_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTSubtract *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, SUB_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTTimes *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, MUL_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTDivide *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = getTypeFromOperation(node, DIV_OP);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTUnaryNot *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::type type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.defined_operations & NOT_OP) {
        *nodeType = type1;
    }


    throw TypeException();

}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTUnaryPlus *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::type type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.defined_operations & UN_PLUS_OP) {
        *nodeType = type1;
    }

    throw TypeException();
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTUnaryMinus *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::type type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.defined_operations & UN_MIN_OP) {
        *nodeType = type1;
    }

    throw TypeException();
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTExpression *node, void *data) {
    ExpressionTypeInferenceVisitor vis(m_context);
    RattleLang::TypeInformation *nodeType = ((RattleLang::TypeInformation *) data);

    *nodeType = vis.StartParsing(node);
}

// TODO
void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTFnInvoke *node, void *data) {
    RattleLang::type *nodeType = static_cast<type*>(data);
    if (nodeType) {
        TypeInformation info = m_context->get_function(get_token_of_child(node, 0));
        *nodeType = info.typenames[0];
    }
}

// TODO
void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTMethodInvoke *node, void *data) {
    RattleDefaultVisitor::visit(node, data);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTIdentifier *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    TypeInformation info = m_context->get_variable(node->tokenValue);
    *nodeType = info.typenames[0];

}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTMemIdentifier *node, void *data) {
    //TODO
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCharacter *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = type(CHARACTER, CHAR);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTString *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = type(STRING, STR);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTNumber *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);
    *nodeType = type(NUMBER, NUM);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTTrue *node, void *data) {
    RattleLang::type* nodeType  = ((RattleLang::type*) data);
    *nodeType = type(BOOLEAN, BOOL);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTFalse *node, void *data) {
    RattleLang::type* nodeType  = ((RattleLang::type*) data);
    *nodeType = type(BOOLEAN, BOOL);
}


void RattleLang::ExpressionTypeInferenceVisitor::defaultVisit(const RattleLang::SimpleNode *node, void *data) {
    // Do nothing.
}

RattleLang::type RattleLang::ExpressionTypeInferenceVisitor::getTypeFromNode(const RattleLang::SimpleNode *node) {
    RattleLang::type nodeType;
    node->jjtAccept(this, &nodeType);
    return nodeType;
}

RattleLang::type RattleLang::ExpressionTypeInferenceVisitor::getTypeFromOperation(const RattleLang::SimpleNode *node,
                                                                                  RattleLang::operands operand) {
    RattleLang::type type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));
    RattleLang::type type2 = getTypeFromNode((SimpleNode*) node->jjtGetChild(1));

    return TypeStorage::get_instance()->get_return_type_from_operation(type1, type2, operand);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTDereference *node, void *data) {
    node->jjtGetChild(0)->jjtAccept(this, data);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTIndexedExpression *node, void *data) {
    ASTNumber* number = static_cast<ASTNumber*>(node->jjtGetChild(1));
    ASTExpression* exp = new ASTExpression(0);
    exp->jjtAddChild((Node*)node->jjtGetChild(0), 0);

    TypeInformation IndexType = StartParsing(exp);

    bool onlyDigits = (number->tokenValue.find_first_not_of( "0123456789" ) == std::string::npos);
    if (!onlyDigits) {
        throw ParsingException("Index may only be positive integer values");
    }
    int value = atoi(number->tokenValue.c_str());

    // If there's only one value, or
    if (IndexType.typenames.size() < (value + 1) || IndexType.isEmpty()) {
        throw ParsingException("Index Out Of Range");
    }

    RattleLang::type* nodeType  = ((RattleLang::type*) data);
    *nodeType = IndexType.typenames[value];
}
