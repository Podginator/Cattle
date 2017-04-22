//
// Created by Thomas Rogers on 22/04/2017.
//

#ifndef RATTLE_CPP_SCOPEEXCEPTION_H
#define RATTLE_CPP_SCOPEEXCEPTION_H


#include <exception>

namespace RattleLang {
    class ScopeException : public std::exception{
    public:
        ScopeException (const char* err) {
            m_what = err;
        }

        const char * what () const throw () {
            return m_what;
        }

    private:
        const char* m_what;
    };
}


#endif //RATTLE_CPP_SCOPEEXCEPTION_H
