//
// Created by Thomas Rogers on 07/04/2017.
//

#ifndef RATTLE_CPP_TYPE_H
#define RATTLE_CPP_TYPE_H

// Some structures designed to make type_inference easier.

#include <string>
#include <map>


#define BOOLEAN "boolean"
#define CHARACTER "char"
#define STRING "string"
#define NUMBER "number"
#define NONE "none"
#define VOID "void"

namespace RattleLang {

    struct type;


    enum operands {
        ADD_OP = 1,
        SUB_OP = 1 << 1,
        MUL_OP = 1 << 2,
        DIV_OP = 1 << 3,
        LTE_OP = 1 << 4,
        GTE_OP = 1 << 5,
        EQ_OP = 1 << 6,
        NOT_OP = 1 << 7,
        OR_OP  = 1 << 8,
        AND_OP = 1 << 9,
        UN_MIN_OP = 1 << 10,
        UN_PLUS_OP = 1 << 11,
        ALL = ADD_OP | SUB_OP | MUL_OP | DIV_OP | LTE_OP | GTE_OP | EQ_OP | NOT_OP | UN_MIN_OP | UN_PLUS_OP | AND_OP | OR_OP
    };

    enum primitives {
        BOOL = EQ_OP|NOT_OP|AND_OP|OR_OP,
        STR = ADD_OP|LTE_OP|GTE_OP|EQ_OP,
        CHAR = ADD_OP|SUB_OP|LTE_OP|GTE_OP|EQ_OP,
        NUM = ADD_OP|SUB_OP|MUL_OP|DIV_OP|LTE_OP|GTE_OP|EQ_OP|UN_MIN_OP|UN_PLUS_OP
    };


    typedef uint16_t operation_types;

    typedef std::pair<type, type> paired_combination;


    struct type {
        type(std::string name, uint16_t operands = 0)
                : defined_operations(operands), type_name(name)
        {}

        type() : defined_operations(0), type_name(NONE) {}

        bool operator<(const type &rhs) const {
            return type_name < rhs.type_name;
        }

        bool operator>(const type &rhs) const {
            return rhs < *this;
        }

        bool operator==(const type &rhs) const {
            return type_name == rhs.type_name;
        }

        bool operator!=(const type &rhs) const {
            return !(rhs == *this);
        }

        bool operator<=(const type &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(const type &rhs) const {
            return !(*this < rhs);
        }

        // where 0000000001 would indicate an add is possible on this type.
        // and   0000000011 would indicate that add and subtract are possible
        // etc etc.
        operation_types defined_operations;

        std::string type_name;

        std::string get_type_name() {
            return type_name;
        }

        std::string get_corresponding_type_string() {
            return type::corresponding_type_string(type_name);
        }

        static std::string corresponding_type_string(std::string type_name) {
            if (type_name == NUMBER) return "double";
            if (type_name == BOOLEAN) return "bool";
            if (type_name == STRING) return "std::string";
            if (type_name == CHARACTER) return "char";

            return type_name;
        }
    };
}


#endif //RATTLE_CPP_TYPE_H
