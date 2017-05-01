#ifndef TYPESINGLE_H
#define TYPESINGLE_H

#include "TypeInformation.h"
#include "type.h"
#include "../gen/SimpleNode.h"
#include <map>
#include <set>
#include <unordered_map>
#include "Context.h"

namespace RattleLang {

    // Stores information about different types and stores different scopes.
    class TypeStorage
    {
    private:

        std::unordered_map<operands, std::map<RattleLang::paired_combination, RattleLang::type>, std::hash<int> > m_definedOperations;

        std::map<std::string, RattleLang::type> m_types;

        std::map<SimpleNode*, Context> m_contexts;

        static TypeStorage *s_instance;
        
        TypeStorage();

    public:

        static TypeStorage* get_instance();

        type get_return_type_from_operation(const type& type1, const type& type2, operands operand);

        void add_type(RattleLang::type type);

        RattleLang::type get_type(const std::string& name);

        Context get_context_from_node(const SimpleNode* key);

        void add_context_to_node(RattleLang::SimpleNode* key, RattleLang::Context *context);

    };

}

#endif