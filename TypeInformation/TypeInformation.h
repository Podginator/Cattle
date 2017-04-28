#ifndef TYPEINFO_H
#define TYPEINFO_H

#include <vector>
#include <map>
#include <initializer_list>
#include <string>
#include "type.h"
#include "Context.h"


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

    class TypeInformation {
    public:
        TypeInformation();

        // The Constructor, takes a variable amount of types.
        TypeInformation(std::initializer_list<RattleLang::type> types, Context* context = nullptr);

        // The vector of typenames. 
        std::vector<RattleLang::type> typenames;

        // This is for a class instance - a class can have many inner vars, and even some inner classes. 
        // This allows us to have inner classes and infer their types. 
        std::map<std::string, TypeInformation> inner_vars;

        // Return the number of returned items. 
        size_t num_return();

        void set_scope(Context* context);

        bool isEmpty();

        std::string get_typenames() {
            size_t numReturned = num_return();
            if (numReturned == 1) {
                return typenames[0].get_corresponding_type_string();
            }

            std::string ret = "std::tuple<";

            for (int i = 0; i < numReturned; ++i) {
                ret += typenames[i].get_corresponding_type_string() + ",";
            }
            ret.pop_back();
            ret += ">";

            return ret;
        }

        Context* scope;

    };

}

#endif