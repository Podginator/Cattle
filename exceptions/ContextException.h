#ifndef RATTLE_CPP_CONTEXTEXCEPTION_H
#define RATTLE_CPP_CONTEXTEXCEPTION_H

#include <exception>

namespace RattleLang {
    class ContextException : public std::exception{
    public:
        ContextException (const char* err) {
            m_what = err;
        }

        const char * what () const throw () {
            return m_what;
        }

    private:
        const char* m_what;
    };
}


#endif //RATTLE_CPP_CONTEXTEXCEPTION_H
