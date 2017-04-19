//
// Created by Thomas Rogers on 03/04/2017.
//

#include <iostream>
#include "ExpressionParser.h"
#include "../exceptions/TypeException.h"
#include "ExpressionTypeInferenceVisitor.h"
#include "../exceptions/ParameterException.h"

void RattleLang::ExpressionParser::StartParsing(const SimpleNode* n) {
    isMultiAssign = isMultiAssignment(n);

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
        AppendToResult(node->tokenValue);
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
    TypeInformation type_info = m_context->get_function(name);
    std::vector<RattleLang::type> types = type_info.typenames;

    if (type_info.isEmpty()) {
        throw TypeException();
    }

    std::string fnCall = name+"(";
    std::string uniqueName = get_unique_name(name);
    m_fnCallName[node] = uniqueName;
    if (types[0].type_name != VOID) {
        returnedExpressions.back().append(
                "std::tuple<"
        );

        for (const RattleLang::type &i : types) {
            AppendToResult(i.get_corresponding_type_string() + ",");
        }
        returnedExpressions.back().pop_back();
        AppendToResult("> " + uniqueName + ";\n");
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
    if (m_context->get_function(name).typenames[0].type_name != VOID) {
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
    PrintNode(node);
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
    ChildAccept(n, 0);
    AppendToResult(expression);
    ChildAccept(n, 1);
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
    int expectedParams = m_context->get_function(static_cast<SimpleNode*>(node->jjtGetParent()->jjtGetChild(0))->tokenValue).inner_vars.size();
    int totalParams = 0;

    std::string functionName = m_fnCallName[(SimpleNode*)node->jjtGetParent()];
    ExpressionTypeInferenceVisitor typeInferenceVisitor(m_context);

    if (nodeNum > 0) {
        size_t paramNum = 0;
        for (size_t i = 0; i < nodeNum; ++i) {
            ASTExpression* exp = static_cast<ASTExpression*>(node->jjtGetChild(i));
            TypeInformation info = typeInferenceVisitor.StartParsing(exp);
            if (info.isEmpty()) {
                throw TypeException();
            }

            std::vector<std::string> param_names;
            size_t resultSize= info.typenames.size();
            for (int j = 0; j < resultSize; ++j, ++paramNum) {
                param_names.push_back(functionName + "param" + std::to_string(paramNum));
                AppendToResult(info.typenames[j].get_corresponding_type_string() + " " + functionName + "param" + std::to_string(paramNum) + ";\n");
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
    int nodeNum = m_context->get_function(static_cast<SimpleNode*>(node->jjtGetParent()->jjtGetChild(0))->tokenValue).inner_vars.size();

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

    ChildrenAccept(node, data);
}