//
// Created by podgi on 4/12/2017.
//

#ifndef RATTLE_CPP_PARSINGEXCEPTION_H
#define RATTLE_CPP_PARSINGEXCEPTION_H

#include <exception>

namespace RattleLang {
    class ParsingException : public std::exception{
    public:
        ParsingException (const char* err) {
            m_what = err;
        }

        const char * what () const throw () {
            return m_what;
        }

    private:
        const char* m_what;
    };
}


#endif //RATTLE_CPP_PARSINGEXCEPTION_H
