#include "TypeInformation.h"


using namespace RattleLang;
using namespace std;

TypeInformation::TypeInformation() {
    this->scope = nullptr;
}

TypeInformation::TypeInformation(initializer_list<type> names, Context* context)
{
    for (auto i : names) {
        typenames.push_back(i);
    }

    this->scope = context;

}

// Return the number of returned items.
size_t TypeInformation::num_return() {
    return typenames.size();
}

string TypeInformation::get_c_typename() {
    size_t numReturned = num_return();
    if (numReturned == 1) {
        return typenames[0].get_corresponding_type_string();
    }

    string ret = "tuple<";
    ret.append(StringHelper::combine_str(typenames, ',', &type::get_corresponding_type_string ));
    ret += ">";

    return ret;
}

void TypeInformation::set_scope(Context *context) {
    scope = context;
}

bool TypeInformation::is_empty() {
    return (num_return() == 1 && typenames[0].type_name == NONE) || (num_return() == 0);
}


// Functions return a type name.
string TypeInformation::get_c_return_types() {
    return get_c_typename();
}

string TypeInformation::get_rattle_typename() {
    size_t numReturned = num_return();
    if (numReturned == 1) {
        return typenames[0].type_name;
    }

    string ret = "[";
    ret += StringHelper::combine_str(typenames, ',', &type::get_type_name);
    ret += "]";

    return ret;
}

bool TypeInformation::is_void() {
    return typenames.size() == 1 && typenames[0].type_name == VOID;
}