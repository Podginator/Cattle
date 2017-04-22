//
// Created by Thomas Rogers on 12/04/2017.
//

#include "Context.h"
#include "../exceptions/TypeException.h"
#include "../exceptions/ScopeException.h"

RattleLang::Context RattleLang::Context::global_scope;

RattleLang::Context::Context() {
    this->parent = nullptr;
}

RattleLang::Context::Context(RattleLang::Context *parent) {
    this->parent = parent;
}

void RattleLang::Context::add_variable(const std::string &name, const RattleLang::TypeInformation &info) {

    if (m_variables.find(name) == m_variables.end()) {
        this->m_variables[name] = info;
    } else {
        throw ScopeException("Variable Already Exists");
    }

}

//Todo: We cannot name an inner class the same as classes that exist in lower classes.
void RattleLang::Context::add_class(const std::string &name, const RattleLang::TypeInformation &info) {
    // This will check all scopes to see if a class has the same name, if it does we will throw an exception/
    if (get_class_definition(name).typenames[0].type_name == NONE) {
        this->m_classInformation[name] = info;
    } else {
        throw ScopeException("Class Already Exists");
    }
}

RattleLang::TypeInformation RattleLang::Context::get_variable(const std::string &name) {

    if (m_variables.find(name) != m_variables.end()) {
        return m_variables[name];
    }

    if (parent) {
        return parent->get_variable(name);
    }

    return TypeInformation();
}

RattleLang::TypeInformation RattleLang::Context::get_class_definition(const std::string &name) {
    if (m_classInformation.find(name) != m_classInformation.end()) {
        return m_classInformation[name];
    }

    if (parent) {
        return parent->get_class_definition(name);
    }

    return TypeInformation();
}

void RattleLang::Context::add_function(const std::string &name, const RattleLang::TypeInformation &info) {
    if (m_functionInformation.find(name) == m_functionInformation.end()) {
        this->m_functionInformation[name] = info;
    } else {
        throw TypeException();
    }

}

RattleLang::TypeInformation RattleLang::Context::get_function(const std::string &name) {
    if (m_functionInformation.find(name) != m_functionInformation.end()) {
        return m_functionInformation[name];
    }

    if (parent) {
        return parent->get_function(name);
    }

    return TypeInformation();
}
