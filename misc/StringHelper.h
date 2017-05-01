//
// Created by Thomas Rogers on 30/04/2017.
//

#ifndef RATTLE_CPP_STRINGHELPER_H
#define RATTLE_CPP_STRINGHELPER_H


#include <string>

class StringHelper {
public:
    template <typename Iterator>
    static std::string combine_str( Iterator iteratable, const char token) {
        std::string retVal = "";

        for(auto it= iteratable.begin(); it < iteratable.end(); it++) {
           retVal.append((*it) + token);
        }
        retVal.pop_back();

        return retVal;
    }


    template <typename Iterator, class Function>
    static std::string combine_str( Iterator iteratable, const char token,  Function f) {
        std::string retVal = "";

        for(auto it= iteratable.begin(); it < iteratable.end(); it++) {
            retVal.append(((*it).*f)() + token);
        }
        retVal.pop_back();

        return retVal;
    }

    template <typename Iterator, typename Member, typename Function>
    static std::string combine_str_ptr( Iterator iteratable, const char token,  Member m, Function f = nullptr) {
        std::string retVal = "";

        for(auto it = iteratable.begin(); it < iteratable.end(); it++) {
            auto iterated = *it;
            auto iterated_member = iterated.*m;
            retVal.append(f ? ((*iterated_member).*f)() + token : "");
        }
        retVal.pop_back();

        return retVal;
    }


};


#endif //RATTLE_CPP_STRINGHELPER_H
