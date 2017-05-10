#include "TypeInferer.h"
#include "../TypeInformation/TypeStorage.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ParsingException.h"
#include "FunctionBuilder.h"
#include "../TypeInformation/LambdaTypeInformation.h"

using namespace RattleLang;

TypeInferer* TypeInferer::instance;

TypeInferer::TypeInferer(){}

TypeInfoPtr TypeInferer::StartParsing(const ASTExpression *node, Context* context) {
    // Then do all the leaf nodes.
    m_context = context;
    size_t numChildren = node->jjtGetNumChildren();
    TypeInfoPtr ret(new TypeInformation({}, m_context));

    if (m_typemap.find(node) != m_typemap.end()) {
        return m_typemap[node];
    }

    if (dynamic_cast<ASTFnInvoke*>(node->jjtGetChild(0))) {
        return  m_context->get_function(get_token_of_child((SimpleNode*)node->jjtGetChild(0), 0));
    }

    for (int i = 0; i < numChildren; ++i) {
        SimpleNode* childNode = (SimpleNode*) node->jjtGetChild(i);
        childNode->jjtAccept(this, &ret);
    }

    m_typemap[node] = ret;
    return ret;
}



void TypeInferer::visit(const ASTOr *node, void *data) {
    do_operand(node, OR_OP, data);
}

void TypeInferer::visit(const ASTAnd *node, void *data) {
    do_operand(node, AND_OP, data);
}

void TypeInferer::visit(const ASTCompEqual *node, void *data) {
    do_operand(node, EQ_OP, data);
}

void TypeInferer::visit(const ASTCompNequal *node, void *data) {
    do_operand(node, EQ_OP, data);
}

void TypeInferer::visit(const ASTCompGTE *node, void *data) {
    do_operand(node, GTE_OP, data);
}

void TypeInferer::visit(const ASTCompLTE *node, void *data) {
    do_operand(node, LTE_OP, data);
}

void TypeInferer::visit(const ASTCompGT *node, void *data) {
    do_operand(node, GTE_OP, data);
}

void TypeInferer::visit(const ASTCompLT *node, void *data) {
    do_operand(node, LTE_OP, data);
}

void TypeInferer::visit(const ASTAdd *node, void *data) {
    do_operand(node, ADD_OP, data);
}

void TypeInferer::visit(const ASTSubtract *node, void *data) {
    do_operand(node, SUB_OP, data);
}

void TypeInferer::visit(const ASTTimes *node, void *data) {
    do_operand(node, MUL_OP, data);
}

void TypeInferer::visit(const ASTDivide *node, void *data) {
    do_operand(node, DIV_OP, data);
}

void TypeInferer::visit(const ASTUnaryNot *node, void *data) {
    type *nodeType = ((type *) data);

    TypeInfoPtr type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1->typenames[0].defined_operations & NOT_OP) {
        *nodeType = type1->typenames[0];
    }


    throw TypeException(get_line_num(node));

}

void TypeInferer::visit(const ASTUnaryPlus *node, void *data) {
    type *nodeType = ((type *) data);

    TypeInfoPtr type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1->typenames[0].defined_operations & UN_PLUS_OP) {
        *nodeType = type1->typenames[0];
    }


    throw TypeException(get_line_num(node));

}

void TypeInferer::visit(const ASTUnaryMinus *node, void *data) {
    type *nodeType = ((type *) data);

    TypeInfoPtr type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));

    if (type1->typenames[0].defined_operations & UN_MIN_OP) {
        *nodeType = type1->typenames[0];
    }


    throw TypeException(get_line_num(node));

}

void TypeInferer::visit(const ASTExpression *node, void *data) {
    TypeInfoPtr* nodeType = (TypeInfoPtr*) data;

    *nodeType = TypeInfoPtr(StartParsing(node, m_context));
}

void TypeInferer::visit(const ASTFnInvoke *node, void *data) {
    TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(data);
    *typeInformation = TypeInfoPtr(m_context->get_function(get_token_of_child(node, 0)));
}

void TypeInferer::visit(const ASTMethodInvoke *node, void *data) {
    RattleDefaultVisitor::visit(node, data);
}

void TypeInferer::visit(const ASTIdentifier *node, void *data) {
   TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(data);
    *typeInformation = m_context->get_variable(node->tokenValue);
}

void TypeInferer::visit(const ASTMemIdentifier *node, void *data) {
    //TODO
}

void TypeInferer::visit(const ASTCharacter *node, void *data) {
   TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(data);
    (*typeInformation)->typenames.push_back(type(CHARACTER, CHAR));
}

void TypeInferer::visit(const ASTString *node, void *data) {
    TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(data);
    (*typeInformation)->typenames.push_back(type(STRING, STR));
}

void TypeInferer::visit(const ASTNumber *node, void *data) {
    TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(data);
    (*typeInformation)->typenames.push_back(type(NUMBER, NUM));
}

void TypeInferer::visit(const ASTTrue *node, void *data) {
    TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(data);
    (*typeInformation)->typenames.push_back(type(BOOLEAN, BOOL));
}

void TypeInferer::visit(const ASTFalse *node, void *data) {
    TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(data);
    (*typeInformation)->typenames.push_back(type(BOOLEAN, BOOL));
}

void TypeInferer::defaultVisit(const SimpleNode *node, void *data) {
    // Do nothing.
}

TypeInfoPtr TypeInferer::getTypeFromNode(const SimpleNode *node) {
    TypeInfoPtr nodeType(new TypeInformation());
    node->jjtAccept(this, &nodeType);
    return nodeType;
}

TypeInfoPtr TypeInferer::getTypeFromOperation(const SimpleNode *node,
                                                                                  operands operand) {
    TypeInfoPtr type1 = getTypeFromNode((SimpleNode*) node->jjtGetChild(0));
    TypeInfoPtr type2 = getTypeFromNode((SimpleNode*) node->jjtGetChild(1));

    if (!type1 || !type2) {
        throw ParsingException("Variable does not exist", get_line_num(node));
    }

    bool multi_types = type1->typenames.size() > 1 || type2->typenames.size() > 1;
    if (multi_types) {
        // If we are multiple we want to return a big ole tuple.
        if (operand == ADD_OP  && !is_lambda_operation(type1, type2)) {


            vector<type> type_combo = type1->typenames;
            for(const auto& typers : type2->typenames) {
                type_combo.push_back(typers);
            }

            TypeInfoPtr tuple_info =  TypeInfoPtr(new TypeInformation(type_combo, m_context));
            tuple_info->source = TUPLE;

            return tuple_info;
        }
    }

    if (operand == ADD_OP  && is_lambda_operation(type1, type2)) {
        TypeInfoPtr lambda_info = TypeInfoPtr(new LambdaTypeInformation({}, m_context));
        lambda_info->typenames = type2->typenames;
        lambda_info->inner_vars = type1->inner_vars;

        return lambda_info;
    }

    if (multi_types) {
        throw ParsingException("Cannot perform operations on multiple types", get_line_num(node));
    }

    type ret_type = TypeStorage::get_instance()->get_return_type_from_operation(
                                                         type1->typenames[0], type2->typenames[0], operand);

    return TypeInfoPtr(new TypeInformation({ret_type}, m_context));
}

bool TypeInferer::is_lambda_operation(TypeInfoPtr type1, TypeInfoPtr type2) {
    return (dynamic_pointer_cast<LambdaTypeInformation>(type1) && dynamic_pointer_cast<LambdaTypeInformation>(type2));
}


void TypeInferer::visit(const ASTDereference *node, void *data) {
    node->jjtGetChild(0)->jjtAccept(this, data);
}

void TypeInferer::visit(const ASTIndexedExpression *node, void *data) {
    ASTNumber* number = static_cast<ASTNumber*>(node->jjtGetChild(1));
    ASTExpression* exp = new ASTExpression(0);
    exp->jjtAddChild((Node*)node->jjtGetChild(0), 0);

    TypeInfoPtr IndexType = StartParsing(exp, m_context);

    if (TypeInformation::is_empty(IndexType)) {
        throw TypeException(get_line_num(node));
    }

    size_t typeSize = IndexType->typenames.size();
    bool onlyDigits = (number->tokenValue.find_first_not_of( "0123456789" ) == std::string::npos);
    if (!onlyDigits) {
        throw ParsingException("Index may only be positive integer values", get_line_num(node));
    }
    int value = atoi(number->tokenValue.c_str());

    // If there's only one value, or
    if (typeSize == 1 || typeSize < (value + 1) || IndexType->is_empty()) {
        throw ParsingException("Index Out Of Range", get_line_num(node));
    }

    TypeInfoPtr* nodeType  = (TypeInfoPtr*) (data);
    (*nodeType)->typenames.push_back(IndexType->typenames[value]);
}

void TypeInferer::visit(const ASTTupleDefine *node, void *data) {
    size_t numChildren = node->jjtGetNumChildren();
    TypeInfoPtr* data_info = static_cast<TypeInfoPtr*>(data);

    for (int i = 0; i < numChildren; ++i) {
        ASTExpression* exp = dynamic_cast<ASTExpression*>(node->jjtGetChild(i));
        if (exp) {
            TypeInfoPtr info = TypeInfoPtr(new TypeInformation());
            this->visit(exp, &info);

            if (TypeInformation::is_empty(info)) {
                throw TypeException(get_line_num(node));
            }

            size_t returnedTypes = info->typenames.size();
            for (int j = 0; j < returnedTypes; ++j) {
                (*data_info)->typenames.push_back(info->typenames[j]);
            }

            info->source = TUPLE;

        }
    }
}

TypeInferer *TypeInferer::get_instance() {
    if (!instance) {
        instance = new TypeInferer();
    };

    return instance;
}

void
TypeInferer::do_operand(const SimpleNode *node, operands operand, void *info) {
    TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(info);
    (*typeInformation) = getTypeFromOperation(node, operand);
}


void TypeInferer::visit(const ASTLambdaDefine *node, void *data) {
    TypeInfoPtr* typeInformation = static_cast<TypeInfoPtr*>(data);
    ASTAssignment* ass = (ASTAssignment*)node->jjtGetParent()->jjtGetParent();
    FunctionBuilder builder(m_context);
    (*typeInformation) = builder.declare_function(node, get_token_of_child(ass, 0), true);
}

