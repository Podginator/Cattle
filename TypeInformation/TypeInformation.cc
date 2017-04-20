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

void RattleLang::TypeInformation::set_scope(RattleLang::Context *context) {
    this->scope = context;
}

bool RattleLang::TypeInformation::isEmpty() {
    return (num_return() == 1 && typenames[0].type_name == "none") || (num_return() == 0);
}
