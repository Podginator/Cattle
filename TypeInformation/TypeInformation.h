#ifndef TYPEINFO_H
#define TYPEINFO_H

#include <vector>
#include <map>
#include <initializer_list>
#include <string>
#include <unordered_map>
#include "type.h"
#include "Context.h"
#include "../misc/StringHelper.h"


namespace RattleLang {
    // primitives:
    //  number  1101111111
    //  char    0001110001
    //  string  0001110001
    //  boolean 0011000000

    // Can also store functions and classes
    // Classes and functions will have inner vars.
    // This won't work for blocks, though, and maybe that's important...

    class Context;
    class TypeInformation;
    typedef std::shared_ptr<TypeInformation> TypeInfoPtr;
    typedef std::pair<std::string, TypeInfoPtr> NamedVariableInfo;


    class TypeInformation {
    public:


        TypeInformation();

        // The Constructor, takes a variable amount of types.
        TypeInformation(std::initializer_list<RattleLang::type> types, Context* context = nullptr);

        // The vector of typenames. 
        std::vector<RattleLang::type> typenames;

        // This is for a class instance - a class can have many inner vars, and even some inner classes. 
        // This allows us to have inner classes and infer their types. 
        std::vector<NamedVariableInfo> inner_vars;

        // Return the number of returned items. 
        size_t num_return();

        void set_scope(Context* context);

        bool is_empty();

        bool is_void();

        std::string get_c_typename();

        Context* scope;

        // Functions return a type name.
        virtual std::string get_c_return_types();

        virtual std::string get_rattle_typename();

        static bool is_empty(TypeInfoPtr ptr) {
            return !ptr || ptr->is_empty();
        }

    };




}

#endif