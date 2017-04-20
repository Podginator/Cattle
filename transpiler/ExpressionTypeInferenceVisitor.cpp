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
    TypeInformation ret({}, m_context);

    if (dynamic_cast<ASTFnInvoke*>(node->jjtGetChild(0))) {
        return  m_context->get_function(get_token_of_child((SimpleNode*)node->jjtGetChild(0) ,0));
    }

    for (int i = 0; i < numChildren; ++i) {
        SimpleNode* childNode = (SimpleNode*) node->jjtGetChild(i);
        childNode->jjtAccept(this, &ret);
    }

    return ret;
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTOr *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, OR_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTAnd *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, AND_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompEqual *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, EQ_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompNequal *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, EQ_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompGTE *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, GTE_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompLTE *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, LTE_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompGT *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, GTE_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCompLT *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, LTE_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTAdd *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, ADD_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTSubtract *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, SUB_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTTimes *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, MUL_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTDivide *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, DIV_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTUnaryNot *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::TypeInformation type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.typenames[0].defined_operations & NOT_OP) {
        *nodeType = type1.typenames[0];
    }


    throw TypeException();

}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTUnaryPlus *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::TypeInformation type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.typenames[0].defined_operations & UN_PLUS_OP) {
        *nodeType = type1.typenames[0];
    }


    throw TypeException();
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTUnaryMinus *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::TypeInformation type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.typenames[0].defined_operations & UN_MIN_OP) {
        *nodeType = type1.typenames[0];
    }


    throw TypeException();
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTExpression *node, void *data) {
    ExpressionTypeInferenceVisitor vis(m_context);
    RattleLang::TypeInformation *nodeType = ((RattleLang::TypeInformation *) data);

    *nodeType = vis.StartParsing(node);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTFnInvoke *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    *typeInformation = m_context->get_function(get_token_of_child(node, 0));
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTMethodInvoke *node, void *data) {
    RattleDefaultVisitor::visit(node, data);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTIdentifier *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    *typeInformation = m_context->get_variable(node->tokenValue);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTMemIdentifier *node, void *data) {
    //TODO
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTCharacter *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(CHARACTER, CHAR));
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTString *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(STRING, STR));
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTNumber *node, void *data) {

    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(NUMBER, NUM));
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTTrue *node, void *data) {

    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(BOOLEAN, BOOL));
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTFalse *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(BOOLEAN, BOOL));
}

void RattleLang::ExpressionTypeInferenceVisitor::defaultVisit(const RattleLang::SimpleNode *node, void *data) {
    // Do nothing.
}

RattleLang::TypeInformation RattleLang::ExpressionTypeInferenceVisitor::getTypeFromNode(const RattleLang::SimpleNode *node) {
    RattleLang::TypeInformation nodeType;
    node->jjtAccept(this, &nodeType);
    return nodeType;
}

RattleLang::type RattleLang::ExpressionTypeInferenceVisitor::getTypeFromOperation(const RattleLang::SimpleNode *node,
                                                                                  RattleLang::operands operand) {
    RattleLang::TypeInformation type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));
    RattleLang::TypeInformation type2 = getTypeFromNode((SimpleNode*) node->jjtGetChild(1));

    if (type1.typenames.size() > 1 || type2.typenames.size() > 2) {
        throw ParsingException("Operation cannot be performed on multiple types");
    }

    return TypeStorage::get_instance()->get_return_type_from_operation(type1.typenames[0], type2.typenames[0], operand);
}
void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTDereference *node, void *data) {
    node->jjtGetChild(0)->jjtAccept(this, data);
}

void RattleLang::ExpressionTypeInferenceVisitor::visit(const RattleLang::ASTIndexedExpression *node, void *data) {
    ASTNumber* number = static_cast<ASTNumber*>(node->jjtGetChild(1));
    ASTExpression* exp = new ASTExpression(0);
    exp->jjtAddChild((Node*)node->jjtGetChild(0), 0);

    TypeInformation IndexType = StartParsing(exp);
    size_t typeSize = IndexType.typenames.size();

    bool onlyDigits = (number->tokenValue.find_first_not_of( "0123456789" ) == std::string::npos);
    if (!onlyDigits) {
        throw ParsingException("Index may only be positive integer values");
    }
    int value = atoi(number->tokenValue.c_str());

    // If there's only one value, or
    if (typeSize == 1 || typeSize < (value + 1) || IndexType.isEmpty()) {
        throw ParsingException("Index Out Of Range");
    }

    RattleLang::TypeInformation* nodeType  = ((RattleLang::TypeInformation*) data);
    nodeType->typenames.push_back(IndexType.typenames[value]);
}
