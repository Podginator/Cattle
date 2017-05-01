#include "TypeInformation.h"

RattleLang::TypeInformation::TypeInformation() {
    this->scope = nullptr;
}

RattleLang::TypeInformation::TypeInformation(std::initializer_list<RattleLang::type> names, Context* context)
{
    for (auto i : names) {
        typenames.push_back(i);
    }

    this->scope = context;

}

// Return the number of returned items.
size_t RattleLang::TypeInformation::num_return() {
    return typenames.size();
}

std::string RattleLang::TypeInformation::get_c_typename() {
    size_t numReturned = num_return();
    if (numReturned == 1) {
        return typenames[0].get_corresponding_type_string();
    }

    std::string ret = "std::tuple<";
    ret.append(StringHelper::combine_str(typenames, ',', &type::get_corresponding_type_string ));
    ret += ">";

    return ret;
}

void RattleLang::TypeInformation::set_scope(RattleLang::Context *context) {
    scope = context;
}

bool RattleLang::TypeInformation::isEmpty() {
    return (num_return() == 1 && typenames[0].type_name == NONE) || (num_return() == 0);
}
