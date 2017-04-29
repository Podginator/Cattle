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


        std::string get_returntype() override {
            std::string res = "std::function<" + this->get_typenames() + "(";
            size_t param_size = inner_vars.size();

            for (const auto &param : inner_vars) {
                res += param.second->get_typenames() + ",";
            }
            res.pop_back();

            return res;
        }

    };
}


#endif //RATTLE_CPP_LAMBDATYPEINFORMATION_H
