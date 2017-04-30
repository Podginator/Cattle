//
// Created by podgi on 4/12/2017.
//

#ifndef RATTLE_CPP_PARSINGEXCEPTION_H
#define RATTLE_CPP_PARSINGEXCEPTION_H

#include <exception>

namespace RattleLang {
    class ParameterException : public std::exception{
    public:
        ParameterException (int line) {
            m_what = "Incorrect number of parameters at line: " + std::to_string(line);
        }

        const char * what () const throw () {
            return m_what.c_str();
        }

    private:
        std::string m_what;
    };
}


#endif //RATTLE_CPP_PARSINGEXCEPTION_H
