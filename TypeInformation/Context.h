#ifndef RATTLE_CPP_CONTEXT_H
#define RATTLE_CPP_CONTEXT_H

#include <string>
#include <memory>
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

        void add_variable(const std::string& name, std::shared_ptr<RattleLang::TypeInformation> info);

        void add_class(const std::string& name, std::shared_ptr<RattleLang::TypeInformation> info);

        void add_function(const std::string& name, std::shared_ptr<RattleLang::TypeInformation> info);

        std::shared_ptr<RattleLang::TypeInformation> get_variable(const std::string& name);

        std::shared_ptr<RattleLang::TypeInformation> get_class_definition(const std::string& name);

        std::shared_ptr<RattleLang::TypeInformation> get_function(const std::string& name);



    private:
        std::map<std::string, std::shared_ptr<RattleLang::TypeInformation>> m_variables;

        std::map<std::string, std::shared_ptr<RattleLang::TypeInformation>> m_classInformation;

        std::map<std::string, std::shared_ptr<RattleLang::TypeInformation>> m_functionInformation;

        Context* parent;
    };
}


#endif //RATTLE_CPP_CONTEXT_H
