//
// Created by podgi on 4/12/2017.
//

#ifndef RATTLE_CPP_TYPEEXCEPTION_H
#define RATTLE_CPP_TYPEEXCEPTION_H


#include <exception>

namespace RattleLang {
    class TypeException : public std::exception{
        const char * what () const throw () {
            return "Type does not exist";
        }
    };
}


#endif //RATTLE_CPP_TYPEEXCEPTION_H