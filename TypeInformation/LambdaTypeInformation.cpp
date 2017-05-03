#include "LambdaTypeInformation.h"

using namespace std;
using namespace RattleLang;


LambdaTypeInformation::LambdaTypeInformation() : TypeInformation(){}

// The Constructor, takes a variable amount of types.
LambdaTypeInformation::LambdaTypeInformation(std::initializer_list<RattleLang::type> types, Context* context)
: TypeInformation(types, context){}


string LambdaTypeInformation::get_c_return_types() {
    std::string res = "std::function<" + this->get_c_typename() + "(";
    if (inner_vars.size() > 0){
        res.append(StringHelper::combine_str_ptr(inner_vars, ',',
                                                 &NamedVariableInfo::second, &TypeInformation::get_c_typename));
    }
    res += ")>";
    return res;
}

