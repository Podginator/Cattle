#ifndef BASE_ASTNODE_H
#define BASE_ASTNODE_H

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>


namespace RattleLang {

class BaseASTNode {
public:
    // The name of the token.
    std::string tokenValue;
    // Does an if branch have a corresponding else branch
    bool ifHasElse = false;
    // Does the function have a return value?
    bool fnHasReturn = false;
    // Does the member have a default value. 
    bool memHasDefaultVal = false;
    // Is the class polymorphic
    bool polymorphic = false;
    // Is the member a variable.
    bool isObject = false;
    // Has this node already been done?
    bool typeDeclared = false;


    void setDone() {
        isDone = true;
    }

    bool isDone = false;
};


}

#endif