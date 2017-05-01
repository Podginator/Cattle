#ifndef RATTLE_CPP_TYPEEXCEPTION_H
#define RATTLE_CPP_TYPEEXCEPTION_H


#include <exception>

namespace RattleLang {
    class TypeException : public std::exception{
    public:
        TypeException(int linenum) : m_line_num(linenum) {}

        const char * what () const throw () {
            return "Type does not exist " + m_line_num;
        }
    private:
        int m_line_num;
    };
}


#endif //RATTLE_CPP_TYPEEXCEPTION_H
