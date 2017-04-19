//
// Created by podgi on 4/12/2017.
//

#ifndef RATTLE_CPP_PARSINGEXCEPTION_H
#define RATTLE_CPP_PARSINGEXCEPTION_H

#include <exception>

namespace RattleLang {
    class ParameterException : public std::exception{
    public:
        ParameterException () {
            m_what = "Too few / too many parameters";
        }

        const char * what () const throw () {
            return m_what;
        }

    private:
        const char* m_what;
    };
}


#endif //RATTLE_CPP_PARSINGEXCEPTION_H
