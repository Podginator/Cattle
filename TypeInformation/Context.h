//
// Created by Thomas Rogers on 12/04/2017.
//

#ifndef RATTLE_CPP_CONTEXT_H
#define RATTLE_CPP_CONTEXT_H

#include <string>
#include "TypeInformation.h"


namespace RattleLang {


    class TypeInformation;

    // A context is the means to which we model scope.
    class Context {

    public:
        // The global scope.
        static Context global_scope;

        Context();

        Context(Context* parent);

        void add_variable(const std::string& name, const RattleLang::TypeInformation& info);

        void add_class(const std::string& name, const RattleLang::TypeInformation& info);

        void add_function(const std::string& name, const RattleLang::TypeInformation& info);

        TypeInformation get_variable(const std::string& name);

        TypeInformation get_class_definition(const std::string& name);

        TypeInformation get_function(const std::string& name);



    private:
        std::map<std::string, RattleLang::TypeInformation> m_variables;

        std::map<std::string, RattleLang::TypeInformation> m_classInformation;

        std::map<std::string, RattleLang::TypeInformation> m_functionInformation;

        Context* parent;
    };
}


#endif //RATTLE_CPP_CONTEXT_H
