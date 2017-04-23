//
// Created by Thomas Rogers on 07/04/2017.
//

#include "TypeInferer.h"
#include "../TypeInformation/TypeStorage.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"

RattleLang::TypeInferer* RattleLang::TypeInferer::instance;

RattleLang::TypeInferer::TypeInferer()
        : retType(NONE, 0){}

RattleLang::TypeInformation RattleLang::TypeInferer::StartParsing(const RattleLang::ASTExpression *node, Context* context) {
    // Then do all the leaf nodes.
    m_context = context;
    size_t numChildren = node->jjtGetNumChildren();
    TypeInformation ret({}, m_context);

    if (m_typemap.find(node) != m_typemap.end()) {
        return m_typemap[node];
    }


    if (dynamic_cast<ASTFnInvoke*>(node->jjtGetChild(0))) {
        return  m_context->get_function(get_token_of_child((SimpleNode*)node->jjtGetChild(0) ,0));
    }

    for (int i = 0; i < numChildren; ++i) {
        SimpleNode* childNode = (SimpleNode*) node->jjtGetChild(i);
        childNode->jjtAccept(this, &ret);
    }

    m_typemap[node] = ret;
    return ret;
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTOr *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, OR_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTAnd *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, AND_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTCompEqual *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, EQ_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTCompNequal *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, EQ_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTCompGTE *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, GTE_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTCompLTE *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, LTE_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTCompGT *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, GTE_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTCompLT *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, LTE_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTAdd *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, ADD_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTSubtract *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, SUB_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTTimes *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, MUL_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTDivide *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    RattleLang::type nodeType = getTypeFromOperation(node, DIV_OP);
    typeInformation->typenames.push_back(nodeType);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTUnaryNot *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::TypeInformation type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.typenames[0].defined_operations & NOT_OP) {
        *nodeType = type1.typenames[0];
    }


    throw TypeException();

}

void RattleLang::TypeInferer::visit(const RattleLang::ASTUnaryPlus *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::TypeInformation type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.typenames[0].defined_operations & UN_PLUS_OP) {
        *nodeType = type1.typenames[0];
    }


    throw TypeException();
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTUnaryMinus *node, void *data) {
    RattleLang::type *nodeType = ((RattleLang::type *) data);

    RattleLang::TypeInformation type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1.typenames[0].defined_operations & UN_MIN_OP) {
        *nodeType = type1.typenames[0];
    }


    throw TypeException();
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTExpression *node, void *data) {
    RattleLang::TypeInformation *nodeType = ((RattleLang::TypeInformation *) data);

    *nodeType = StartParsing(node, m_context);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTFnInvoke *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    *typeInformation = m_context->get_function(get_token_of_child(node, 0));
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTMethodInvoke *node, void *data) {
    RattleDefaultVisitor::visit(node, data);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTIdentifier *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    *typeInformation = m_context->get_variable(node->tokenValue);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTMemIdentifier *node, void *data) {
    //TODO
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTCharacter *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(CHARACTER, CHAR));
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTString *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(STRING, STR));
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTNumber *node, void *data) {

    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(NUMBER, NUM));
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTTrue *node, void *data) {

    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(BOOLEAN, BOOL));
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTFalse *node, void *data) {
    RattleLang::TypeInformation* typeInformation = static_cast<TypeInformation*>(data);
    typeInformation->typenames.push_back(type(BOOLEAN, BOOL));
}

void RattleLang::TypeInferer::defaultVisit(const RattleLang::SimpleNode *node, void *data) {
    // Do nothing.
}

RattleLang::TypeInformation RattleLang::TypeInferer::getTypeFromNode(const RattleLang::SimpleNode *node) {
    RattleLang::TypeInformation nodeType;
    node->jjtAccept(this, &nodeType);
    return nodeType;
}

RattleLang::type RattleLang::TypeInferer::getTypeFromOperation(const RattleLang::SimpleNode *node,
                                                                                  RattleLang::operands operand) {
    RattleLang::TypeInformation type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));
    RattleLang::TypeInformation type2 = getTypeFromNode((SimpleNode*) node->jjtGetChild(1));

    if (type1.typenames.size() > 1 || type2.typenames.size() > 1) {
        throw ParsingException("Operation cannot be performed on multiple types");
    }

    return TypeStorage::get_instance()->get_return_type_from_operation(type1.typenames[0], type2.typenames[0], operand);
}
void RattleLang::TypeInferer::visit(const RattleLang::ASTDereference *node, void *data) {
    node->jjtGetChild(0)->jjtAccept(this, data);
}

void RattleLang::TypeInferer::visit(const RattleLang::ASTIndexedExpression *node, void *data) {
    ASTNumber* number = static_cast<ASTNumber*>(node->jjtGetChild(1));
    ASTExpression* exp = new ASTExpression(0);
    exp->jjtAddChild((Node*)node->jjtGetChild(0), 0);

    TypeInformation IndexType = StartParsing(exp, m_context);
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

void RattleLang::TypeInferer::visit(const RattleLang::ASTTupleDefine *node, void *data) {
    size_t numChildren = node->jjtGetNumChildren();
    TypeInformation* data_info = static_cast<TypeInformation*>(data);

    for (int i = 0; i < numChildren; ++i) {
        ASTExpression* exp = dynamic_cast<ASTExpression*>(node->jjtGetChild(i));
        if (exp) {
            TypeInformation info;
            this->visit(exp, &info);
            size_t returnedTypes = info.typenames.size();

            for (int j = 0; j < returnedTypes; ++j) {
                data_info->typenames.push_back(info.typenames[j]);
            }

        }
    }
}

RattleLang::TypeInferer *RattleLang::TypeInferer::get_instance() {
    if (!instance) {
        instance = new TypeInferer();
    };

    return instance;
}