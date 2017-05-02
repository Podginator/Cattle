#ifndef RATTLE_CPP_LAMBDATYPEINFORMATION_H
#define RATTLE_CPP_LAMBDATYPEINFORMATION_H


#include "TypeInformation.h"

namespace RattleLang {
    class LambdaTypeInformation : public TypeInformation {
    public:

        LambdaTypeInformation();

        // The Constructor, takes a variable amount of types.
        LambdaTypeInformation(std::initializer_list<RattleLang::type> types, Context* context = nullptr);

        std::string get_c_return_types() override;

    };
}


#endif //RATTLE_CPP_LAMBDATYPEINFORMATION_H
