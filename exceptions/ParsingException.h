//
// Created by podgi on 4/12/2017.
//

#ifndef RATTLE_CPP_PARSINGEXCEPTION_H
#define RATTLE_CPP_PARSINGEXCEPTION_H

#include <exception>
#include <cstring>

namespace RattleLang {
    class ParsingException : public std::exception{
    public:
        ParsingException (const char* err) {
            strcpy(m_what, err);
        }

        ParsingException (const std::string& err) {
            strcpy(m_what, err.c_str());
        }

        const char * what () const throw () {
            return m_what;
        }

        ~ParsingException() {
        }

    private:
        char m_what[256];
    };
}


#endif //RATTLE_CPP_PARSINGEXCEPTION_H
