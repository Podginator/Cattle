//
// Created by Thomas Rogers on 02/04/2017.
//

#ifndef RATTLE_CPP_EXPRESSIONOP_H
#define RATTLE_CPP_EXPRESSIONOP_H


#include <vector>
#include <string>

// Simple struct to store information about what type of operation is being performed
// In an expression
struct ExpressionOp {

    enum ExpressionParent {
        FN_CALL,
        ANONYMOUS,
        ASSIGNMENT
    };

    ExpressionOp(const ExpressionOp &obj) {
        parents = obj.parents;
        parent = obj.parent;
    }


    ExpressionOp(ExpressionParent parent, std::vector<std::string> parents);

    std::vector<std::string> parents;

    ExpressionParent parent;

};


#endif //RATTLE_CPP_EXPRESSIONOP_H
