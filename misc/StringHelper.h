//
// Created by Thomas Rogers on 30/04/2017.
//

#ifndef RATTLE_CPP_STRINGHELPER_H
#define RATTLE_CPP_STRINGHELPER_H


#include <string>

class StringHelper {
public:
    template <typename Iterator>
    static std::string combine_str( Iterator begin, Iterator end, const char token ) {
        std::string retVal = "";

        for(Iterator it= begin; it < end; it++) {
           retVal.append((*it) + token);
        }
        retVal.pop_back();

        return retVal;
    }
};


#endif //RATTLE_CPP_STRINGHELPER_H
