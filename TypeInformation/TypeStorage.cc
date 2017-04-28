#include "TypeStorage.h"
#include "../exceptions/ContextException.h"

RattleLang::TypeStorage* RattleLang::TypeStorage::s_instance = 0;


/**
 *     enum operands {
        ADD = 1,
        SUB = 1 << 1,
        MUL = 1 << 2,
        DIV = 1 << 3,
        LTE = 1 << 4,
        GTE = 1 << 5,
        EQ = 1 << 6,
        NOT = 1 << 7,
        OR  = 1 << 8,
        AND = 1 << 9,
        UN_MIN = 1 << 10,
        UN_PLUS = 1 << 11,
        ALL = ADD | SUB | MUL | DIV | LTE | GTE | EQ | NOT | UN_MIN | UN_PLUS | AND | OR
    };
 */
RattleLang::TypeStorage::TypeStorage(){
    type number(NUMBER, NUM);
    m_types[NUMBER] = number;

    type boolean(BOOLEAN, BOOL);
    m_types[BOOLEAN] = boolean;

    type character(CHARACTER, CHAR);
    m_types[CHARACTER] = character;

    type string(STRING, STR);
    m_types[STRING] = string;


    // Define the operations
    m_definedOperations[ADD_OP][std::make_pair(character, number)] = character;
    m_definedOperations[ADD_OP][std::make_pair(number,character)] = character;
    m_definedOperations[ADD_OP][std::make_pair(character, string)] = string;
    m_definedOperations[ADD_OP][std::make_pair(string, character)] = string;
    m_definedOperations[ADD_OP][std::make_pair(string, number)] = string;
    m_definedOperations[ADD_OP][std::make_pair(number, string)] = string;
    m_definedOperations[ADD_OP][std::make_pair(character, character)] = string;
    m_definedOperations[SUB_OP][std::make_pair(character, number)] = character;
    m_definedOperations[SUB_OP][std::make_pair(number,character)] = character;


}

RattleLang::TypeStorage* RattleLang::TypeStorage::get_instance() {
    if (!s_instance) {
        s_instance = new TypeStorage();
    }

    return s_instance; 
}


RattleLang::type
RattleLang::TypeStorage::get_return_type_from_operation(const type &type1, const type &type2, operands operand)
{
    bool isApplicable = (type1.defined_operations & operand) & type2.defined_operations;


    if (isApplicable) {
        auto pair = std::make_pair(type1, type2);
        if (m_definedOperations[operand].find(pair) != m_definedOperations[operand].end()) {
            return m_definedOperations[operand][pair];
        }

        pair = std::make_pair(type2, type1);
        if (m_definedOperations[operand].find(pair) != m_definedOperations[operand].end()) {
            return m_definedOperations[operand][pair];
        }

        // If they're the same type then just return the same type back
        if (type1 == type2) {

            if ((operand & (BOOL | GTE_OP | LTE_OP)) > 0) {
                return type(BOOLEAN, BOOL);
            }

            return type1;
        }
    }

    // Return null otherwise.
    return RattleLang::type(NONE, 0);
}

// Add a type.
void RattleLang::TypeStorage::add_type(RattleLang::type type) {
    m_types[type.type_name] = type;
}


// Return a type if it exists, otherwise return NONE
RattleLang::type RattleLang::TypeStorage::get_type(const std::string &name) {

    if (m_types.find(name) != m_types.end()) {
        return m_types[name];
    }


    return RattleLang::type();
}

RattleLang::Context RattleLang::TypeStorage::get_context_from_node(const RattleLang::SimpleNode *key) {
    return RattleLang::Context();
}

void RattleLang::TypeStorage::add_context_to_node(RattleLang::SimpleNode* key, RattleLang::Context *context) {
    if (m_contexts.find(key) == m_contexts.end()) {
        m_contexts[key] = context;
        return;
    }

    throw ContextException("Context already exists for this node");
}
