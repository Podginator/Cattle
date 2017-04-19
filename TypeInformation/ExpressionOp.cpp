//
// Created by Thomas Rogers on 02/04/2017.
//

#include "ExpressionOp.h"

ExpressionOp::ExpressionOp(ExpressionOp::ExpressionParent parentType, std::vector<std::string> parentVec) :
        parent(parentType), parents(parentVec)
{}

std::string ExpressionOp::getCloseTag() {
    switch(parent) {
        case ASSIGNMENT:
            return ";";
        case FN_CALL:
            return ");";
        case ANONYMOUS:
            return "";
    }

    return "";
}
