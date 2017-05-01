#ifndef RATTLE_CPP_PARSINGEXCEPTION_H
#define RATTLE_CPP_PARSINGEXCEPTION_H

#include <exception>
#include <cstring>

namespace RattleLang {
    class ParsingException : public std::exception{
    public:

        ParsingException (const std::string& err, int line) {
            m_what = err;
            m_what.append(" at line: " + std::to_string(line));

        }

        const char * what () const throw () {
            return m_what.c_str();
        }

        ~ParsingException() {
        }

    private:
        std::string m_what;
    };
}


#endif //RATTLE_CPP_PARSINGEXCEPTION_H
