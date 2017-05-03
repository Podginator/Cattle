/* Rattle.cc */
#include "Rattle.h"
#include "TokenMgrError.h"
#include "SimpleNode.h"
namespace RattleLang {
  unsigned int jj_la1_0[] = {
0x80183a00,0x183a00,0x80183a00,0x80000000,0x0,0x80000000,0x80000000,0x0,0x0,0x0,0x80180000,0x80180000,0x80183a00,0x0,0x0,0x200000,0x0,0x0,0x0,0x0,0x80000000,0x0,0x0,0x80000000,0x0,0x400,0x80000000,0x0,0x80000000,0x0,0x0,0x200000,0xe8070000,0x0,0x4000,0x8000,0x0,0x0,0x0,0x0,0x0,0x0,0x10000,0xe8060000,0x68060000,0x0,0x0,0x0,0x68060000,0x0,0x80000000,0x60000,};
  unsigned int jj_la1_1[] = {
0x10,0x10,0x10,0x0,0x200,0x0,0x0,0x200,0x200,0x0,0x0,0x0,0x10,0x200,0x80000000,0x0,0x200,0x2010,0x2010,0x80000000,0x0,0x200,0x80000000,0x0,0x200,0x0,0x0,0x200,0x0,0x0,0x0,0x0,0xc000054,0x200,0x0,0x0,0x7a0000,0x7a0000,0xc000000,0xc000000,0x30000000,0x30000000,0xc000000,0x54,0x0,0x14,0x200,0x0,0x0,0x0,0x0,0x0,};
  unsigned int jj_la1_2[] = {
0x0,0x0,0x0,0x1,0x0,0x1,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x4,0x8,0x0,0x0,0x0,0x0,0x0,0x10,0x10,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x8,0x0,0x8,0x0,0x0,};

  /** Constructor with user supplied TokenManager. */




ASTCode
       * Rattle::code() {/*@bgen(jjtree) Code */
  ASTCode *jjtn000 = new ASTCode(JJTCODE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      statement();
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case IF:
        case FOR:
        case WHILE:
        case PRINT:
        case FN:
        case CLASS:
        case IDENTIFIER:
        case LBRACE:{
          ;
          break;
          }
        default:
          jj_la1[0] = jj_gen;
          goto end_label_1;
        }
        statement();
      }
      end_label_1: ;
ASTEOF *jjtn001 = new ASTEOF(JJTEOF);
    bool jjtc001 = true;
    jjtree.openNodeScope(jjtn001);
    jjtn001->jjtSetFirstToken(getToken(1));
      try {
        jj_consume_token(0);
      } catch ( ...) {
if (jjtc001) {
      jjtree.clearNodeScope(jjtn001);
      jjtc001 = false;
    } else {
      jjtree.popNode();
    }
      }
if (jjtc001) {
      jjtree.closeNodeScope(jjtn001, true);
      jjtn001->jjtSetLastToken(getToken(0));
    }
jjtree.closeNodeScope(jjtn000, true);
    jjtc000 = false;
    jjtn000->jjtSetLastToken(getToken(0));
return jjtn000;
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
assert(false);
}


void Rattle::statement() {/*@bgen(jjtree) Statement */
  ASTStatement *jjtn000 = new ASTStatement(JJTSTATEMENT);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      if (jj_2_1(2147483647)) {
        assignment();
      } else {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case FN:{
          fndef();
          break;
          }
        case CLASS:{
          classdef();
          break;
          }
        case LBRACE:{
          block();
          break;
          }
        case IF:{
          ifstatement();
          break;
          }
        case FOR:{
          forloop();
          break;
          }
        case WHILE:{
          whileloop();
          break;
          }
        case PRINT:{
          write();
          break;
          }
        default:
          jj_la1[1] = jj_gen;
          if (jj_2_2(2)) {
            fn_invoke();
          } else if (jj_2_3(2147483647)) {
            method_invoke();
          } else {
            jj_consume_token(-1);
            errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
          }
        }
      }
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::block() {/*@bgen(jjtree) Block */
  ASTBlock *jjtn000 = new ASTBlock(JJTBLOCK);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(LBRACE);
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case IF:
        case FOR:
        case WHILE:
        case PRINT:
        case FN:
        case CLASS:
        case IDENTIFIER:
        case LBRACE:{
          ;
          break;
          }
        default:
          jj_la1[2] = jj_gen;
          goto end_label_2;
        }
        statement();
      }
      end_label_2: ;
      jj_consume_token(RBRACE);
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::parmlist() {/*@bgen(jjtree) Parmlist */
  ASTParmlist *jjtn000 = new ASTParmlist(JJTPARMLIST);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(LPAREN);
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case IDENTIFIER:{
        identifier();
        jj_consume_token(63);
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case IDENTIFIER:{
          identifier();
          break;
          }
        case 64:{
          LambdaPass();
          break;
          }
        default:
          jj_la1[3] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
        while (!hasError) {
          switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
          case COMMA:{
            ;
            break;
            }
          default:
            jj_la1[4] = jj_gen;
            goto end_label_3;
          }
          jj_consume_token(COMMA);
          identifier();
          jj_consume_token(63);
          switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
          case IDENTIFIER:{
            identifier();
            break;
            }
          case 64:{
            LambdaPass();
            break;
            }
          default:
            jj_la1[5] = jj_gen;
            jj_consume_token(-1);
            errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
          }
        }
        end_label_3: ;
        break;
        }
      default:
        jj_la1[6] = jj_gen;
        ;
      }
      jj_consume_token(RPAREN);
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::LambdaPass() {/*@bgen(jjtree) LambdaPass */
  ASTLambdaPass *jjtn000 = new ASTLambdaPass(JJTLAMBDAPASS);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(64);
      identifier();
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COMMA:{
          ;
          break;
          }
        default:
          jj_la1[7] = jj_gen;
          goto end_label_4;
        }
        jj_consume_token(COMMA);
        identifier();
      }
      end_label_4: ;
      jj_consume_token(GT);
ASTLambdaIds *jjtn001 = new ASTLambdaIds(JJTLAMBDAIDS);
          bool jjtc001 = true;
          jjtree.openNodeScope(jjtn001);
          jjtn001->jjtSetFirstToken(getToken(1));
      try {
        jj_consume_token(LPAREN);
        identifier();
        while (!hasError) {
          switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
          case COMMA:{
            ;
            break;
            }
          default:
            jj_la1[8] = jj_gen;
            goto end_label_5;
          }
          jj_consume_token(COMMA);
          identifier();
        }
        end_label_5: ;
        jj_consume_token(RPAREN);
      } catch ( ...) {
if (jjtc001) {
            jjtree.clearNodeScope(jjtn001);
            jjtc001 = false;
          } else {
            jjtree.popNode();
          }
      }
if (jjtc001) {
            jjtree.closeNodeScope(jjtn001, true);
            jjtn001->jjtSetLastToken(getToken(0));
          }
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::classdef() {/*@bgen(jjtree) ClassDef */
  ASTClassDef *jjtn000 = new ASTClassDef(JJTCLASSDEF);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(CLASS);
      identifier();
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case 65:{
        jj_consume_token(65);
        identifier();
jjtn000->polymorphic = true;
        break;
        }
      default:
        jj_la1[9] = jj_gen;
        ;
      }
      jj_consume_token(LBRACE);
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case FN:
        case CLASS:
        case IDENTIFIER:{
          ;
          break;
          }
        default:
          jj_la1[10] = jj_gen;
          goto end_label_6;
        }
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case CLASS:{
          classdef();
          break;
          }
        case IDENTIFIER:{
          member_declaration();
          break;
          }
        case FN:{
          fndef();
          break;
          }
        default:
          jj_la1[11] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
      }
      end_label_6: ;
      jj_consume_token(RBRACE);
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::fnbody() {/*@bgen(jjtree) FnBody */
  ASTFnBody *jjtn000 = new ASTFnBody(JJTFNBODY);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case IF:
        case FOR:
        case WHILE:
        case PRINT:
        case FN:
        case CLASS:
        case IDENTIFIER:
        case LBRACE:{
          ;
          break;
          }
        default:
          jj_la1[12] = jj_gen;
          goto end_label_7;
        }
        statement();
      }
      end_label_7: ;
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::fnTypeList() {/*@bgen(jjtree) FnTypeList */
  ASTFnTypeList *jjtn000 = new ASTFnTypeList(JJTFNTYPELIST);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(63);
      identifier();
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COMMA:{
          ;
          break;
          }
        default:
          jj_la1[13] = jj_gen;
          goto end_label_8;
        }
        jj_consume_token(COMMA);
        identifier();
      }
      end_label_8: ;
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::methoddef() {/*@bgen(jjtree) MethodDef */
  ASTMethodDef *jjtn000 = new ASTMethodDef(JJTMETHODDEF);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      fndef();
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::fndef() {/*@bgen(jjtree) FnDef */
  ASTFnDef *jjtn000 = new ASTFnDef(JJTFNDEF);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(FN);
      identifier();
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case 63:{
        fnTypeList();
        break;
        }
      default:
        jj_la1[14] = jj_gen;
        ;
      }
      parmlist();
      jj_consume_token(LBRACE);
      fnbody();
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case RETURN:{
        jj_consume_token(RETURN);
        returnexpr();
jjtn000->fnHasReturn = true;
        break;
        }
      default:
        jj_la1[15] = jj_gen;
        ;
      }
      jj_consume_token(RBRACE);
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::returnexpr() {/*@bgen(jjtree) ReturnExpression */
  ASTReturnExpression *jjtn000 = new ASTReturnExpression(JJTRETURNEXPRESSION);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      expression();
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COMMA:{
          ;
          break;
          }
        default:
          jj_la1[16] = jj_gen;
          goto end_label_9;
        }
        jj_consume_token(COMMA);
        expression();
      }
      end_label_9: ;
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::member_declaration() {/*@bgen(jjtree) #MemDeclaration( 2) */
  ASTMemDeclaration *jjtn000 = new ASTMemDeclaration(JJTMEMDECLARATION);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      identifier();
      jj_consume_token(63);
      identifier();
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case LBRACE:
      case ASSIGN:{
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case ASSIGN:{
          jj_consume_token(ASSIGN);
          expression();
          break;
          }
        case LBRACE:{
          obj_create();
jjtn000->memHasDefaultVal = true;
          break;
          }
        default:
          jj_la1[17] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
        break;
        }
      default:
        jj_la1[18] = jj_gen;
        ;
      }
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000,  2u);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::assignment() {/*@bgen(jjtree) Assignment */
  ASTAssignment *jjtn000 = new ASTAssignment(JJTASSIGNMENT);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      if (jj_2_4(2147483647)) {
        member_identifier();
jjtn000->isObject = true;
      } else {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case IDENTIFIER:{
          identifier();
          switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
          case 63:{
            jj_consume_token(63);
            identifier();
jjtn000->typeDeclared = true;
            break;
            }
          default:
            jj_la1[19] = jj_gen;
            ;
          }
          break;
          }
        default:
          jj_la1[20] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
      }
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COMMA:{
          ;
          break;
          }
        default:
          jj_la1[21] = jj_gen;
          goto end_label_10;
        }
        jj_consume_token(COMMA);
        if (jj_2_5(2147483647)) {
          member_identifier();
jjtn000->isObject = true;
        } else {
          switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
          case IDENTIFIER:{
            identifier();
            switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
            case 63:{
              jj_consume_token(63);
              identifier();
              break;
              }
            default:
              jj_la1[22] = jj_gen;
              ;
            }
            break;
            }
          default:
            jj_la1[23] = jj_gen;
            jj_consume_token(-1);
            errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
          }
        }
      }
      end_label_10: ;
      jj_consume_token(ASSIGN);
      expression();
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COMMA:{
          ;
          break;
          }
        default:
          jj_la1[24] = jj_gen;
          goto end_label_11;
        }
        jj_consume_token(COMMA);
        expression();
      }
      end_label_11: ;
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::ifstatement() {/*@bgen(jjtree) IfStatement */
  ASTIfStatement *jjtn000 = new ASTIfStatement(JJTIFSTATEMENT);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(IF);
      jj_consume_token(LPAREN);
      expression();
      jj_consume_token(RPAREN);
      statement();
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case ELSE:{
        jj_consume_token(ELSE);
        statement();
jjtn000->ifHasElse = true;
        break;
        }
      default:
        jj_la1[25] = jj_gen;
        ;
      }
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::obj_create() {/*@bgen(jjtree) ObjCreate */
  ASTObjCreate *jjtn000 = new ASTObjCreate(JJTOBJCREATE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(LBRACE);
      jj_consume_token(CREATE);
      identifier();
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case 66:{
        jj_consume_token(66);
        while (!hasError) {
          switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
          case IDENTIFIER:{
            ;
            break;
            }
          default:
            jj_la1[26] = jj_gen;
            goto end_label_12;
          }
          if (jj_2_6(2147483647)) {
            method_instantiate();
          } else {
            switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
            case IDENTIFIER:{
              member_instantiate();
              switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
              case COMMA:{
                jj_consume_token(COMMA);
                break;
                }
              default:
                jj_la1[27] = jj_gen;
                ;
              }
              break;
              }
            default:
              jj_la1[28] = jj_gen;
              jj_consume_token(-1);
              errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
            }
          }
        }
        end_label_12: ;
        break;
        }
      default:
        jj_la1[29] = jj_gen;
        ;
      }
      jj_consume_token(RBRACE);
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::member_instantiate() {/*@bgen(jjtree) MemInstantiate */
  ASTMemInstantiate *jjtn000 = new ASTMemInstantiate(JJTMEMINSTANTIATE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      identifier();
      jj_consume_token(ASSIGN);
      expression();
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::method_instantiate() {/*@bgen(jjtree) MethodInstantiate */
  ASTMethodInstantiate *jjtn000 = new ASTMethodInstantiate(JJTMETHODINSTANTIATE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      identifier();
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case 67:{
          ;
          break;
          }
        default:
          jj_la1[30] = jj_gen;
          goto end_label_13;
        }
        jj_consume_token(67);
        identifier();
jjtn000->isObject = true;
      }
      end_label_13: ;
      arglist();
    } catch ( ...) {
if (jjtc000) {
       jjtree.clearNodeScope(jjtn000);
       jjtc000 = false;
     } else {
       jjtree.popNode();
     }
    }
if (jjtc000) {
       jjtree.closeNodeScope(jjtn000, true);
       jjtn000->jjtSetLastToken(getToken(0));
     }
}


void Rattle::lambda_define() {/*@bgen(jjtree) LabmdaDefine */
  ASTLambdaDefine *jjtn000 = new ASTLambdaDefine(JJTLABMDADEFINE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      parmlist();
      fnTypeList();
      jj_consume_token(67);
      jj_consume_token(LBRACE);
      fnbody();
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case RETURN:{
        jj_consume_token(RETURN);
        returnexpr();
jjtn000->fnHasReturn = true;
        break;
        }
      default:
        jj_la1[31] = jj_gen;
        ;
      }
      jj_consume_token(RBRACE);
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::forloop() {/*@bgen(jjtree) ForLoop */
  ASTForLoop *jjtn000 = new ASTForLoop(JJTFORLOOP);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(FOR);
      jj_consume_token(LPAREN);
      assignment();
      jj_consume_token(SEMICOLON);
      expression();
      jj_consume_token(SEMICOLON);
      assignment();
      jj_consume_token(RPAREN);
      statement();
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::whileloop() {/*@bgen(jjtree) WhileLoop */
  ASTWhileLoop *jjtn000 = new ASTWhileLoop(JJTWHILELOOP);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(WHILE);
      jj_consume_token(LPAREN);
      expression();
      jj_consume_token(RPAREN);
      statement();
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::write() {
    jj_consume_token(PRINT);
ASTWrite *jjtn001 = new ASTWrite(JJTWRITE);
              bool jjtc001 = true;
              jjtree.openNodeScope(jjtn001);
              jjtn001->jjtSetFirstToken(getToken(1));
    try {
      expression();
    } catch ( ...) {
if (jjtc001) {
                jjtree.clearNodeScope(jjtn001);
                jjtc001 = false;
              } else {
                jjtree.popNode();
              }
    }
if (jjtc001) {
                jjtree.closeNodeScope(jjtn001,  1u);
                jjtn001->jjtSetLastToken(getToken(0));
              }
}


void Rattle::arglist() {/*@bgen(jjtree) ArgList */
  ASTArgList *jjtn000 = new ASTArgList(JJTARGLIST);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(LPAREN);
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case NOT:
      case TRUE:
      case FALSE:
      case FLOATING_POINT_LITERAL:
      case STRING_LITERAL:
      case CHARACTER_LITERAL:
      case IDENTIFIER:
      case LPAREN:
      case LBRACE:
      case LBRACKET:
      case PLUS:
      case SUBT:{
        expression();
        break;
        }
      default:
        jj_la1[32] = jj_gen;
        ;
      }
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COMMA:{
          ;
          break;
          }
        default:
          jj_la1[33] = jj_gen;
          goto end_label_14;
        }
        jj_consume_token(COMMA);
        expression();
      }
      end_label_14: ;
      jj_consume_token(RPAREN);
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::expression() {/*@bgen(jjtree) Expression */
  ASTExpression *jjtn000 = new ASTExpression(JJTEXPRESSION);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      or_expression();
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::or_expression() {
    and_expression();
    while (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case OR:{
        ;
        break;
        }
      default:
        jj_la1[34] = jj_gen;
        goto end_label_15;
      }
      jj_consume_token(OR);
ASTOr *jjtn001 = new ASTOr(JJTOR);
             bool jjtc001 = true;
             jjtree.openNodeScope(jjtn001);
             jjtn001->jjtSetFirstToken(getToken(1));
      try {
        and_expression();
      } catch ( ...) {
if (jjtc001) {
               jjtree.clearNodeScope(jjtn001);
               jjtc001 = false;
             } else {
               jjtree.popNode();
             }
      }
if (jjtc001) {
               jjtree.closeNodeScope(jjtn001,  2u);
               jjtn001->jjtSetLastToken(getToken(0));
             }
    }
    end_label_15: ;
}


void Rattle::and_expression() {
    compare_expression();
    while (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case AND:{
        ;
        break;
        }
      default:
        jj_la1[35] = jj_gen;
        goto end_label_16;
      }
      jj_consume_token(AND);
ASTAnd *jjtn001 = new ASTAnd(JJTAND);
              bool jjtc001 = true;
              jjtree.openNodeScope(jjtn001);
              jjtn001->jjtSetFirstToken(getToken(1));
      try {
        compare_expression();
      } catch ( ...) {
if (jjtc001) {
                jjtree.clearNodeScope(jjtn001);
                jjtc001 = false;
              } else {
                jjtree.popNode();
              }
      }
if (jjtc001) {
                jjtree.closeNodeScope(jjtn001,  2u);
                jjtn001->jjtSetLastToken(getToken(0));
              }
    }
    end_label_16: ;
}


void Rattle::compare_expression() {
    add_expression();
    switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
    case EQ:
    case GT:
    case LT:
    case LE:
    case GE:
    case 68:{
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case EQ:{
        jj_consume_token(EQ);
ASTCompEqual *jjtn001 = new ASTCompEqual(JJTCOMPEQUAL);
           bool jjtc001 = true;
           jjtree.openNodeScope(jjtn001);
           jjtn001->jjtSetFirstToken(getToken(1));
        try {
          add_expression();
        } catch ( ...) {
if (jjtc001) {
             jjtree.clearNodeScope(jjtn001);
             jjtc001 = false;
           } else {
             jjtree.popNode();
           }
        }
if (jjtc001) {
             jjtree.closeNodeScope(jjtn001,  2u);
             jjtn001->jjtSetLastToken(getToken(0));
           }
        break;
        }
      case 68:{
        jj_consume_token(68);
ASTCompNequal *jjtn002 = new ASTCompNequal(JJTCOMPNEQUAL);
         bool jjtc002 = true;
         jjtree.openNodeScope(jjtn002);
         jjtn002->jjtSetFirstToken(getToken(1));
        try {
          add_expression();
        } catch ( ...) {
if (jjtc002) {
           jjtree.clearNodeScope(jjtn002);
           jjtc002 = false;
         } else {
           jjtree.popNode();
         }
        }
if (jjtc002) {
           jjtree.closeNodeScope(jjtn002,  2u);
           jjtn002->jjtSetLastToken(getToken(0));
         }
        break;
        }
      case GE:{
        jj_consume_token(GE);
ASTCompGTE *jjtn003 = new ASTCompGTE(JJTCOMPGTE);
         bool jjtc003 = true;
         jjtree.openNodeScope(jjtn003);
         jjtn003->jjtSetFirstToken(getToken(1));
        try {
          add_expression();
        } catch ( ...) {
if (jjtc003) {
           jjtree.clearNodeScope(jjtn003);
           jjtc003 = false;
         } else {
           jjtree.popNode();
         }
        }
if (jjtc003) {
           jjtree.closeNodeScope(jjtn003,  2u);
           jjtn003->jjtSetLastToken(getToken(0));
         }
        break;
        }
      case LE:{
        jj_consume_token(LE);
ASTCompLTE *jjtn004 = new ASTCompLTE(JJTCOMPLTE);
         bool jjtc004 = true;
         jjtree.openNodeScope(jjtn004);
         jjtn004->jjtSetFirstToken(getToken(1));
        try {
          add_expression();
        } catch ( ...) {
if (jjtc004) {
           jjtree.clearNodeScope(jjtn004);
           jjtc004 = false;
         } else {
           jjtree.popNode();
         }
        }
if (jjtc004) {
           jjtree.closeNodeScope(jjtn004,  2u);
           jjtn004->jjtSetLastToken(getToken(0));
         }
        break;
        }
      case GT:{
        jj_consume_token(GT);
ASTCompGT *jjtn005 = new ASTCompGT(JJTCOMPGT);
        bool jjtc005 = true;
        jjtree.openNodeScope(jjtn005);
        jjtn005->jjtSetFirstToken(getToken(1));
        try {
          add_expression();
        } catch ( ...) {
if (jjtc005) {
          jjtree.clearNodeScope(jjtn005);
          jjtc005 = false;
        } else {
          jjtree.popNode();
        }
        }
if (jjtc005) {
          jjtree.closeNodeScope(jjtn005,  2u);
          jjtn005->jjtSetLastToken(getToken(0));
        }
        break;
        }
      case LT:{
        jj_consume_token(LT);
ASTCompLT *jjtn006 = new ASTCompLT(JJTCOMPLT);
        bool jjtc006 = true;
        jjtree.openNodeScope(jjtn006);
        jjtn006->jjtSetFirstToken(getToken(1));
        try {
          add_expression();
        } catch ( ...) {
if (jjtc006) {
          jjtree.clearNodeScope(jjtn006);
          jjtc006 = false;
        } else {
          jjtree.popNode();
        }
        }
if (jjtc006) {
          jjtree.closeNodeScope(jjtn006,  2u);
          jjtn006->jjtSetLastToken(getToken(0));
        }
        break;
        }
      default:
        jj_la1[36] = jj_gen;
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
      break;
      }
    default:
      jj_la1[37] = jj_gen;
      ;
    }
}


void Rattle::add_expression() {
    mul_expression();
    while (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case PLUS:
      case SUBT:{
        ;
        break;
        }
      default:
        jj_la1[38] = jj_gen;
        goto end_label_17;
      }
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case PLUS:{
        jj_consume_token(PLUS);
ASTAdd *jjtn001 = new ASTAdd(JJTADD);
          bool jjtc001 = true;
          jjtree.openNodeScope(jjtn001);
          jjtn001->jjtSetFirstToken(getToken(1));
        try {
          mul_expression();
        } catch ( ...) {
if (jjtc001) {
            jjtree.clearNodeScope(jjtn001);
            jjtc001 = false;
          } else {
            jjtree.popNode();
          }
        }
if (jjtc001) {
            jjtree.closeNodeScope(jjtn001,  2u);
            jjtn001->jjtSetLastToken(getToken(0));
          }
        break;
        }
      case SUBT:{
        jj_consume_token(SUBT);
ASTSubtract *jjtn002 = new ASTSubtract(JJTSUBTRACT);
            bool jjtc002 = true;
            jjtree.openNodeScope(jjtn002);
            jjtn002->jjtSetFirstToken(getToken(1));
        try {
          mul_expression();
        } catch ( ...) {
if (jjtc002) {
              jjtree.clearNodeScope(jjtn002);
              jjtc002 = false;
            } else {
              jjtree.popNode();
            }
        }
if (jjtc002) {
              jjtree.closeNodeScope(jjtn002,  2u);
              jjtn002->jjtSetLastToken(getToken(0));
            }
        break;
        }
      default:
        jj_la1[39] = jj_gen;
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
    }
    end_label_17: ;
}


void Rattle::mul_expression() {
    unary_expression();
    while (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case STAR:
      case SLASH:{
        ;
        break;
        }
      default:
        jj_la1[40] = jj_gen;
        goto end_label_18;
      }
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case STAR:{
        jj_consume_token(STAR);
ASTTimes *jjtn001 = new ASTTimes(JJTTIMES);
          bool jjtc001 = true;
          jjtree.openNodeScope(jjtn001);
          jjtn001->jjtSetFirstToken(getToken(1));
        try {
          unary_expression();
        } catch ( ...) {
if (jjtc001) {
            jjtree.clearNodeScope(jjtn001);
            jjtc001 = false;
          } else {
            jjtree.popNode();
          }
        }
if (jjtc001) {
            jjtree.closeNodeScope(jjtn001,  2u);
            jjtn001->jjtSetLastToken(getToken(0));
          }
        break;
        }
      case SLASH:{
        jj_consume_token(SLASH);
ASTDivide *jjtn002 = new ASTDivide(JJTDIVIDE);
        bool jjtc002 = true;
        jjtree.openNodeScope(jjtn002);
        jjtn002->jjtSetFirstToken(getToken(1));
        try {
          unary_expression();
        } catch ( ...) {
if (jjtc002) {
          jjtree.clearNodeScope(jjtn002);
          jjtc002 = false;
        } else {
          jjtree.popNode();
        }
        }
if (jjtc002) {
          jjtree.closeNodeScope(jjtn002,  2u);
          jjtn002->jjtSetLastToken(getToken(0));
        }
        break;
        }
      default:
        jj_la1[41] = jj_gen;
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
    }
    end_label_18: ;
}


void Rattle::unary_expression() {
    switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
    case NOT:{
      jj_consume_token(NOT);
ASTUnaryNot *jjtn001 = new ASTUnaryNot(JJTUNARYNOT);
            bool jjtc001 = true;
            jjtree.openNodeScope(jjtn001);
            jjtn001->jjtSetFirstToken(getToken(1));
      try {
        unary_expression();
      } catch ( ...) {
if (jjtc001) {
              jjtree.clearNodeScope(jjtn001);
              jjtc001 = false;
            } else {
              jjtree.popNode();
            }
      }
if (jjtc001) {
              jjtree.closeNodeScope(jjtn001,  1u);
              jjtn001->jjtSetLastToken(getToken(0));
            }
      break;
      }
    case PLUS:{
      jj_consume_token(PLUS);
ASTUnaryPlus *jjtn002 = new ASTUnaryPlus(JJTUNARYPLUS);
        bool jjtc002 = true;
        jjtree.openNodeScope(jjtn002);
        jjtn002->jjtSetFirstToken(getToken(1));
      try {
        unary_expression();
      } catch ( ...) {
if (jjtc002) {
          jjtree.clearNodeScope(jjtn002);
          jjtc002 = false;
        } else {
          jjtree.popNode();
        }
      }
if (jjtc002) {
          jjtree.closeNodeScope(jjtn002,  1u);
          jjtn002->jjtSetLastToken(getToken(0));
        }
      break;
      }
    case SUBT:{
      jj_consume_token(SUBT);
ASTUnaryMinus *jjtn003 = new ASTUnaryMinus(JJTUNARYMINUS);
        bool jjtc003 = true;
        jjtree.openNodeScope(jjtn003);
        jjtn003->jjtSetFirstToken(getToken(1));
      try {
        unary_expression();
      } catch ( ...) {
if (jjtc003) {
          jjtree.clearNodeScope(jjtn003);
          jjtc003 = false;
        } else {
          jjtree.popNode();
        }
      }
if (jjtc003) {
          jjtree.closeNodeScope(jjtn003,  1u);
          jjtn003->jjtSetLastToken(getToken(0));
        }
      break;
      }
    default:
      jj_la1[42] = jj_gen;
      if (jj_2_7(2147483647)) {
        indexed_expression();
      } else {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case TRUE:
        case FALSE:
        case FLOATING_POINT_LITERAL:
        case STRING_LITERAL:
        case CHARACTER_LITERAL:
        case IDENTIFIER:
        case LPAREN:
        case LBRACE:
        case LBRACKET:{
          primary_expression();
          break;
          }
        default:
          jj_la1[43] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
      }
    }
}


void Rattle::indexed_expression() {/*@bgen(jjtree) IndexedExpression */
  ASTIndexedExpression *jjtn000 = new ASTIndexedExpression(JJTINDEXEDEXPRESSION);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      primary_expression();
      jj_consume_token(LBRACKET);
      number();
      jj_consume_token(RBRACKET);
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::primary_expression() {
    switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
    case TRUE:
    case FALSE:
    case FLOATING_POINT_LITERAL:
    case STRING_LITERAL:
    case CHARACTER_LITERAL:{
      literal();
      break;
      }
    default:
      jj_la1[44] = jj_gen;
      if (jj_2_8(2147483647)) {
        lambda_define();
      } else if (jj_2_9(2147483647)) {
        tuple_define();
      } else if (jj_2_10(2147483647)) {
        fn_invoke();
      } else if (jj_2_11(2147483647)) {
        method_invoke();
      } else if (jj_2_12(3)) {
        dereference();
      } else {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case LBRACE:{
          obj_create();
          break;
          }
        case LPAREN:{
          jj_consume_token(LPAREN);
          expression();
          jj_consume_token(RPAREN);
          break;
          }
        default:
          jj_la1[45] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
      }
    }
}


void Rattle::tuple_define() {/*@bgen(jjtree) TupleDefine */
  ASTTupleDefine *jjtn000 = new ASTTupleDefine(JJTTUPLEDEFINE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      jj_consume_token(LBRACKET);
      expression();
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COMMA:{
          ;
          break;
          }
        default:
          jj_la1[46] = jj_gen;
          goto end_label_19;
        }
        jj_consume_token(COMMA);
        expression();
      }
      end_label_19: ;
      jj_consume_token(RBRACKET);
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::fn_invoke() {/*@bgen(jjtree) FnInvoke */
  ASTFnInvoke *jjtn000 = new ASTFnInvoke(JJTFNINVOKE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      identifier();
      arglist();
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::method_invoke() {/*@bgen(jjtree) MethodInvoke */
  ASTMethodInvoke *jjtn000 = new ASTMethodInvoke(JJTMETHODINVOKE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      identifier();
      while (!hasError) {
        jj_consume_token(67);
        identifier();
jjtn000->isObject = true;
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case 67:{
          ;
          break;
          }
        default:
          jj_la1[47] = jj_gen;
          goto end_label_20;
        }
      }
      end_label_20: ;
      arglist();
    } catch ( ...) {
if (jjtc000) {
       jjtree.clearNodeScope(jjtn000);
       jjtc000 = false;
     } else {
       jjtree.popNode();
     }
    }
if (jjtc000) {
       jjtree.closeNodeScope(jjtn000, true);
       jjtn000->jjtSetLastToken(getToken(0));
     }
}


void Rattle::literal() {
    switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
    case FLOATING_POINT_LITERAL:{
      number();
      break;
      }
    case CHARACTER_LITERAL:{
      character();
      break;
      }
    case STRING_LITERAL:{
      string();
      break;
      }
    case TRUE:
    case FALSE:{
      Bool();
      break;
      }
    default:
      jj_la1[48] = jj_gen;
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
}


void Rattle::identifier() {Token* t;/*@bgen(jjtree) Identifier */
  ASTIdentifier *jjtn000 = new ASTIdentifier(JJTIDENTIFIER);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      t = jj_consume_token(IDENTIFIER);
jjtree.closeNodeScope(jjtn000, true);
    jjtc000 = false;
    jjtn000->jjtSetLastToken(getToken(0));
jjtn000->tokenValue = t->image;
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::member_identifier() {Token* t;/*@bgen(jjtree) MemIdentifier */
  ASTMemIdentifier *jjtn000 = new ASTMemIdentifier(JJTMEMIDENTIFIER);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      // One and then many identifiers.
          t = jj_consume_token(IDENTIFIER);
jjtn000->tokenValue = t->image;
        jjtn000->isObject = true;
      while (!hasError) {
        jj_consume_token(67);
        identifier();
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case 67:{
          ;
          break;
          }
        default:
          jj_la1[49] = jj_gen;
          goto end_label_21;
        }
      }
      end_label_21: ;
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::dereference() {Token* t;/*@bgen(jjtree) Dereference */
  ASTDereference *jjtn000 = new ASTDereference(JJTDEREFERENCE);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      if (jj_2_13(2147483647)) {
        member_identifier();
jjtree.closeNodeScope(jjtn000, true);
                                                       jjtc000 = false;
                                                       jjtn000->jjtSetLastToken(getToken(0));
jjtn000->isObject = true;
      } else {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case IDENTIFIER:{
          identifier();
          break;
          }
        default:
          jj_la1[50] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
      }
    } catch ( ...) {
if (jjtc000) {
       jjtree.clearNodeScope(jjtn000);
       jjtc000 = false;
     } else {
       jjtree.popNode();
     }
    }
if (jjtc000) {
       jjtree.closeNodeScope(jjtn000, true);
       jjtn000->jjtSetLastToken(getToken(0));
     }
}


void Rattle::character() {Token* t;/*@bgen(jjtree) Character */
  ASTCharacter *jjtn000 = new ASTCharacter(JJTCHARACTER);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      t = jj_consume_token(CHARACTER_LITERAL);
jjtree.closeNodeScope(jjtn000, true);
    jjtc000 = false;
    jjtn000->jjtSetLastToken(getToken(0));
jjtn000->tokenValue = t->image;
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::string() {Token* t;/*@bgen(jjtree) String */
  ASTString *jjtn000 = new ASTString(JJTSTRING);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      t = jj_consume_token(STRING_LITERAL);
jjtree.closeNodeScope(jjtn000, true);
      jjtc000 = false;
      jjtn000->jjtSetLastToken(getToken(0));
jjtn000->tokenValue = t->image;
    } catch ( ...) {
if (jjtc000) {
        jjtree.clearNodeScope(jjtn000);
        jjtc000 = false;
      } else {
        jjtree.popNode();
      }
    }
if (jjtc000) {
        jjtree.closeNodeScope(jjtn000, true);
        jjtn000->jjtSetLastToken(getToken(0));
      }
}


void Rattle::number() {Token* t;/*@bgen(jjtree) Number */
  ASTNumber *jjtn000 = new ASTNumber(JJTNUMBER);
  bool jjtc000 = true;
  jjtree.openNodeScope(jjtn000);
  jjtn000->jjtSetFirstToken(getToken(1));
    try {
      t = jj_consume_token(FLOATING_POINT_LITERAL);
jjtree.closeNodeScope(jjtn000, true);
    jjtc000 = false;
    jjtn000->jjtSetLastToken(getToken(0));
jjtn000->tokenValue = t->image;
    } catch ( ...) {
if (jjtc000) {
      jjtree.clearNodeScope(jjtn000);
      jjtc000 = false;
    } else {
      jjtree.popNode();
    }
    }
if (jjtc000) {
      jjtree.closeNodeScope(jjtn000, true);
      jjtn000->jjtSetLastToken(getToken(0));
    }
}


void Rattle::Bool() {
    switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
    case TRUE:{
ASTTrue *jjtn001 = new ASTTrue(JJTTRUE);
    bool jjtc001 = true;
    jjtree.openNodeScope(jjtn001);
    jjtn001->jjtSetFirstToken(getToken(1));
      try {
        jj_consume_token(TRUE);
      } catch ( ...) {
if (jjtc001) {
      jjtree.clearNodeScope(jjtn001);
      jjtc001 = false;
    } else {
      jjtree.popNode();
    }
      }
if (jjtc001) {
      jjtree.closeNodeScope(jjtn001, true);
      jjtn001->jjtSetLastToken(getToken(0));
    }
      break;
      }
    case FALSE:{
ASTFalse *jjtn002 = new ASTFalse(JJTFALSE);
    bool jjtc002 = true;
    jjtree.openNodeScope(jjtn002);
    jjtn002->jjtSetFirstToken(getToken(1));
      try {
        jj_consume_token(FALSE);
      } catch ( ...) {
if (jjtc002) {
      jjtree.clearNodeScope(jjtn002);
      jjtc002 = false;
    } else {
      jjtree.popNode();
    }
      }
if (jjtc002) {
      jjtree.closeNodeScope(jjtn002, true);
      jjtn002->jjtSetLastToken(getToken(0));
    }
      break;
      }
    default:
      jj_la1[51] = jj_gen;
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
}


  Rattle::Rattle(TokenManager *tokenManager){
    head = nullptr;
    ReInit(tokenManager);
}
Rattle::~Rattle()
{
  clear();
}

void Rattle::ReInit(TokenManager* tokenManager){
    clear();
    errorHandler = new ErrorHandler();
    hasError = false;
    token_source = tokenManager;
    head = token = new Token();
    token->kind = 0;
    token->next = nullptr;
    jj_lookingAhead = false;
    jj_rescan = false;
    jj_done = false;
    jj_scanpos = jj_lastpos = nullptr;
    jj_gc = 0;
    jj_kind = -1;
    indent = 0;
    trace = false;
    jj_ntk = -1;
    jjtree.reset();
    jj_gen = 0;
    for (int i = 0; i < 52; i++) jj_la1[i] = -1;
  }


void Rattle::clear(){
  //Since token manager was generate from outside,
  //parser should not take care of deleting
  //if (token_source) delete token_source;
  if (head) {
    Token *next, *t = head;
    while (t) {
      next = t->next;
      delete t;
      t = next;
    }
  }
  if (errorHandler) {
    delete errorHandler, errorHandler = nullptr;
  }
}


Token * Rattle::jj_consume_token(int kind)  {
    Token *oldToken;
    if ((oldToken = token)->next != nullptr) token = token->next;
    else token = token->next = token_source->getNextToken();
    jj_ntk = -1;
    if (token->kind == kind) {
      jj_gen++;
      if (++jj_gc > 100) {
        jj_gc = 0;
        for (int i = 0; i < 13; i++) {
          JJCalls *c = &jj_2_rtns[i];
          while (c != nullptr) {
            if (c->gen < jj_gen) c->first = nullptr;
            c = c->next;
          }
        }
      }
      return token;
    }
    token = oldToken;
    jj_kind = kind;
    JJString image = kind >= 0 ? tokenImage[kind] : tokenImage[0];
    errorHandler->handleUnexpectedToken(kind, image.substr(1, image.size() - 2), getToken(1), this);
    hasError = true;
    return token;
  }


bool  Rattle::jj_scan_token(int kind){
    if (jj_scanpos == jj_lastpos) {
      jj_la--;
      if (jj_scanpos->next == nullptr) {
        jj_lastpos = jj_scanpos = jj_scanpos->next = token_source->getNextToken();
      } else {
        jj_lastpos = jj_scanpos = jj_scanpos->next;
      }
    } else {
      jj_scanpos = jj_scanpos->next;
    }
    if (jj_rescan) {
      int i = 0; Token *tok = token;
      while (tok != nullptr && tok != jj_scanpos) { i++; tok = tok->next; }
      if (tok != nullptr) jj_add_error_token(kind, i);
    }
    if (jj_scanpos->kind != kind) return true;
    if (jj_la == 0 && jj_scanpos == jj_lastpos) { return jj_done = true; }
    return false;
  }


/** Get the next Token. */

Token * Rattle::getNextToken(){
    if (token->next != nullptr) token = token->next;
    else token = token->next = token_source->getNextToken();
    jj_ntk = -1;
    jj_gen++;
    return token;
  }

/** Get the specific Token. */

Token * Rattle::getToken(int index){
    Token *t = token;
    for (int i = 0; i < index; i++) {
      if (t->next != nullptr) t = t->next;
      else t = t->next = token_source->getNextToken();
    }
    return t;
  }


int Rattle::jj_ntk_f(){
    if ((jj_nt=token->next) == nullptr)
      return (jj_ntk = (token->next=token_source->getNextToken())->kind);
    else
      return (jj_ntk = jj_nt->kind);
  }


  void Rattle::jj_add_error_token(int kind, int pos)  {
  }


 void  Rattle::parseError()   {
      fprintf(stderr, "Parse error at: %d:%d, after token: %s encountered: %s\n", token->beginLine, token->beginColumn, addUnicodeEscapes(token->image).c_str(), addUnicodeEscapes(getToken(1)->image).c_str());
   }


  bool Rattle::trace_enabled()  {
    return trace;
  }


  void Rattle::enable_tracing()  {
  }

  void Rattle::disable_tracing()  {
  }


  void Rattle::jj_rescan_token(){
    jj_rescan = true;
    for (int i = 0; i < 13; i++) {
      JJCalls *p = &jj_2_rtns[i];
      do {
        if (p->gen > jj_gen) {
          jj_la = p->arg; jj_lastpos = jj_scanpos = p->first;
          switch (i) {
            case 0: jj_3_1(); break;
            case 1: jj_3_2(); break;
            case 2: jj_3_3(); break;
            case 3: jj_3_4(); break;
            case 4: jj_3_5(); break;
            case 5: jj_3_6(); break;
            case 6: jj_3_7(); break;
            case 7: jj_3_8(); break;
            case 8: jj_3_9(); break;
            case 9: jj_3_10(); break;
            case 10: jj_3_11(); break;
            case 11: jj_3_12(); break;
            case 12: jj_3_13(); break;
          }
        }
        p = p->next;
      } while (p != nullptr);
    }
    jj_rescan = false;
  }


  void Rattle::jj_save(int index, int xla){
    JJCalls *p = &jj_2_rtns[index];
    while (p->gen > jj_gen) {
      if (p->next == nullptr) { p = p->next = new JJCalls(); break; }
      p = p->next;
    }
    p->gen = jj_gen + xla - jj_la; p->first = token; p->arg = xla;
  }


}
