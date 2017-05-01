#include "ExpressionOp.h"

ExpressionOp::ExpressionOp(ExpressionOp::ExpressionParent parentType, std::vector<std::string> parentVec) :
        parent(parentType), parents(parentVec)
{}

