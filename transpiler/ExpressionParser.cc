//
// Created by Thomas Rogers on 03/04/2017.
//

#include <iostream>
#include "ExpressionParser.h"
#include "../exceptions/TypeException.h"
#include "TypeInferer.h"
#include "../exceptions/ParameterException.h"
#include "FunctionBuilder.h"
#include "../TypeInformation/LambdaTypeInformation.h"

void RattleLang::ExpressionParser::StartParsing(const SimpleNode* n) {
    isMultiAssign = isMultiAssignment(n);
    expectedOutput = TypeInferer::get_instance()->StartParsing(static_cast<const ASTExpression*>(n), m_context);

    // Do an initial pass for this, ensuring that we first elaborate on any functions.
    ChildrenAccept(n);
    res.append(returnedExpressions[0]);

    // Do the expression pass
    state = EXPRESSION_PASS;
    DoEachExpression(n);
    const_cast<SimpleNode*>(n)->isDone = true;
    for (int i = 1; i < returnedExpressions.size(); i++) {
        if (parent.parents.size() > i-1) {
            res.append(parent.parents[i - 1] + " = ");
        }
        res.append(returnedExpressions[i] + ";\n");
    }

    if (hasFnCalls) {
        res.append(SCOPE_CLOSE);
    }
}

void RattleLang::ExpressionParser::visit_fnPass(const RattleLang::ASTTupleDefine *node, void *data) {

}

void RattleLang::ExpressionParser::defaultVisit(const RattleLang::SimpleNode *node, void *data) {
    // Do nothing.
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTOr *node, void *data) {
    doExpression(node, "||");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTAnd *node, void *data) {
    doExpression(node, "&&");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTCompEqual *node, void *data) {
    doExpression(node, "==");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTCompNequal *node, void *data) {
    doExpression(node, "!=");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTCompGTE *node, void *data) {
    doExpression(node, ">=");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTCompLTE *node, void *data) {
    doExpression(node, "<=");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTCompGT *node, void *data) {
    doExpression(node, ">");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTCompLT *node, void *data) {
    doExpression(node, "<");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTAdd *node, void *data) {
    doExpression(node, "+");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTSubtract *node, void *data) {
    doExpression(node, "-");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTTimes *node, void *data) {
    doExpression(node, "*");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTDivide *node, void *data) {
    doExpression(node, "/");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTUnaryNot *node, void *data) {
    AppendToResult("!");
    ChildAccept(node, 0, data);
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTUnaryPlus *node, void *data) {
    AppendToResult("+");
    ChildAccept(node, 0, data);
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTUnaryMinus *node, void *data) {
    AppendToResult("-");
    ChildAccept(node, 0, data);
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTIdentifier *node, void *data) {
    if (data) {
        int val = *(static_cast<int *>(data));
        AppendToResult("std::get<" + std::to_string(val) + ">" + "(");
    }
    AppendToResult(node->tokenValue + (data ? ")" : ""));
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTDereference *node, void *data) {
    if (isMultiAssign) {
        std::string name(((SimpleNode *) node->jjtGetChild(0))->tokenValue);

        AppendToResult("std::get<" + std::to_string(0) + ">(" + name + ")");
        for (int i = 1; i < parent.parents.size(); i++) {
            std::string name(((SimpleNode *) node->jjtGetChild(0))->tokenValue);
            returnedExpressions.push_back("std::get<" + std::to_string(i) + ">(" + name + ")");
        }
    } else {
        ChildAccept(node, 0, data);
    }
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTExpression *node, void *data) {

    returnedExpressions.back() += "(";
    ChildrenAccept(node, data);
    returnedExpressions.back() += ")";
    const_cast<ASTExpression*>(node)->isDone = true;
}

void RattleLang::ExpressionParser::visit_fnPass(const RattleLang::ASTExpression *node, void* data) {
    ChildrenAccept(node, data);
    const_cast<ASTExpression*>(node)->isDone = true;
}

void RattleLang::ExpressionParser::visit_fnPass(const RattleLang::ASTFnInvoke *node, void *data) {

    std::string name = ((SimpleNode *) (node->jjtGetChild(0)))->tokenValue;
    const_cast<ASTFnInvoke *>(node)->isDone = true;

    if (!hasFnCalls) {
        AppendToResult(SCOPE_OPEN);
        hasFnCalls = true;
    }

    // Get the function name.
    // Check how many return values there are.
    // Unnecessary unless we're doing a multi assign.
    std::shared_ptr<TypeInformation> type_info = m_context->get_function(name);


    if (!type_info) {
        // Check if a lambda exists with this.
        type_info = std::dynamic_pointer_cast<LambdaTypeInformation>(m_context->get_variable(name));
    }


    if (!type_info || type_info->isEmpty()) {
        throw TypeException();
    }

    std::vector<RattleLang::type> types = type_info->typenames;
    std::string fnCall = name+"(";
    std::string uniqueName = get_unique_name(name);
    m_fnCallName[node] = uniqueName;

    if (types[0].type_name != VOID) {
        AppendToResult(type_info->get_typenames() + " " + uniqueName + ";\n");
        fnCall.insert(0, "\n" + uniqueName + "=");
    }

    ChildAccept(node, 1, data);

    AppendToResult(fnCall);
    state = EXPRESSION_PASS;
    ChildAccept(node, 1, data);
    state = FN_PASS;
    AppendToResult(");\n");


}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTFnInvoke *node, void *data) {
    std::string name = ((SimpleNode *) (node->jjtGetChild(0)))->tokenValue;
    int startIndex = data ? *((int*)data) : 0;




    if (m_context->get_function(name)->typenames[0].type_name != VOID) {
        if (!isMultiAssign && !data) {
            AppendToResult(m_fnCallName[node]);
            return;
        }

        AppendToResult("std::get<" + std::to_string(startIndex) + ">(" + m_fnCallName[node] + ")");
        if (returnedExpressions.size() - 1 != parent.parents.size()) {
            for (int i = 1; i < parent.parents.size(); i++) {
                std::string multi(
                        "std::get<" + std::to_string(i) + ">(" + m_fnCallName[node] + ")");

                if (!data) {
                    returnedExpressions.push_back(multi);
                } else {
                    AppendToResult(multi);
                }
            }
        }
    }


}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTCharacter *node, void *data) {
    PrintNode(node);
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTString *node, void *data) {
    AppendToResult("std::string(");
    PrintNode(node);
    AppendToResult(")");
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTNumber *node, void *data) {
    PrintNode(node);
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTTrue *node, void *data) {
    PrintNode(node);
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTFalse *node, void *data) {
    PrintNode(node);
}

void RattleLang::ExpressionParser::PrintNode(const RattleLang::SimpleNode *node) {
    AppendToResult(node->tokenValue);
}

void RattleLang::ExpressionParser::doExpression(const RattleLang::SimpleNode *n, const std::string &expression) {
    std::string preample = NeedsConverting(const_cast<SimpleNode*>(n)) ? "std::to_string(" : "";
    AppendToResult(preample);
    ConvertIfNeeded((SimpleNode*) n->jjtGetChild(0));
    AppendToResult(expression);
    ConvertIfNeeded((SimpleNode*) n->jjtGetChild(1));
}

void RattleLang::ExpressionParser::ConvertIfNeeded(RattleLang::SimpleNode *node) {
    if (NeedsConverting(node)) {
        AppendToResult("std::to_string(");
        Accept(node, nullptr);
        AppendToResult(")");
    } else {
        Accept(node, nullptr);
    }
}

bool RattleLang::ExpressionParser::NeedsConverting(SimpleNode* node) {
    ASTExpression* exp = new ASTExpression(0);
    exp->jjtAddChild(node,0);
    std::shared_ptr<TypeInformation> expression_info = TypeInferer::get_instance()->StartParsing(exp, m_context);
    return (expectedOutput->num_return() == 1 && expectedOutput->typenames[0].type_name == STRING) &&
    (expression_info->num_return() == 1 && expression_info->typenames[0].type_name == NUMBER);
}



bool RattleLang::ExpressionParser::isMultiAssignment(const SimpleNode *exp) {
    if (parent.parents.size() == 1) { return false; }

    bool typeCorrect = dynamic_cast<const ASTFnInvoke*>(exp->jjtGetChild(0))
                       || dynamic_cast<const ASTDereference*>(exp->jjtGetChild(0));
    // Otherwise check whether exp immediate children are of the correct type.
    return typeCorrect;
}

void RattleLang::ExpressionParser::visit_fnPass(const RattleLang::ASTArgList *node, void *data) {

    // If we've pass
    int nodeNum = node->jjtGetNumChildren();
    int expectedParams = m_context->get_function(static_cast<SimpleNode*>(node->jjtGetParent()->jjtGetChild(0))->tokenValue)->inner_vars.size();
    int totalParams = 0;

    std::string functionName = m_fnCallName[(SimpleNode*)node->jjtGetParent()];
    if (nodeNum > 0) {
        size_t paramNum = 0;
        for (size_t i = 0; i < nodeNum; ++i) {
            ASTExpression* exp = static_cast<ASTExpression*>(node->jjtGetChild(i));
            std::shared_ptr<TypeInformation> info = TypeInferer::get_instance()->StartParsing(exp, m_context);
            if (!info || info->isEmpty()) {
                throw TypeException();
            }

            std::vector<std::string> param_names;
            size_t resultSize= info->typenames.size();
            for (int j = 0; j < resultSize; ++j, ++paramNum) {
                param_names.push_back(functionName + "param" + std::to_string(paramNum));
                AppendToResult(info->typenames[j].get_corresponding_type_string() + " " + functionName + "param" + std::to_string(paramNum) + ";\n");
                totalParams++;
            }

            AppendToResult(StateMachineParserDecorator<ExpressionParser>::GetParserResults(
                    ExpressionParser(ExpressionOp(ExpressionOp::ASSIGNMENT, param_names), m_context), exp));
        }

        if (totalParams != expectedParams) {
            throw ParameterException();
        }
        returnedExpressions.back().pop_back();
    }


}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTArgList *node, void *data) {
    std::string functionName = m_fnCallName[(SimpleNode*)node->jjtGetParent()];
    int nodeNum = m_context->get_function(static_cast<SimpleNode*>(node->jjtGetParent()->jjtGetChild(0))->tokenValue)->inner_vars.size();

    if (nodeNum > 0) {
        for (size_t i = 0; i < nodeNum; ++i) {
            AppendToResult(functionName + "param" + std::to_string(i));
            AppendToResult(",");
        }
        returnedExpressions.back().pop_back();
    }
}

void RattleLang::ExpressionParser::AppendToResult(const std::string &res) {
    returnedExpressions.back().append(res);
}

void RattleLang::ExpressionParser::DoEachExpression(const RattleLang::SimpleNode *node) {
    size_t childrenSize = node->jjtGetNumChildren();
    for (size_t i = 0; i < childrenSize; ++i) {
        returnedExpressions.push_back("");
        node->jjtGetChild(i)->jjtAccept(ref, nullptr);
    }
}

// Pass down the expected index for the function return.
void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTIndexedExpression *node, void *data) {
    ASTNumber* number = static_cast<ASTNumber*>(node->jjtGetChild(1));
    int value = atoi(number->tokenValue.c_str());
    ChildAccept(node, 0 ,&value);
}

void RattleLang::ExpressionParser::visit_fnPass(const RattleLang::ASTIndexedExpression *node, void *data) {
    ChildAccept(node, 0 ,data);
}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTTupleDefine *node, void *data) {
    size_t nodeSize = node->jjtGetNumChildren();
    std::vector<std::string> allNames;
    res.append(SCOPE_OPEN);

    for (int i = 0; i < nodeSize; ++i) {
        ASTExpression* exp = static_cast<ASTExpression*>(node->jjtGetChild(i));
        std::shared_ptr<TypeInformation> info = TypeInferer::get_instance()->StartParsing(exp, m_context);
        std::vector<std::string> names;
        size_t internalSize = info->num_return();
        for (int j = 0; j < internalSize; ++j) {
            std::string unName = get_unique_name("tuple_assign");
            res.append(info->typenames[j].get_corresponding_type_string() + " " + unName + ";\n");
            names.push_back(unName);
            allNames.push_back(unName);
        }

        res.append(StateMachineParserDecorator<ExpressionParser>::GetParserResults(
                ExpressionParser(ExpressionOp(ExpressionOp::ASSIGNMENT, names), m_context), exp));
    }

    AppendToResult("std::make_tuple(");
    for (const auto name : allNames) {
        AppendToResult(name + ",");
    }
    returnedExpressions.back().pop_back();
    AppendToResult(");");

    AppendToResult(SCOPE_CLOSE);

}

void RattleLang::ExpressionParser::visit_expressionPass(const RattleLang::ASTLabmdaDefine *node, void *data) {
    FunctionBuilder builder(m_context);
    SimpleNode* parent = static_cast<SimpleNode*>(node->jjtGetParent()->jjtGetParent());
    builder.StartParsing(node, get_token_of_child(parent, 0));
    AppendToResult(builder.get_c_output());
}
