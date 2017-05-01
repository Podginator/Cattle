//
// Created by podgi on 4/12/2017.
//
#include <iostream>
#include "MainParser.h"
#include "ScopeParser.h"

#include "../exceptions/TypeException.h"
#include "FunctionBuilder.h"

using namespace RattleLang;


MainParser::MainParser(ASTCode *code) {
    codeNode = code;
    cOutput = create_preample();
    context = &Context::global_scope;
}

std::string MainParser::get_c_output() {
    return cOutput;
}


void MainParser::StartParsing(const SimpleNode *node) {
    create_preample();
    node->childrenAccept(this, nullptr);
    cOutput += "\n// Main \n";
    cOutput += "int main(int argc, char **argv) ";
    cOutput += SCOPE_OPEN;
    cOutput += StateMachineParserDecorator<ScopeParser>::GetParserResults(ScopeParser(&Context::global_scope), codeNode);
    cOutput += SCOPE_CLOSE;

    std::cout<<cOutput<<std::endl;
}

void MainParser::defaultVisit(const SimpleNode *node, void *data) {
    // Do nothing.
}

void MainParser::visit(const ASTClassDef *node, void *data) {
    std::string className = get_token_of_child(node, 0);
    cOutput += "class " + className;

    if (node->polymorphic) {
        cOutput += " : ";
        size_t amtOfChildren = node->jjtGetNumChildren();
        for (int i = 1; i < amtOfChildren ; ++i) {

            if (!dynamic_cast<ASTIdentifier*>(node->jjtGetChild(i))) {
                break;
            }

            auto subclass_name = get_token_of_child(node, i);
            TypeInfoPtr subclass_info = context->get_class_definition(subclass_name );
            if (subclass_info && !subclass_info->isEmpty()) {
                cOutput += " public " + get_token_of_child(node, i) + ",";
            } else {
                throw TypeException(get_line_num(node));
            }
        }
        // Remove last ","
        cOutput.pop_back();
    }
    type class_type = type(className, EQ_OP);
    TypeInfoPtr class_information(new TypeInformation({class_type}, context));
    TypeStorage::get_instance()->add_type(class_type);
    context->add_class(className, class_information);
    cOutput += ";\n";
}

std::string MainParser::create_preample() {
    return  "#include <fstream>\n"
            "#include <iomanip>\n"
            "#include <iostream>\n"
            "#include <functional>\n"
            "#include <tuple>\n"
            "#include <string>\n"
            "using namespace std;\n";
}

void MainParser::visit(const ASTAssignment *node, void *data) {
    cOutput += StateMachineParserDecorator<ScopeParser>::GetParserSingleNodeResult(ScopeParser(&Context::global_scope),
                                                                                   node);
}

void MainParser::visit(const ASTFnDef *node, void *data) {
    FunctionBuilder builder(context);
    builder.StartParsing(node, get_token_of_child(node, 0));
    cOutput.append(builder.get_c_output());
}

void MainParser::visit(const ASTStatement *node, void *data) {
    node->childrenAccept(this, nullptr);
}

