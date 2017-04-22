//
// Created by Thomas Rogers on 02/04/2017.
//

#include "ExpressionOp.h"

ExpressionOp::ExpressionOp(ExpressionOp::ExpressionParent parentType, std::vector<std::string> parentVec) :
        parent(parentType), parents(parentVec)
{}

