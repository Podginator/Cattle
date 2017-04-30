//
// Created by podgi on 4/29/2017.
//

#ifndef RATTLE_CPP_LAMBDATYPEINFORMATION_H
#define RATTLE_CPP_LAMBDATYPEINFORMATION_H


#include "TypeInformation.h"

namespace RattleLang {
    class LambdaTypeInformation : public TypeInformation {
    public:

        LambdaTypeInformation() : TypeInformation(){}

        // The Constructor, takes a variable amount of types.
        LambdaTypeInformation(std::initializer_list<RattleLang::type> types, Context* context = nullptr)
                : TypeInformation(types, context){}


        std::string get_c_return_types() override {
            std::string res = "std::function<" + this->get_c_typename() + "(";
            size_t param_size = inner_vars.size();

            if (inner_vars.size() > 0){
                for (const auto &param : inner_vars) {
                    res += param.second->get_c_typename() + ",";
                }
                res.pop_back();
            }

            res += ")>";

            return res;
        }

    };
}


#endif //RATTLE_CPP_LAMBDATYPEINFORMATION_H
