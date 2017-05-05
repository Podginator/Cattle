#ifndef RATTLE_H
#define RATTLE_H
#include "JavaCC.h"
#include "CharStream.h"
#include "Token.h"
#include "TokenManager.h"
#include "RattleConstants.h"
#include "JJTRattleState.h"
#include "ErrorHandler.h"
#include "RattleTree.h"
namespace RattleLang {
  struct JJCalls {
    int        gen;
    int        arg;
    JJCalls*   next;
    Token*     first;
    ~JJCalls() { if (next) delete next; }
     JJCalls() { next = nullptr; arg = 0; gen = -1; first = nullptr; }
  };

class Rattle {
public:
ASTCode
       * code();
void statement();
void block();
void parmlist();
void LambdaPass();
void classdef();
void fnbody();
void fnTypeList();
void methoddef();
void fndef();
void returnexpr();
void member_declaration();
void assignment();
void ifstatement();
void obj_create();
void member_instantiate();
void method_instantiate();
void lambda_define();
void forloop();
void whileloop();
void write();
void arglist();
void expression();
void or_expression();
void and_expression();
void compare_expression();
void add_expression();
void mul_expression();
void unary_expression();
void indexed_expression();
void primary_expression();
void tuple_define();
void fn_invoke();
void method_invoke();
void literal();
void identifier();
void member_identifier();
void dereference();
void character();
void string();
void number();
void Bool();
 inline bool jj_2_1(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_1() || jj_done);
 { jj_save(0, xla); }
  }

 inline bool jj_2_2(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_2() || jj_done);
 { jj_save(1, xla); }
  }

 inline bool jj_2_3(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_3() || jj_done);
 { jj_save(2, xla); }
  }

 inline bool jj_2_4(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_4() || jj_done);
 { jj_save(3, xla); }
  }

 inline bool jj_2_5(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_5() || jj_done);
 { jj_save(4, xla); }
  }

 inline bool jj_2_6(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_6() || jj_done);
 { jj_save(5, xla); }
  }

 inline bool jj_2_7(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_7() || jj_done);
 { jj_save(6, xla); }
  }

 inline bool jj_2_8(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_8() || jj_done);
 { jj_save(7, xla); }
  }

 inline bool jj_2_9(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_9() || jj_done);
 { jj_save(8, xla); }
  }

 inline bool jj_2_10(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_10() || jj_done);
 { jj_save(9, xla); }
  }

 inline bool jj_2_11(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_11() || jj_done);
 { jj_save(10, xla); }
  }

 inline bool jj_2_12(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_12() || jj_done);
 { jj_save(11, xla); }
  }

 inline bool jj_2_13(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_13() || jj_done);
 { jj_save(12, xla); }
  }

 inline bool jj_3R_77()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_3R_34()) return true;
    return false;
  }

 inline bool jj_3R_147()
 {
    if (jj_done) return true;
    if (jj_scan_token(ASSIGN)) return true;
    if (jj_3R_34()) return true;
    return false;
  }

 inline bool jj_3R_146()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_147()) {
    jj_scanpos = xsp;
    if (jj_3R_148()) return true;
    }
    return false;
  }

 inline bool jj_3R_142()
 {
    if (jj_done) return true;
    if (jj_3R_41()) return true;
    return false;
  }

 inline bool jj_3R_141()
 {
    if (jj_done) return true;
    if (jj_3R_27()) return true;
    return false;
  }

 inline bool jj_3R_140()
 {
    if (jj_done) return true;
    if (jj_scan_token(SUBT)) return true;
    if (jj_3R_130()) return true;
    return false;
  }

 inline bool jj_3R_139()
 {
    if (jj_done) return true;
    if (jj_scan_token(PLUS)) return true;
    if (jj_3R_130()) return true;
    return false;
  }

 inline bool jj_3R_145()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    if (jj_scan_token(63)) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_146()) jj_scanpos = xsp;
    return false;
  }

 inline bool jj_3R_138()
 {
    if (jj_done) return true;
    if (jj_scan_token(NOT)) return true;
    if (jj_3R_130()) return true;
    return false;
  }

 inline bool jj_3R_130()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_138()) {
    jj_scanpos = xsp;
    if (jj_3R_139()) {
    jj_scanpos = xsp;
    if (jj_3R_140()) {
    jj_scanpos = xsp;
    if (jj_3R_141()) {
    jj_scanpos = xsp;
    if (jj_3R_142()) return true;
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3R_124()
 {
    if (jj_done) return true;
    if (jj_3R_64()) return true;
    return false;
  }

 inline bool jj_3R_143()
 {
    if (jj_done) return true;
    if (jj_scan_token(STAR)) return true;
    if (jj_3R_130()) return true;
    return false;
  }

 inline bool jj_3R_131()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_143()) {
    jj_scanpos = xsp;
    if (jj_3R_144()) return true;
    }
    return false;
  }

 inline bool jj_3R_144()
 {
    if (jj_done) return true;
    if (jj_scan_token(SLASH)) return true;
    if (jj_3R_130()) return true;
    return false;
  }

 inline bool jj_3R_66()
 {
    if (jj_done) return true;
    if (jj_3R_34()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_77()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_49()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_112()
 {
    if (jj_done) return true;
    if (jj_3R_130()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_131()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_125()
 {
    if (jj_done) return true;
    if (jj_scan_token(RETURN)) return true;
    if (jj_3R_66()) return true;
    return false;
  }

 inline bool jj_3R_133()
 {
    if (jj_done) return true;
    if (jj_scan_token(SUBT)) return true;
    if (jj_3R_112()) return true;
    return false;
  }

 inline bool jj_3R_132()
 {
    if (jj_done) return true;
    if (jj_scan_token(PLUS)) return true;
    if (jj_3R_112()) return true;
    return false;
  }

 inline bool jj_3R_113()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_132()) {
    jj_scanpos = xsp;
    if (jj_3R_133()) return true;
    }
    return false;
  }

 inline bool jj_3R_75()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_97()
 {
    if (jj_done) return true;
    if (jj_3R_112()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_113()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_105()
 {
    if (jj_done) return true;
    if (jj_scan_token(FN)) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_124()) jj_scanpos = xsp;
    if (jj_3R_43()) return true;
    if (jj_scan_token(LBRACE)) return true;
    if (jj_3R_45()) return true;
    xsp = jj_scanpos;
    if (jj_3R_125()) jj_scanpos = xsp;
    if (jj_scan_token(RBRACE)) return true;
    return false;
  }

 inline bool jj_3R_119()
 {
    if (jj_done) return true;
    if (jj_scan_token(LT)) return true;
    if (jj_3R_97()) return true;
    return false;
  }

 inline bool jj_3R_118()
 {
    if (jj_done) return true;
    if (jj_scan_token(GT)) return true;
    if (jj_3R_97()) return true;
    return false;
  }

 inline bool jj_3R_117()
 {
    if (jj_done) return true;
    if (jj_scan_token(LE)) return true;
    if (jj_3R_97()) return true;
    return false;
  }

 inline bool jj_3R_116()
 {
    if (jj_done) return true;
    if (jj_scan_token(GE)) return true;
    if (jj_3R_97()) return true;
    return false;
  }

 inline bool jj_3R_114()
 {
    if (jj_done) return true;
    if (jj_scan_token(EQ)) return true;
    if (jj_3R_97()) return true;
    return false;
  }

 inline bool jj_3R_98()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_114()) {
    jj_scanpos = xsp;
    if (jj_3R_115()) {
    jj_scanpos = xsp;
    if (jj_3R_116()) {
    jj_scanpos = xsp;
    if (jj_3R_117()) {
    jj_scanpos = xsp;
    if (jj_3R_118()) {
    jj_scanpos = xsp;
    if (jj_3R_119()) return true;
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3R_115()
 {
    if (jj_done) return true;
    if (jj_scan_token(68)) return true;
    if (jj_3R_97()) return true;
    return false;
  }

 inline bool jj_3R_87()
 {
    if (jj_done) return true;
    if (jj_3R_85()) return true;
    return false;
  }

 inline bool jj_3R_126()
 {
    if (jj_done) return true;
    if (jj_scan_token(65)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_78()
 {
    if (jj_done) return true;
    if (jj_3R_97()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_98()) jj_scanpos = xsp;
    return false;
  }

 inline bool jj_3R_64()
 {
    if (jj_done) return true;
    if (jj_scan_token(63)) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_75()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_104()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_73()
 {
    if (jj_done) return true;
    if (jj_3R_85()) return true;
    return false;
  }

 inline bool jj_3R_79()
 {
    if (jj_done) return true;
    if (jj_scan_token(AND)) return true;
    if (jj_3R_78()) return true;
    return false;
  }

 inline bool jj_3R_65()
 {
    if (jj_done) return true;
    if (jj_3R_76()) return true;
    return false;
  }

 inline bool jj_3R_68()
 {
    if (jj_done) return true;
    if (jj_3R_78()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_79()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_103()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_135()
 {
    if (jj_done) return true;
    if (jj_3R_106()) return true;
    return false;
  }

 inline bool jj_3R_127()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_135()) {
    jj_scanpos = xsp;
    if (jj_3R_136()) {
    jj_scanpos = xsp;
    if (jj_3R_137()) return true;
    }
    }
    return false;
  }

 inline bool jj_3R_121()
 {
    if (jj_done) return true;
    if (jj_scan_token(FALSE)) return true;
    return false;
  }

 inline bool jj_3R_86()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_45()
 {
    if (jj_done) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_65()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_137()
 {
    if (jj_done) return true;
    if (jj_3R_105()) return true;
    return false;
  }

 inline bool jj_3R_120()
 {
    if (jj_done) return true;
    if (jj_scan_token(TRUE)) return true;
    return false;
  }

 inline bool jj_3R_101()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_120()) {
    jj_scanpos = xsp;
    if (jj_3R_121()) return true;
    }
    return false;
  }

 inline bool jj_3R_69()
 {
    if (jj_done) return true;
    if (jj_scan_token(OR)) return true;
    if (jj_3R_68()) return true;
    return false;
  }

 inline bool jj_3R_136()
 {
    if (jj_done) return true;
    if (jj_3R_145()) return true;
    return false;
  }

 inline bool jj_3R_53()
 {
    if (jj_done) return true;
    if (jj_3R_68()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_69()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_72()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_34()
 {
    if (jj_done) return true;
    if (jj_3R_53()) return true;
    return false;
  }

 inline bool jj_3R_42()
 {
    if (jj_done) return true;
    if (jj_scan_token(FLOATING_POINT_LITERAL)) return true;
    return false;
  }

 inline bool jj_3R_106()
 {
    if (jj_done) return true;
    if (jj_scan_token(CLASS)) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_126()) jj_scanpos = xsp;
    if (jj_scan_token(LBRACE)) return true;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_127()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RBRACE)) return true;
    return false;
  }

 inline bool jj_3R_123()
 {
    if (jj_done) return true;
    if (jj_3R_134()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_scan_token(41)) jj_scanpos = xsp;
    return false;
  }

 inline bool jj_3R_85()
 {
    if (jj_done) return true;
    if (jj_scan_token(64)) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_103()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(GT)) return true;
    if (jj_scan_token(LPAREN)) return true;
    if (jj_3R_36()) return true;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_104()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RPAREN)) return true;
    return false;
  }

 inline bool jj_3R_54()
 {
    if (jj_done) return true;
    if (jj_3R_34()) return true;
    return false;
  }

 inline bool jj_3R_55()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_3R_34()) return true;
    return false;
  }

 inline bool jj_3R_100()
 {
    if (jj_done) return true;
    if (jj_scan_token(STRING_LITERAL)) return true;
    return false;
  }

 inline bool jj_3R_74()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_3R_36()) return true;
    if (jj_scan_token(63)) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_86()) {
    jj_scanpos = xsp;
    if (jj_3R_87()) return true;
    }
    return false;
  }

 inline bool jj_3R_37()
 {
    if (jj_done) return true;
    if (jj_scan_token(LPAREN)) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_54()) jj_scanpos = xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_55()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RPAREN)) return true;
    return false;
  }

 inline bool jj_3R_63()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    if (jj_scan_token(63)) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_72()) {
    jj_scanpos = xsp;
    if (jj_3R_73()) return true;
    }
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_74()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_111()
 {
    if (jj_done) return true;
    if (jj_scan_token(PRINT)) return true;
    if (jj_3R_34()) return true;
    return false;
  }

 inline bool jj_3_13()
 {
    if (jj_done) return true;
    if (jj_3R_25()) return true;
    return false;
  }

 inline bool jj_3R_43()
 {
    if (jj_done) return true;
    if (jj_scan_token(LPAREN)) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_63()) jj_scanpos = xsp;
    if (jj_scan_token(RPAREN)) return true;
    return false;
  }

 inline bool jj_3R_99()
 {
    if (jj_done) return true;
    if (jj_scan_token(CHARACTER_LITERAL)) return true;
    return false;
  }

 inline bool jj_3R_110()
 {
    if (jj_done) return true;
    if (jj_scan_token(WHILE)) return true;
    if (jj_scan_token(LPAREN)) return true;
    if (jj_3R_34()) return true;
    if (jj_scan_token(RPAREN)) return true;
    if (jj_3R_76()) return true;
    return false;
  }

 inline bool jj_3R_128()
 {
    if (jj_done) return true;
    if (jj_3R_76()) return true;
    return false;
  }

 inline bool jj_3_3()
 {
    if (jj_done) return true;
    if (jj_3R_24()) return true;
    return false;
  }

 inline bool jj_3R_109()
 {
    if (jj_done) return true;
    if (jj_scan_token(FOR)) return true;
    if (jj_scan_token(LPAREN)) return true;
    if (jj_3R_22()) return true;
    if (jj_scan_token(SEMICOLON)) return true;
    if (jj_3R_34()) return true;
    if (jj_scan_token(SEMICOLON)) return true;
    if (jj_3R_22()) return true;
    if (jj_scan_token(RPAREN)) return true;
    if (jj_3R_76()) return true;
    return false;
  }

 inline bool jj_3R_44()
 {
    if (jj_done) return true;
    if (jj_3R_64()) return true;
    return false;
  }

 inline bool jj_3R_30()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_48()) {
    jj_scanpos = xsp;
    if (jj_3R_49()) return true;
    }
    return false;
  }

 inline bool jj_3R_48()
 {
    if (jj_done) return true;
    if (jj_3R_25()) return true;
    return false;
  }

 inline bool jj_3R_107()
 {
    if (jj_done) return true;
    if (jj_scan_token(LBRACE)) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_128()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RBRACE)) return true;
    return false;
  }

 inline bool jj_3R_95()
 {
    if (jj_done) return true;
    if (jj_3R_111()) return true;
    return false;
  }

 inline bool jj_3R_46()
 {
    if (jj_done) return true;
    if (jj_scan_token(RETURN)) return true;
    if (jj_3R_66()) return true;
    return false;
  }

 inline bool jj_3R_93()
 {
    if (jj_done) return true;
    if (jj_3R_109()) return true;
    return false;
  }

 inline bool jj_3R_96()
 {
    if (jj_done) return true;
    if (jj_3R_24()) return true;
    return false;
  }

 inline bool jj_3R_92()
 {
    if (jj_done) return true;
    if (jj_3R_108()) return true;
    return false;
  }

 inline bool jj_3R_91()
 {
    if (jj_done) return true;
    if (jj_3R_107()) return true;
    return false;
  }

 inline bool jj_3_1()
 {
    if (jj_done) return true;
    if (jj_3R_22()) return true;
    return false;
  }

 inline bool jj_3R_39()
 {
    if (jj_done) return true;
    if (jj_scan_token(67)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3_2()
 {
    if (jj_done) return true;
    if (jj_3R_23()) return true;
    return false;
  }

 inline bool jj_3R_89()
 {
    if (jj_done) return true;
    if (jj_3R_105()) return true;
    return false;
  }

 inline bool jj_3R_94()
 {
    if (jj_done) return true;
    if (jj_3R_110()) return true;
    return false;
  }

 inline bool jj_3R_28()
 {
    if (jj_done) return true;
    if (jj_3R_43()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_44()) jj_scanpos = xsp;
    if (jj_scan_token(67)) return true;
    if (jj_scan_token(LBRACE)) return true;
    if (jj_3R_45()) return true;
    xsp = jj_scanpos;
    if (jj_3R_46()) jj_scanpos = xsp;
    if (jj_scan_token(RBRACE)) return true;
    return false;
  }

 inline bool jj_3R_90()
 {
    if (jj_done) return true;
    if (jj_3R_106()) return true;
    return false;
  }

 inline bool jj_3R_25()
 {
    if (jj_done) return true;
    if (jj_scan_token(IDENTIFIER)) return true;
    Token * xsp;
    if (jj_3R_39()) return true;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_39()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_40()
 {
    if (jj_done) return true;
    if (jj_scan_token(67)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_88()
 {
    if (jj_done) return true;
    if (jj_3R_22()) return true;
    return false;
  }

 inline bool jj_3R_76()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_88()) {
    jj_scanpos = xsp;
    if (jj_3R_89()) {
    jj_scanpos = xsp;
    if (jj_3R_90()) {
    jj_scanpos = xsp;
    if (jj_3R_91()) {
    jj_scanpos = xsp;
    if (jj_3R_92()) {
    jj_scanpos = xsp;
    if (jj_3R_93()) {
    jj_scanpos = xsp;
    if (jj_3R_94()) {
    jj_scanpos = xsp;
    if (jj_3R_95()) {
    jj_scanpos = xsp;
    if (jj_3_2()) {
    jj_scanpos = xsp;
    if (jj_3R_96()) return true;
    }
    }
    }
    }
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3_6()
 {
    if (jj_done) return true;
    if (jj_3R_26()) return true;
    return false;
  }

 inline bool jj_3R_26()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_40()) { jj_scanpos = xsp; break; }
    }
    if (jj_3R_37()) return true;
    return false;
  }

 inline bool jj_3R_122()
 {
    if (jj_done) return true;
    if (jj_3R_26()) return true;
    return false;
  }

 inline bool jj_3R_102()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_122()) {
    jj_scanpos = xsp;
    if (jj_3R_123()) return true;
    }
    return false;
  }

 inline bool jj_3R_36()
 {
    if (jj_done) return true;
    if (jj_scan_token(IDENTIFIER)) return true;
    return false;
  }

 inline bool jj_3R_134()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    if (jj_scan_token(ASSIGN)) return true;
    if (jj_3R_34()) return true;
    return false;
  }

 inline bool jj_3R_84()
 {
    if (jj_done) return true;
    if (jj_scan_token(66)) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_102()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_83()
 {
    if (jj_done) return true;
    if (jj_3R_101()) return true;
    return false;
  }

 inline bool jj_3R_82()
 {
    if (jj_done) return true;
    if (jj_3R_100()) return true;
    return false;
  }

 inline bool jj_3R_81()
 {
    if (jj_done) return true;
    if (jj_3R_99()) return true;
    return false;
  }

 inline bool jj_3R_80()
 {
    if (jj_done) return true;
    if (jj_3R_42()) return true;
    return false;
  }

 inline bool jj_3R_70()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_80()) {
    jj_scanpos = xsp;
    if (jj_3R_81()) {
    jj_scanpos = xsp;
    if (jj_3R_82()) {
    jj_scanpos = xsp;
    if (jj_3R_83()) return true;
    }
    }
    }
    return false;
  }

 inline bool jj_3R_67()
 {
    if (jj_done) return true;
    if (jj_scan_token(63)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_38()
 {
    if (jj_done) return true;
    if (jj_scan_token(67)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_47()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_3R_34()) return true;
    return false;
  }

 inline bool jj_3R_50()
 {
    if (jj_done) return true;
    if (jj_scan_token(63)) return true;
    if (jj_3R_36()) return true;
    return false;
  }

 inline bool jj_3R_71()
 {
    if (jj_done) return true;
    if (jj_scan_token(LBRACE)) return true;
    if (jj_scan_token(CREATE)) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_84()) jj_scanpos = xsp;
    if (jj_scan_token(RBRACE)) return true;
    return false;
  }

 inline bool jj_3R_24()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    if (jj_3R_38()) return true;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_38()) { jj_scanpos = xsp; break; }
    }
    if (jj_3R_37()) return true;
    return false;
  }

 inline bool jj_3R_23()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    if (jj_3R_37()) return true;
    return false;
  }

 inline bool jj_3R_129()
 {
    if (jj_done) return true;
    if (jj_scan_token(ELSE)) return true;
    if (jj_3R_76()) return true;
    return false;
  }

 inline bool jj_3_5()
 {
    if (jj_done) return true;
    if (jj_3R_25()) return true;
    return false;
  }

 inline bool jj_3_11()
 {
    if (jj_done) return true;
    if (jj_3R_24()) return true;
    return false;
  }

 inline bool jj_3R_29()
 {
    if (jj_done) return true;
    if (jj_scan_token(LBRACKET)) return true;
    if (jj_3R_34()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_47()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RBRACKET)) return true;
    return false;
  }

 inline bool jj_3_10()
 {
    if (jj_done) return true;
    if (jj_3R_23()) return true;
    return false;
  }

 inline bool jj_3R_108()
 {
    if (jj_done) return true;
    if (jj_scan_token(IF)) return true;
    if (jj_scan_token(LPAREN)) return true;
    if (jj_3R_34()) return true;
    if (jj_scan_token(RPAREN)) return true;
    if (jj_3R_76()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_129()) jj_scanpos = xsp;
    return false;
  }

 inline bool jj_3R_35()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_3R_34()) return true;
    return false;
  }

 inline bool jj_3_9()
 {
    if (jj_done) return true;
    if (jj_3R_29()) return true;
    return false;
  }

 inline bool jj_3R_62()
 {
    if (jj_done) return true;
    if (jj_scan_token(LPAREN)) return true;
    if (jj_3R_34()) return true;
    if (jj_scan_token(RPAREN)) return true;
    return false;
  }

 inline bool jj_3_8()
 {
    if (jj_done) return true;
    if (jj_3R_28()) return true;
    return false;
  }

 inline bool jj_3R_61()
 {
    if (jj_done) return true;
    if (jj_3R_71()) return true;
    return false;
  }

 inline bool jj_3_12()
 {
    if (jj_done) return true;
    if (jj_3R_30()) return true;
    return false;
  }

 inline bool jj_3_4()
 {
    if (jj_done) return true;
    if (jj_3R_25()) return true;
    return false;
  }

 inline bool jj_3R_52()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_67()) jj_scanpos = xsp;
    return false;
  }

 inline bool jj_3R_51()
 {
    if (jj_done) return true;
    if (jj_3R_25()) return true;
    return false;
  }

 inline bool jj_3R_60()
 {
    if (jj_done) return true;
    if (jj_3R_24()) return true;
    return false;
  }

 inline bool jj_3R_59()
 {
    if (jj_done) return true;
    if (jj_3R_23()) return true;
    return false;
  }

 inline bool jj_3R_58()
 {
    if (jj_done) return true;
    if (jj_3R_29()) return true;
    return false;
  }

 inline bool jj_3R_33()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_51()) {
    jj_scanpos = xsp;
    if (jj_3R_52()) return true;
    }
    return false;
  }

 inline bool jj_3R_57()
 {
    if (jj_done) return true;
    if (jj_3R_28()) return true;
    return false;
  }

 inline bool jj_3R_56()
 {
    if (jj_done) return true;
    if (jj_3R_70()) return true;
    return false;
  }

 inline bool jj_3R_32()
 {
    if (jj_done) return true;
    if (jj_3R_36()) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_50()) jj_scanpos = xsp;
    return false;
  }

 inline bool jj_3R_31()
 {
    if (jj_done) return true;
    if (jj_3R_25()) return true;
    return false;
  }

 inline bool jj_3R_148()
 {
    if (jj_done) return true;
    if (jj_3R_71()) return true;
    return false;
  }

 inline bool jj_3R_41()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_56()) {
    jj_scanpos = xsp;
    if (jj_3R_57()) {
    jj_scanpos = xsp;
    if (jj_3R_58()) {
    jj_scanpos = xsp;
    if (jj_3R_59()) {
    jj_scanpos = xsp;
    if (jj_3R_60()) {
    jj_scanpos = xsp;
    if (jj_3_12()) {
    jj_scanpos = xsp;
    if (jj_3R_61()) {
    jj_scanpos = xsp;
    if (jj_3R_62()) return true;
    }
    }
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3R_22()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_31()) {
    jj_scanpos = xsp;
    if (jj_3R_32()) return true;
    }
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_33()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(ASSIGN)) return true;
    if (jj_3R_34()) return true;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_35()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3_7()
 {
    if (jj_done) return true;
    if (jj_3R_27()) return true;
    return false;
  }

 inline bool jj_3R_27()
 {
    if (jj_done) return true;
    if (jj_3R_41()) return true;
    if (jj_scan_token(LBRACKET)) return true;
    if (jj_3R_42()) return true;
    if (jj_scan_token(RBRACKET)) return true;
    return false;
  }


public: 
  void setErrorHandler(ErrorHandler *eh) {
    if (errorHandler) delete errorHandler;
    errorHandler = eh;
  }

  TokenManager *token_source = nullptr;
  CharStream   *jj_input_stream = nullptr;
  /** Current token. */
  Token        *token = nullptr;
  /** Next token. */
  Token        *jj_nt = nullptr;

private: 
  int           jj_ntk;
  JJCalls       jj_2_rtns[14];
  bool          jj_rescan;
  int           jj_gc;
  Token        *jj_scanpos, *jj_lastpos;
  int           jj_la;
  /** Whether we are looking ahead. */
  bool          jj_lookingAhead;
  bool          jj_semLA;
  int           jj_gen;
  int           jj_la1[54];
  ErrorHandler *errorHandler = nullptr;

protected: 
  bool          hasError;

  Token *head; 
public: 
  Rattle(TokenManager *tokenManager);
  virtual ~Rattle();
void ReInit(TokenManager* tokenManager);
void clear();
Token * jj_consume_token(int kind);
bool  jj_scan_token(int kind);
Token * getNextToken();
Token * getToken(int index);
int jj_ntk_f();
private:
  int jj_kind;
  int **jj_expentries;
  int *jj_expentry;
  void jj_add_error_token(int kind, int pos);
protected:
  /** Generate ParseException. */
  virtual void  parseError();
private:
  int  indent;	// trace indentation
  bool trace = false; // trace enabled if true

public:
  bool trace_enabled();
  void enable_tracing();
  void disable_tracing();
  void jj_rescan_token();
  void jj_save(int index, int xla);


  JJTRattleState jjtree;
private:
  bool jj_done;
};
}
#endif
