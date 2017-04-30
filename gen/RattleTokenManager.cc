/* RattleTokenManager.cc */
#include "RattleTokenManager.h"
#include "TokenMgrError.h"
#include "SimpleNode.h"
namespace RattleLang {
static const unsigned long long jjbitVec0[] = {
   0x0ULL, 0x0ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL
};
static const unsigned long long jjbitVec1[] = {
   0x1ff00000fffffffeULL, 0xffffffffffffc000ULL, 0xffffffffULL, 0x600000000000000ULL
};
static const unsigned long long jjbitVec3[] = {
   0x0ULL, 0x0ULL, 0x0ULL, 0xff7fffffff7fffffULL
};
static const unsigned long long jjbitVec4[] = {
   0x0ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL
};
static const unsigned long long jjbitVec5[] = {
   0xffffffffffffffffULL, 0xffffffffffffffffULL, 0xffffULL, 0x0ULL
};
static const unsigned long long jjbitVec6[] = {
   0xffffffffffffffffULL, 0xffffffffffffffffULL, 0x0ULL, 0x0ULL
};
static const unsigned long long jjbitVec7[] = {
   0x3fffffffffffULL, 0x0ULL, 0x0ULL, 0x0ULL
};
static const int jjnextStates[] = {
   30, 31, 36, 37, 40, 41, 5, 49, 60, 61, 19, 20, 22, 10, 11, 13, 
   45, 47, 8, 1, 2, 5, 10, 11, 15, 13, 19, 20, 24, 22, 32, 33, 
   5, 40, 41, 5, 50, 51, 53, 56, 57, 59, 63, 64, 66, 3, 4, 12, 
   14, 16, 21, 23, 25, 34, 35, 38, 39, 42, 43, 
};
static JJChar jjstrLiteralChars_0[] = {0};
static JJChar jjstrLiteralChars_1[] = {0};
static JJChar jjstrLiteralChars_2[] = {0};
static JJChar jjstrLiteralChars_3[] = {0};
static JJChar jjstrLiteralChars_4[] = {0};
static JJChar jjstrLiteralChars_5[] = {0};
static JJChar jjstrLiteralChars_6[] = {0};

static JJChar jjstrLiteralChars_7[] = {0};
static JJChar jjstrLiteralChars_8[] = {0};
static JJChar jjstrLiteralChars_9[] = {0};
static JJChar jjstrLiteralChars_10[] = {0};
static JJChar jjstrLiteralChars_11[] = {0};
static JJChar jjstrLiteralChars_12[] = {0};
static JJChar jjstrLiteralChars_13[] = {0};
static JJChar jjstrLiteralChars_14[] = {0};
static JJChar jjstrLiteralChars_15[] = {0};
static JJChar jjstrLiteralChars_16[] = {0};
static JJChar jjstrLiteralChars_17[] = {0};
static JJChar jjstrLiteralChars_18[] = {0};
static JJChar jjstrLiteralChars_19[] = {0};
static JJChar jjstrLiteralChars_20[] = {0};

static JJChar jjstrLiteralChars_21[] = {0};
static JJChar jjstrLiteralChars_22[] = {0};
static JJChar jjstrLiteralChars_23[] = {0};
static JJChar jjstrLiteralChars_24[] = {0};
static JJChar jjstrLiteralChars_25[] = {0};
static JJChar jjstrLiteralChars_26[] = {0};
static JJChar jjstrLiteralChars_27[] = {0};
static JJChar jjstrLiteralChars_28[] = {0};
static JJChar jjstrLiteralChars_29[] = {0};
static JJChar jjstrLiteralChars_30[] = {0};
static JJChar jjstrLiteralChars_31[] = {0};
static JJChar jjstrLiteralChars_32[] = {0};
static JJChar jjstrLiteralChars_33[] = {0};

static JJChar jjstrLiteralChars_34[] = {0x28, 0};
static JJChar jjstrLiteralChars_35[] = {0x29, 0};

static JJChar jjstrLiteralChars_36[] = {0x7b, 0};
static JJChar jjstrLiteralChars_37[] = {0x7d, 0};

static JJChar jjstrLiteralChars_38[] = {0x5b, 0};
static JJChar jjstrLiteralChars_39[] = {0x5d, 0};

static JJChar jjstrLiteralChars_40[] = {0x3b, 0};
static JJChar jjstrLiteralChars_41[] = {0x2c, 0};

static JJChar jjstrLiteralChars_42[] = {0x2e, 0};
static JJChar jjstrLiteralChars_43[] = {0x2b, 0x2b, 0};

static JJChar jjstrLiteralChars_44[] = {0x2d, 0x2d, 0};
static JJChar jjstrLiteralChars_45[] = {0x3d, 0};

static JJChar jjstrLiteralChars_46[] = {0x2b, 0x3d, 0};
static JJChar jjstrLiteralChars_47[] = {0x2d, 0x3d, 0};

static JJChar jjstrLiteralChars_48[] = {0x40, 0x3d, 0};
static JJChar jjstrLiteralChars_49[] = {0x3d, 0x3d, 0};

static JJChar jjstrLiteralChars_50[] = {0x4f, 0x42, 0x4a, 0};
static JJChar jjstrLiteralChars_51[] = {0x3e, 0};

static JJChar jjstrLiteralChars_52[] = {0x3c, 0};
static JJChar jjstrLiteralChars_53[] = {0x3c, 0x3d, 0};

static JJChar jjstrLiteralChars_54[] = {0x3e, 0x3d, 0};
static JJChar jjstrLiteralChars_55[] = {0x21, 0x3d, 0};

static JJChar jjstrLiteralChars_56[] = {0x3f, 0};
static JJChar jjstrLiteralChars_57[] = {0x3a, 0};

static JJChar jjstrLiteralChars_58[] = {0x2b, 0};
static JJChar jjstrLiteralChars_59[] = {0x2d, 0};

static JJChar jjstrLiteralChars_60[] = {0x2a, 0};
static JJChar jjstrLiteralChars_61[] = {0x2f, 0};

static JJChar jjstrLiteralChars_62[] = {0x25, 0};
static JJChar jjstrLiteralChars_63[] = {0x20, 0x3a, 0x20, 0};

static JJChar jjstrLiteralChars_64[] = {0x66, 0x6e, 0x3c, 0};

static JJChar jjstrLiteralChars_65[] = {0x65, 0x78, 0x74, 0x65, 0x6e, 0x64, 0x73, 0x20, 0};
static JJChar jjstrLiteralChars_66[] = {0x20, 0x77, 0x68, 0x65, 0x72, 0x65, 0};

static JJChar jjstrLiteralChars_67[] = {0x2d, 0x3e, 0};
static JJChar jjstrLiteralChars_68[] = {0x3c, 0x3e, 0};
static const JJString jjstrLiteralImages[] = {
jjstrLiteralChars_0, 
jjstrLiteralChars_1, 
jjstrLiteralChars_2, 
jjstrLiteralChars_3, 
jjstrLiteralChars_4, 
jjstrLiteralChars_5, 
jjstrLiteralChars_6, 
jjstrLiteralChars_7, 
jjstrLiteralChars_8, 
jjstrLiteralChars_9, 
jjstrLiteralChars_10, 
jjstrLiteralChars_11, 
jjstrLiteralChars_12, 
jjstrLiteralChars_13, 
jjstrLiteralChars_14, 
jjstrLiteralChars_15, 
jjstrLiteralChars_16, 
jjstrLiteralChars_17, 
jjstrLiteralChars_18, 
jjstrLiteralChars_19, 
jjstrLiteralChars_20, 
jjstrLiteralChars_21, 
jjstrLiteralChars_22, 
jjstrLiteralChars_23, 
jjstrLiteralChars_24, 
jjstrLiteralChars_25, 
jjstrLiteralChars_26, 
jjstrLiteralChars_27, 
jjstrLiteralChars_28, 
jjstrLiteralChars_29, 
jjstrLiteralChars_30, 
jjstrLiteralChars_31, 
jjstrLiteralChars_32, 
jjstrLiteralChars_33, 
jjstrLiteralChars_34, 
jjstrLiteralChars_35, 
jjstrLiteralChars_36, 
jjstrLiteralChars_37, 
jjstrLiteralChars_38, 
jjstrLiteralChars_39, 
jjstrLiteralChars_40, 
jjstrLiteralChars_41, 
jjstrLiteralChars_42, 
jjstrLiteralChars_43, 
jjstrLiteralChars_44, 
jjstrLiteralChars_45, 
jjstrLiteralChars_46, 
jjstrLiteralChars_47, 
jjstrLiteralChars_48, 
jjstrLiteralChars_49, 
jjstrLiteralChars_50, 
jjstrLiteralChars_51, 
jjstrLiteralChars_52, 
jjstrLiteralChars_53, 
jjstrLiteralChars_54, 
jjstrLiteralChars_55, 
jjstrLiteralChars_56, 
jjstrLiteralChars_57, 
jjstrLiteralChars_58, 
jjstrLiteralChars_59, 
jjstrLiteralChars_60, 
jjstrLiteralChars_61, 
jjstrLiteralChars_62, 
jjstrLiteralChars_63, 
jjstrLiteralChars_64, 
jjstrLiteralChars_65, 
jjstrLiteralChars_66, 
jjstrLiteralChars_67, 
jjstrLiteralChars_68, 
};

/** Lexer state names. */
static const JJChar lexStateNames_arr_0[] = 
{0x44, 0x45, 0x46, 0x41, 0x55, 0x4c, 0x54, 0};
static const JJString lexStateNames[] = {
lexStateNames_arr_0, 
};
static const unsigned long long jjtoToken[] = {
   0xfffffffce8fffe01ULL, 0x1fULL, 
};
static const unsigned long long jjtoSkip[] = {
   0x1feULL, 0x0ULL, 
};
static const unsigned long long jjtoSpecial[] = {
   0x1c0ULL, 0x0ULL, 
};

  void  RattleTokenManager::setDebugStream(FILE *ds){ debugStream = ds; }

 int  RattleTokenManager::jjStopAtPos(int pos, int kind){
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   return pos + 1;
}

 int  RattleTokenManager::jjMoveStringLiteralDfa0_0(){
   switch(curChar)
   {
      case 9:
         jjmatchedKind = 2;
         return jjMoveNfa_0(0, 0);
      case 10:
         jjmatchedKind = 3;
         return jjMoveNfa_0(0, 0);
      case 12:
         jjmatchedKind = 5;
         return jjMoveNfa_0(0, 0);
      case 13:
         jjmatchedKind = 4;
         return jjMoveNfa_0(0, 0);
      case 32:
         jjmatchedKind = 1;
         return jjMoveStringLiteralDfa1_0(0x8000000000000000ULL, 0x4ULL);
      case 33:
         return jjMoveStringLiteralDfa1_0(0x80000000000000ULL, 0x0ULL);
      case 37:
         jjmatchedKind = 62;
         return jjMoveNfa_0(0, 0);
      case 40:
         jjmatchedKind = 34;
         return jjMoveNfa_0(0, 0);
      case 41:
         jjmatchedKind = 35;
         return jjMoveNfa_0(0, 0);
      case 42:
         jjmatchedKind = 60;
         return jjMoveNfa_0(0, 0);
      case 43:
         jjmatchedKind = 58;
         return jjMoveStringLiteralDfa1_0(0x480000000000ULL, 0x0ULL);
      case 44:
         jjmatchedKind = 41;
         return jjMoveNfa_0(0, 0);
      case 45:
         jjmatchedKind = 59;
         return jjMoveStringLiteralDfa1_0(0x900000000000ULL, 0x8ULL);
      case 46:
         jjmatchedKind = 42;
         return jjMoveNfa_0(0, 0);
      case 47:
         jjmatchedKind = 61;
         return jjMoveNfa_0(0, 0);
      case 58:
         jjmatchedKind = 57;
         return jjMoveNfa_0(0, 0);
      case 59:
         jjmatchedKind = 40;
         return jjMoveNfa_0(0, 0);
      case 60:
         jjmatchedKind = 52;
         return jjMoveStringLiteralDfa1_0(0x20000000000000ULL, 0x10ULL);
      case 61:
         jjmatchedKind = 45;
         return jjMoveStringLiteralDfa1_0(0x2000000000000ULL, 0x0ULL);
      case 62:
         jjmatchedKind = 51;
         return jjMoveStringLiteralDfa1_0(0x40000000000000ULL, 0x0ULL);
      case 63:
         jjmatchedKind = 56;
         return jjMoveNfa_0(0, 0);
      case 64:
         return jjMoveStringLiteralDfa1_0(0x1000000000000ULL, 0x0ULL);
      case 65:
         return jjMoveStringLiteralDfa1_0(0x8000ULL, 0x0ULL);
      case 67:
         return jjMoveStringLiteralDfa1_0(0x900000ULL, 0x0ULL);
      case 68:
         return jjMoveStringLiteralDfa1_0(0x80000ULL, 0x0ULL);
      case 69:
         return jjMoveStringLiteralDfa1_0(0x400ULL, 0x0ULL);
      case 70:
         return jjMoveStringLiteralDfa1_0(0x40800ULL, 0x0ULL);
      case 73:
         return jjMoveStringLiteralDfa1_0(0x200ULL, 0x0ULL);
      case 78:
         return jjMoveStringLiteralDfa1_0(0x10000ULL, 0x0ULL);
      case 79:
         return jjMoveStringLiteralDfa1_0(0x4000000004000ULL, 0x0ULL);
      case 80:
         return jjMoveStringLiteralDfa1_0(0x2000ULL, 0x0ULL);
      case 81:
         return jjMoveStringLiteralDfa1_0(0x400000ULL, 0x0ULL);
      case 82:
         return jjMoveStringLiteralDfa1_0(0x200000ULL, 0x0ULL);
      case 84:
         return jjMoveStringLiteralDfa1_0(0x20000ULL, 0x0ULL);
      case 87:
         return jjMoveStringLiteralDfa1_0(0x1000ULL, 0x0ULL);
      case 91:
         jjmatchedKind = 38;
         return jjMoveNfa_0(0, 0);
      case 93:
         jjmatchedKind = 39;
         return jjMoveNfa_0(0, 0);
      case 97:
         return jjMoveStringLiteralDfa1_0(0x8000ULL, 0x0ULL);
      case 99:
         return jjMoveStringLiteralDfa1_0(0x900000ULL, 0x0ULL);
      case 100:
         return jjMoveStringLiteralDfa1_0(0x80000ULL, 0x0ULL);
      case 101:
         return jjMoveStringLiteralDfa1_0(0x400ULL, 0x2ULL);
      case 102:
         return jjMoveStringLiteralDfa1_0(0x40800ULL, 0x1ULL);
      case 105:
         return jjMoveStringLiteralDfa1_0(0x200ULL, 0x0ULL);
      case 110:
         return jjMoveStringLiteralDfa1_0(0x10000ULL, 0x0ULL);
      case 111:
         return jjMoveStringLiteralDfa1_0(0x4000ULL, 0x0ULL);
      case 112:
         return jjMoveStringLiteralDfa1_0(0x2000ULL, 0x0ULL);
      case 113:
         return jjMoveStringLiteralDfa1_0(0x400000ULL, 0x0ULL);
      case 114:
         return jjMoveStringLiteralDfa1_0(0x200000ULL, 0x0ULL);
      case 116:
         return jjMoveStringLiteralDfa1_0(0x20000ULL, 0x0ULL);
      case 119:
         return jjMoveStringLiteralDfa1_0(0x1000ULL, 0x0ULL);
      case 123:
         jjmatchedKind = 36;
         return jjMoveNfa_0(0, 0);
      case 125:
         jjmatchedKind = 37;
         return jjMoveNfa_0(0, 0);
      default :
         return jjMoveNfa_0(0, 0);
   }
}

 int  RattleTokenManager::jjMoveStringLiteralDfa1_0(unsigned long long active0, unsigned long long active1){
   if (input_stream->endOfInput()) {
   return jjMoveNfa_0(0, 0);
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 43:
         if ((active0 & 0x80000000000ULL) != 0L)
         {
            jjmatchedKind = 43;
            jjmatchedPos = 1;
         }
         break;
      case 45:
         if ((active0 & 0x100000000000ULL) != 0L)
         {
            jjmatchedKind = 44;
            jjmatchedPos = 1;
         }
         break;
      case 58:
         return jjMoveStringLiteralDfa2_0(active0, 0x8000000000000000ULL, active1, 0L);
      case 61:
         if ((active0 & 0x400000000000ULL) != 0L)
         {
            jjmatchedKind = 46;
            jjmatchedPos = 1;
         }
         else if ((active0 & 0x800000000000ULL) != 0L)
         {
            jjmatchedKind = 47;
            jjmatchedPos = 1;
         }
         else if ((active0 & 0x1000000000000ULL) != 0L)
         {
            jjmatchedKind = 48;
            jjmatchedPos = 1;
         }
         else if ((active0 & 0x2000000000000ULL) != 0L)
         {
            jjmatchedKind = 49;
            jjmatchedPos = 1;
         }
         else if ((active0 & 0x20000000000000ULL) != 0L)
         {
            jjmatchedKind = 53;
            jjmatchedPos = 1;
         }
         else if ((active0 & 0x40000000000000ULL) != 0L)
         {
            jjmatchedKind = 54;
            jjmatchedPos = 1;
         }
         else if ((active0 & 0x80000000000000ULL) != 0L)
         {
            jjmatchedKind = 55;
            jjmatchedPos = 1;
         }
         break;
      case 62:
         if ((active1 & 0x8ULL) != 0L)
         {
            jjmatchedKind = 67;
            jjmatchedPos = 1;
         }
         else if ((active1 & 0x10ULL) != 0L)
         {
            jjmatchedKind = 68;
            jjmatchedPos = 1;
         }
         break;
      case 65:
         return jjMoveStringLiteralDfa2_0(active0, 0x40000ULL, active1, 0L);
      case 66:
         return jjMoveStringLiteralDfa2_0(active0, 0x4000000000000ULL, active1, 0L);
      case 69:
         return jjMoveStringLiteralDfa2_0(active0, 0x280000ULL, active1, 0L);
      case 70:
         if ((active0 & 0x200ULL) != 0L)
         {
            jjmatchedKind = 9;
            jjmatchedPos = 1;
         }
         break;
      case 72:
         return jjMoveStringLiteralDfa2_0(active0, 0x1000ULL, active1, 0L);
      case 76:
         return jjMoveStringLiteralDfa2_0(active0, 0x100400ULL, active1, 0L);
      case 78:
         return jjMoveStringLiteralDfa2_0(active0, 0x8000ULL, active1, 0L);
      case 79:
         return jjMoveStringLiteralDfa2_0(active0, 0x10800ULL, active1, 0L);
      case 82:
         if ((active0 & 0x4000ULL) != 0L)
         {
            jjmatchedKind = 14;
            jjmatchedPos = 1;
         }
         return jjMoveStringLiteralDfa2_0(active0, 0x822000ULL, active1, 0L);
      case 85:
         return jjMoveStringLiteralDfa2_0(active0, 0x400000ULL, active1, 0L);
      case 97:
         return jjMoveStringLiteralDfa2_0(active0, 0x40000ULL, active1, 0L);
      case 101:
         return jjMoveStringLiteralDfa2_0(active0, 0x280000ULL, active1, 0L);
      case 102:
         if ((active0 & 0x200ULL) != 0L)
         {
            jjmatchedKind = 9;
            jjmatchedPos = 1;
         }
         break;
      case 104:
         return jjMoveStringLiteralDfa2_0(active0, 0x1000ULL, active1, 0L);
      case 108:
         return jjMoveStringLiteralDfa2_0(active0, 0x100400ULL, active1, 0L);
      case 110:
         return jjMoveStringLiteralDfa2_0(active0, 0x8000ULL, active1, 0x1ULL);
      case 111:
         return jjMoveStringLiteralDfa2_0(active0, 0x10800ULL, active1, 0L);
      case 114:
         if ((active0 & 0x4000ULL) != 0L)
         {
            jjmatchedKind = 14;
            jjmatchedPos = 1;
         }
         return jjMoveStringLiteralDfa2_0(active0, 0x822000ULL, active1, 0L);
      case 117:
         return jjMoveStringLiteralDfa2_0(active0, 0x400000ULL, active1, 0L);
      case 119:
         return jjMoveStringLiteralDfa2_0(active0, 0L, active1, 0x4ULL);
      case 120:
         return jjMoveStringLiteralDfa2_0(active0, 0L, active1, 0x2ULL);
      default :
         break;
   }
   return jjMoveNfa_0(0, 1);
}

 int  RattleTokenManager::jjMoveStringLiteralDfa2_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1){
   if (((active0 &= old0) | (active1 &= old1)) == 0L)
      return jjMoveNfa_0(0, 1);
   if (input_stream->endOfInput()) {
   return jjMoveNfa_0(0, 1);
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 32:
         if ((active0 & 0x8000000000000000ULL) != 0L)
         {
            jjmatchedKind = 63;
            jjmatchedPos = 2;
         }
         break;
      case 60:
         if ((active1 & 0x1ULL) != 0L)
         {
            jjmatchedKind = 64;
            jjmatchedPos = 2;
         }
         break;
      case 65:
         return jjMoveStringLiteralDfa3_0(active0, 0x100000ULL, active1, 0L);
      case 68:
         if ((active0 & 0x8000ULL) != 0L)
         {
            jjmatchedKind = 15;
            jjmatchedPos = 2;
         }
         break;
      case 69:
         return jjMoveStringLiteralDfa3_0(active0, 0x800000ULL, active1, 0L);
      case 70:
         if ((active0 & 0x80000ULL) != 0L)
         {
            jjmatchedKind = 19;
            jjmatchedPos = 2;
         }
         break;
      case 73:
         return jjMoveStringLiteralDfa3_0(active0, 0x403000ULL, active1, 0L);
      case 74:
         if ((active0 & 0x4000000000000ULL) != 0L)
         {
            jjmatchedKind = 50;
            jjmatchedPos = 2;
         }
         break;
      case 76:
         return jjMoveStringLiteralDfa3_0(active0, 0x40000ULL, active1, 0L);
      case 82:
         if ((active0 & 0x800ULL) != 0L)
         {
            jjmatchedKind = 11;
            jjmatchedPos = 2;
         }
         break;
      case 83:
         return jjMoveStringLiteralDfa3_0(active0, 0x400ULL, active1, 0L);
      case 84:
         if ((active0 & 0x10000ULL) != 0L)
         {
            jjmatchedKind = 16;
            jjmatchedPos = 2;
         }
         return jjMoveStringLiteralDfa3_0(active0, 0x200000ULL, active1, 0L);
      case 85:
         return jjMoveStringLiteralDfa3_0(active0, 0x20000ULL, active1, 0L);
      case 97:
         return jjMoveStringLiteralDfa3_0(active0, 0x100000ULL, active1, 0L);
      case 100:
         if ((active0 & 0x8000ULL) != 0L)
         {
            jjmatchedKind = 15;
            jjmatchedPos = 2;
         }
         break;
      case 101:
         return jjMoveStringLiteralDfa3_0(active0, 0x800000ULL, active1, 0L);
      case 102:
         if ((active0 & 0x80000ULL) != 0L)
         {
            jjmatchedKind = 19;
            jjmatchedPos = 2;
         }
         break;
      case 104:
         return jjMoveStringLiteralDfa3_0(active0, 0L, active1, 0x4ULL);
      case 105:
         return jjMoveStringLiteralDfa3_0(active0, 0x403000ULL, active1, 0L);
      case 108:
         return jjMoveStringLiteralDfa3_0(active0, 0x40000ULL, active1, 0L);
      case 114:
         if ((active0 & 0x800ULL) != 0L)
         {
            jjmatchedKind = 11;
            jjmatchedPos = 2;
         }
         break;
      case 115:
         return jjMoveStringLiteralDfa3_0(active0, 0x400ULL, active1, 0L);
      case 116:
         if ((active0 & 0x10000ULL) != 0L)
         {
            jjmatchedKind = 16;
            jjmatchedPos = 2;
         }
         return jjMoveStringLiteralDfa3_0(active0, 0x200000ULL, active1, 0x2ULL);
      case 117:
         return jjMoveStringLiteralDfa3_0(active0, 0x20000ULL, active1, 0L);
      default :
         break;
   }
   return jjMoveNfa_0(0, 2);
}

 int  RattleTokenManager::jjMoveStringLiteralDfa3_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1){
   if (((active0 &= old0) | (active1 &= old1)) == 0L)
      return jjMoveNfa_0(0, 2);
   if (input_stream->endOfInput()) {
   return jjMoveNfa_0(0, 2);
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 65:
         return jjMoveStringLiteralDfa4_0(active0, 0x800000ULL, active1, 0L);
      case 69:
         if ((active0 & 0x400ULL) != 0L)
         {
            jjmatchedKind = 10;
            jjmatchedPos = 3;
         }
         else if ((active0 & 0x20000ULL) != 0L)
         {
            jjmatchedKind = 17;
            jjmatchedPos = 3;
         }
         break;
      case 76:
         return jjMoveStringLiteralDfa4_0(active0, 0x1000ULL, active1, 0L);
      case 78:
         return jjMoveStringLiteralDfa4_0(active0, 0x2000ULL, active1, 0L);
      case 83:
         return jjMoveStringLiteralDfa4_0(active0, 0x140000ULL, active1, 0L);
      case 84:
         if ((active0 & 0x400000ULL) != 0L)
         {
            jjmatchedKind = 22;
            jjmatchedPos = 3;
         }
         break;
      case 85:
         return jjMoveStringLiteralDfa4_0(active0, 0x200000ULL, active1, 0L);
      case 97:
         return jjMoveStringLiteralDfa4_0(active0, 0x800000ULL, active1, 0L);
      case 101:
         if ((active0 & 0x400ULL) != 0L)
         {
            jjmatchedKind = 10;
            jjmatchedPos = 3;
         }
         else if ((active0 & 0x20000ULL) != 0L)
         {
            jjmatchedKind = 17;
            jjmatchedPos = 3;
         }
         return jjMoveStringLiteralDfa4_0(active0, 0L, active1, 0x6ULL);
      case 108:
         return jjMoveStringLiteralDfa4_0(active0, 0x1000ULL, active1, 0L);
      case 110:
         return jjMoveStringLiteralDfa4_0(active0, 0x2000ULL, active1, 0L);
      case 115:
         return jjMoveStringLiteralDfa4_0(active0, 0x140000ULL, active1, 0L);
      case 116:
         if ((active0 & 0x400000ULL) != 0L)
         {
            jjmatchedKind = 22;
            jjmatchedPos = 3;
         }
         break;
      case 117:
         return jjMoveStringLiteralDfa4_0(active0, 0x200000ULL, active1, 0L);
      default :
         break;
   }
   return jjMoveNfa_0(0, 3);
}

 int  RattleTokenManager::jjMoveStringLiteralDfa4_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1){
   if (((active0 &= old0) | (active1 &= old1)) == 0L)
      return jjMoveNfa_0(0, 3);
   if (input_stream->endOfInput()) {
   return jjMoveNfa_0(0, 3);
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 69:
         if ((active0 & 0x1000ULL) != 0L)
         {
            jjmatchedKind = 12;
            jjmatchedPos = 4;
         }
         else if ((active0 & 0x40000ULL) != 0L)
         {
            jjmatchedKind = 18;
            jjmatchedPos = 4;
         }
         break;
      case 82:
         return jjMoveStringLiteralDfa5_0(active0, 0x200000ULL, active1, 0L);
      case 83:
         if ((active0 & 0x100000ULL) != 0L)
         {
            jjmatchedKind = 20;
            jjmatchedPos = 4;
         }
         break;
      case 84:
         if ((active0 & 0x2000ULL) != 0L)
         {
            jjmatchedKind = 13;
            jjmatchedPos = 4;
         }
         return jjMoveStringLiteralDfa5_0(active0, 0x800000ULL, active1, 0L);
      case 101:
         if ((active0 & 0x1000ULL) != 0L)
         {
            jjmatchedKind = 12;
            jjmatchedPos = 4;
         }
         else if ((active0 & 0x40000ULL) != 0L)
         {
            jjmatchedKind = 18;
            jjmatchedPos = 4;
         }
         break;
      case 110:
         return jjMoveStringLiteralDfa5_0(active0, 0L, active1, 0x2ULL);
      case 114:
         return jjMoveStringLiteralDfa5_0(active0, 0x200000ULL, active1, 0x4ULL);
      case 115:
         if ((active0 & 0x100000ULL) != 0L)
         {
            jjmatchedKind = 20;
            jjmatchedPos = 4;
         }
         break;
      case 116:
         if ((active0 & 0x2000ULL) != 0L)
         {
            jjmatchedKind = 13;
            jjmatchedPos = 4;
         }
         return jjMoveStringLiteralDfa5_0(active0, 0x800000ULL, active1, 0L);
      default :
         break;
   }
   return jjMoveNfa_0(0, 4);
}

 int  RattleTokenManager::jjMoveStringLiteralDfa5_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1){
   if (((active0 &= old0) | (active1 &= old1)) == 0L)
      return jjMoveNfa_0(0, 4);
   if (input_stream->endOfInput()) {
   return jjMoveNfa_0(0, 4);
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 69:
         if ((active0 & 0x800000ULL) != 0L)
         {
            jjmatchedKind = 23;
            jjmatchedPos = 5;
         }
         break;
      case 78:
         if ((active0 & 0x200000ULL) != 0L)
         {
            jjmatchedKind = 21;
            jjmatchedPos = 5;
         }
         break;
      case 100:
         return jjMoveStringLiteralDfa6_0(active0, 0L, active1, 0x2ULL);
      case 101:
         if ((active0 & 0x800000ULL) != 0L)
         {
            jjmatchedKind = 23;
            jjmatchedPos = 5;
         }
         else if ((active1 & 0x4ULL) != 0L)
         {
            jjmatchedKind = 66;
            jjmatchedPos = 5;
         }
         break;
      case 110:
         if ((active0 & 0x200000ULL) != 0L)
         {
            jjmatchedKind = 21;
            jjmatchedPos = 5;
         }
         break;
      default :
         break;
   }
   return jjMoveNfa_0(0, 5);
}

 int  RattleTokenManager::jjMoveStringLiteralDfa6_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1){
   if (((active0 &= old0) | (active1 &= old1)) == 0L)
      return jjMoveNfa_0(0, 5);
   if (input_stream->endOfInput()) {
   return jjMoveNfa_0(0, 5);
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 115:
         return jjMoveStringLiteralDfa7_0(active1, 0x2ULL);
      default :
         break;
   }
   return jjMoveNfa_0(0, 6);
}

 int  RattleTokenManager::jjMoveStringLiteralDfa7_0(unsigned long long old1, unsigned long long active1){
   if (((active1 &= old1)) == 0L)
      return jjMoveNfa_0(0, 6);
   if (input_stream->endOfInput()) {
   return jjMoveNfa_0(0, 6);
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 32:
         if ((active1 & 0x2ULL) != 0L)
         {
            jjmatchedKind = 65;
            jjmatchedPos = 7;
         }
         break;
      default :
         break;
   }
   return jjMoveNfa_0(0, 7);
}

int RattleTokenManager::jjMoveNfa_0(int startState, int curPos){
   int strKind = jjmatchedKind;
   int strPos = jjmatchedPos;
   int seenUpto;
   input_stream->backup(seenUpto = curPos + 1);
   assert(!input_stream->endOfInput());
   curChar = input_stream->readChar();
   curPos = 0;
   int startsAt = 0;
   jjnewStateCnt = 67;
   int i = 1;
   jjstateSet[0] = startState;
   int kind = 0x7fffffff;
   for (;;)
   {
      if (++jjround == 0x7fffffff)
         ReInitRounds();
      if (curChar < 64)
      {
         unsigned long long l = 1ULL << curChar;
         (void)l;
         do
         {
            switch(jjstateSet[--i])
            {
               case 0:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(0, 6); }
                  else if (curChar == 47)
                     { jjAddStates(7, 9); }
                  else if (curChar == 36)
                  {
                     if (kind > 31)
                        kind = 31;
                     { jjCheckNAdd(28); }
                  }
                  else if (curChar == 39)
                     { jjCheckNAddStates(10, 12); }
                  else if (curChar == 34)
                     { jjCheckNAddStates(13, 15); }
                  else if (curChar == 46)
                     { jjCheckNAdd(1); }
                  if ((0x3fe000000000000ULL & l) != 0L)
                  {
                     if (kind > 27)
                        kind = 27;
                     { jjCheckNAddTwoStates(7, 8); }
                  }
                  else if (curChar == 48)
                  {
                     if (kind > 27)
                        kind = 27;
                     { jjCheckNAddStates(16, 18); }
                  }
                  break;
               case 1:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddStates(19, 21); }
                  break;
               case 3:
                  if ((0x280000000000ULL & l) != 0L)
                     { jjCheckNAdd(4); }
                  break;
               case 4:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddTwoStates(4, 5); }
                  break;
               case 6:
                  if ((0x3fe000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddTwoStates(7, 8); }
                  break;
               case 7:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddTwoStates(7, 8); }
                  break;
               case 9:
                  if (curChar == 34)
                     { jjCheckNAddStates(13, 15); }
                  break;
               case 10:
                  if ((0xfffffffbffffdbffULL & l) != 0L)
                     { jjCheckNAddStates(13, 15); }
                  break;
               case 12:
                  if ((0x8400000000ULL & l) != 0L)
                     { jjCheckNAddStates(13, 15); }
                  break;
               case 13:
                  if (curChar == 34 && kind > 29)
                     kind = 29;
                  break;
               case 14:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(22, 25); }
                  break;
               case 15:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(13, 15); }
                  break;
               case 16:
                  if ((0xf000000000000ULL & l) != 0L)
                     jjstateSet[jjnewStateCnt++] = 17;
                  break;
               case 17:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAdd(15); }
                  break;
               case 18:
                  if (curChar == 39)
                     { jjCheckNAddStates(10, 12); }
                  break;
               case 19:
                  if ((0xffffff7fffffdbffULL & l) != 0L)
                     { jjCheckNAddStates(10, 12); }
                  break;
               case 21:
                  if ((0x8400000000ULL & l) != 0L)
                     { jjCheckNAddStates(10, 12); }
                  break;
               case 22:
                  if (curChar == 39 && kind > 30)
                     kind = 30;
                  break;
               case 23:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(26, 29); }
                  break;
               case 24:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(10, 12); }
                  break;
               case 25:
                  if ((0xf000000000000ULL & l) != 0L)
                     jjstateSet[jjnewStateCnt++] = 26;
                  break;
               case 26:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAdd(24); }
                  break;
               case 27:
                  if (curChar != 36)
                     break;
                  if (kind > 31)
                     kind = 31;
                  { jjCheckNAdd(28); }
                  break;
               case 28:
                  if ((0x3ff001800000000ULL & l) == 0L)
                     break;
                  if (kind > 31)
                     kind = 31;
                  { jjCheckNAdd(28); }
                  break;
               case 29:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(0, 6); }
                  break;
               case 30:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddTwoStates(30, 31); }
                  break;
               case 31:
                  if (curChar != 46)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddStates(30, 32); }
                  break;
               case 32:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddStates(30, 32); }
                  break;
               case 34:
                  if ((0x280000000000ULL & l) != 0L)
                     { jjCheckNAdd(35); }
                  break;
               case 35:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddTwoStates(35, 5); }
                  break;
               case 36:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddTwoStates(36, 37); }
                  break;
               case 38:
                  if ((0x280000000000ULL & l) != 0L)
                     { jjCheckNAdd(39); }
                  break;
               case 39:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddTwoStates(39, 5); }
                  break;
               case 40:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(33, 35); }
                  break;
               case 42:
                  if ((0x280000000000ULL & l) != 0L)
                     { jjCheckNAdd(43); }
                  break;
               case 43:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddTwoStates(43, 5); }
                  break;
               case 44:
                  if (curChar != 48)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddStates(16, 18); }
                  break;
               case 46:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddTwoStates(46, 8); }
                  break;
               case 47:
                  if ((0xff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddTwoStates(47, 8); }
                  break;
               case 48:
                  if (curChar == 47)
                     { jjAddStates(7, 9); }
                  break;
               case 49:
                  if (curChar == 47)
                     { jjCheckNAddStates(36, 38); }
                  break;
               case 50:
                  if ((0xffffffffffffdbffULL & l) != 0L)
                     { jjCheckNAddStates(36, 38); }
                  break;
               case 51:
                  if ((0x2400ULL & l) != 0L && kind > 6)
                     kind = 6;
                  break;
               case 52:
                  if (curChar == 10 && kind > 6)
                     kind = 6;
                  break;
               case 53:
                  if (curChar == 13)
                     jjstateSet[jjnewStateCnt++] = 52;
                  break;
               case 54:
                  if (curChar == 42)
                     { jjCheckNAddTwoStates(55, 56); }
                  break;
               case 55:
                  if ((0xfffffbffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(55, 56); }
                  break;
               case 56:
                  if (curChar == 42)
                     { jjCheckNAddStates(39, 41); }
                  break;
               case 57:
                  if ((0xffff7bffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(58, 56); }
                  break;
               case 58:
                  if ((0xfffffbffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(58, 56); }
                  break;
               case 59:
                  if (curChar == 47 && kind > 7)
                     kind = 7;
                  break;
               case 60:
                  if (curChar == 42)
                     jjstateSet[jjnewStateCnt++] = 54;
                  break;
               case 61:
                  if (curChar == 42)
                     { jjCheckNAddTwoStates(62, 63); }
                  break;
               case 62:
                  if ((0xfffffbffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(62, 63); }
                  break;
               case 63:
                  if (curChar == 42)
                     { jjCheckNAddStates(42, 44); }
                  break;
               case 64:
                  if ((0xffff7bffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(65, 63); }
                  break;
               case 65:
                  if ((0xfffffbffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(65, 63); }
                  break;
               case 66:
                  if (curChar == 47 && kind > 8)
                     kind = 8;
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else if (curChar < 128)
      {
         unsigned long long l = 1ULL << (curChar & 077);
         (void)l;
         do
         {
            switch(jjstateSet[--i])
            {
               case 0:
               case 28:
                  if ((0x7fffffe87fffffeULL & l) == 0L)
                     break;
                  if (kind > 31)
                     kind = 31;
                  { jjCheckNAdd(28); }
                  break;
               case 2:
                  if ((0x2000000020ULL & l) != 0L)
                     { jjAddStates(45, 46); }
                  break;
               case 5:
                  if ((0x5000000050ULL & l) != 0L && kind > 27)
                     kind = 27;
                  break;
               case 8:
                  if ((0x100000001000ULL & l) != 0L && kind > 27)
                     kind = 27;
                  break;
               case 10:
                  if ((0xffffffffefffffffULL & l) != 0L)
                     { jjCheckNAddStates(13, 15); }
                  break;
               case 11:
                  if (curChar == 92)
                     { jjAddStates(47, 49); }
                  break;
               case 12:
                  if ((0x14404410000000ULL & l) != 0L)
                     { jjCheckNAddStates(13, 15); }
                  break;
               case 19:
                  if ((0xffffffffefffffffULL & l) != 0L)
                     { jjCheckNAddStates(10, 12); }
                  break;
               case 20:
                  if (curChar == 92)
                     { jjAddStates(50, 52); }
                  break;
               case 21:
                  if ((0x14404410000000ULL & l) != 0L)
                     { jjCheckNAddStates(10, 12); }
                  break;
               case 33:
                  if ((0x2000000020ULL & l) != 0L)
                     { jjAddStates(53, 54); }
                  break;
               case 37:
                  if ((0x2000000020ULL & l) != 0L)
                     { jjAddStates(55, 56); }
                  break;
               case 41:
                  if ((0x2000000020ULL & l) != 0L)
                     { jjAddStates(57, 58); }
                  break;
               case 45:
                  if ((0x100000001000000ULL & l) != 0L)
                     { jjCheckNAdd(46); }
                  break;
               case 46:
                  if ((0x7e0000007eULL & l) == 0L)
                     break;
                  if (kind > 27)
                     kind = 27;
                  { jjCheckNAddTwoStates(46, 8); }
                  break;
               case 50:
                  { jjAddStates(36, 38); }
                  break;
               case 55:
                  { jjCheckNAddTwoStates(55, 56); }
                  break;
               case 57:
               case 58:
                  { jjCheckNAddTwoStates(58, 56); }
                  break;
               case 62:
                  { jjCheckNAddTwoStates(62, 63); }
                  break;
               case 64:
               case 65:
                  { jjCheckNAddTwoStates(65, 63); }
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else
      {
         int hiByte = (curChar >> 8);
         int i1 = hiByte >> 6;
         unsigned long long l1 = 1ULL << (hiByte & 077);
         int i2 = (curChar & 0xff) >> 6;
         unsigned long long l2 = 1ULL << (curChar & 077);
         do
         {
            switch(jjstateSet[--i])
            {
               case 0:
               case 28:
                  if (!jjCanMove_1(hiByte, i1, i2, l1, l2))
                     break;
                  if (kind > 31)
                     kind = 31;
                  { jjCheckNAdd(28); }
                  break;
               case 10:
                  if (jjCanMove_0(hiByte, i1, i2, l1, l2))
                     { jjAddStates(13, 15); }
                  break;
               case 19:
                  if (jjCanMove_0(hiByte, i1, i2, l1, l2))
                     { jjAddStates(10, 12); }
                  break;
               case 50:
                  if (jjCanMove_0(hiByte, i1, i2, l1, l2))
                     { jjAddStates(36, 38); }
                  break;
               case 55:
                  if (jjCanMove_0(hiByte, i1, i2, l1, l2))
                     { jjCheckNAddTwoStates(55, 56); }
                  break;
               case 57:
               case 58:
                  if (jjCanMove_0(hiByte, i1, i2, l1, l2))
                     { jjCheckNAddTwoStates(58, 56); }
                  break;
               case 62:
                  if (jjCanMove_0(hiByte, i1, i2, l1, l2))
                     { jjCheckNAddTwoStates(62, 63); }
                  break;
               case 64:
               case 65:
                  if (jjCanMove_0(hiByte, i1, i2, l1, l2))
                     { jjCheckNAddTwoStates(65, 63); }
                  break;
               default : if (i1 == 0 || l1 == 0 || i2 == 0 ||  l2 == 0) break; else break;
            }
         } while(i != startsAt);
      }
      if (kind != 0x7fffffff)
      {
         jjmatchedKind = kind;
         jjmatchedPos = curPos;
         kind = 0x7fffffff;
      }
      ++curPos;
      if ((i = jjnewStateCnt), (jjnewStateCnt = startsAt), (i == (startsAt = 67 - startsAt)))
         break;
      if (input_stream->endOfInput()) { break; }
      curChar = input_stream->readChar();
   }
   if (jjmatchedPos > strPos)
      return curPos;

   int toRet = MAX(curPos, seenUpto);

   if (curPos < toRet)
      for (i = toRet - MIN(curPos, seenUpto); i-- > 0; )
        {  assert(!input_stream->endOfInput());
           curChar = input_stream->readChar(); }

   if (jjmatchedPos < strPos)
   {
      jjmatchedKind = strKind;
      jjmatchedPos = strPos;
   }
   else if (jjmatchedPos == strPos && jjmatchedKind > strKind)
      jjmatchedKind = strKind;

   return toRet;
}

bool RattleTokenManager::jjCanMove_0(int hiByte, int i1, int i2, unsigned long long l1, unsigned long long l2){
   switch(hiByte)
   {
      case 0:
         return ((jjbitVec0[i2] & l2) != 0L);
      default :
         return false;
   }
}

bool RattleTokenManager::jjCanMove_1(int hiByte, int i1, int i2, unsigned long long l1, unsigned long long l2){
   switch(hiByte)
   {
      case 0:
         return ((jjbitVec3[i2] & l2) != 0L);
      case 48:
         return ((jjbitVec4[i2] & l2) != 0L);
      case 49:
         return ((jjbitVec5[i2] & l2) != 0L);
      case 51:
         return ((jjbitVec6[i2] & l2) != 0L);
      case 61:
         return ((jjbitVec7[i2] & l2) != 0L);
      default :
         if ((jjbitVec1[i1] & l1) != 0L)
            return true;
         return false;
   }
}

/** Token literal values. */

Token * RattleTokenManager::jjFillToken(){
   Token *t;
   JJString curTokenImage;
   int beginLine   = -1;
   int endLine     = -1;
   int beginColumn = -1;
   int endColumn   = -1;
   JJString im = jjstrLiteralImages[jjmatchedKind];
   curTokenImage = (im.length() == 0) ? input_stream->GetImage() : im;
   if (input_stream->getTrackLineColumn()) {
     beginLine = input_stream->getBeginLine();
     beginColumn = input_stream->getBeginColumn();
     endLine = input_stream->getEndLine();
     endColumn = input_stream->getEndColumn();
   }
   t = Token::newToken(jjmatchedKind);
   t->kind = jjmatchedKind;
   t->image = curTokenImage;
   t->specialToken = nullptr;
   t->next = nullptr;

   if (input_stream->getTrackLineColumn()) {
   t->beginLine = beginLine;
   t->endLine = endLine;
   t->beginColumn = beginColumn;
   t->endColumn = endColumn;
   }

   return t;
}
const int defaultLexState = 0;
/** Get the next Token. */

Token * RattleTokenManager::getNextToken(){
  Token *specialToken = nullptr;
  Token *matchedToken = nullptr;
  int curPos = 0;

  for (;;)
  {
   EOFLoop: 
   if (input_stream->endOfInput())
   {
      jjmatchedKind = 0;
      jjmatchedPos = -1;
      matchedToken = jjFillToken();
      matchedToken->specialToken = specialToken;
      return matchedToken;
   }
   curChar = input_stream->BeginToken();

   jjmatchedKind = 0x7fffffff;
   jjmatchedPos = 0;
   curPos = jjMoveStringLiteralDfa0_0();
   if (jjmatchedKind != 0x7fffffff)
   {
      if (jjmatchedPos + 1 < curPos)
         input_stream->backup(curPos - jjmatchedPos - 1);
      if ((jjtoToken[jjmatchedKind >> 6] & (1ULL << (jjmatchedKind & 077))) != 0L)
      {
         matchedToken = jjFillToken();
         matchedToken->specialToken = specialToken;
         return matchedToken;
      }
      else
      {
         if ((jjtoSpecial[jjmatchedKind >> 6] & (1ULL << (jjmatchedKind & 077))) != 0L)
         {
            matchedToken = jjFillToken();
            if (specialToken == nullptr)
               specialToken = matchedToken;
            else
            {
               matchedToken->specialToken = specialToken;
               specialToken = (specialToken->next = matchedToken);
            }
         }
         goto EOFLoop;
      }
   }
   int error_line = input_stream->getEndLine();
   int error_column = input_stream->getEndColumn();
   JJString error_after;
   bool EOFSeen = false;
   if (input_stream->endOfInput()) {
      EOFSeen = true;
      error_after = curPos <= 1 ? EMPTY : input_stream->GetImage();
      if (curChar == '\n' || curChar == '\r') {
         error_line++;
         error_column = 0;
      }
      else
         error_column++;
   }
   if (!EOFSeen) {
      error_after = curPos <= 1 ? EMPTY : input_stream->GetImage();
   }
   errorHandler->lexicalError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, this);
  }
}

  /** Reinitialise parser. */
  void RattleTokenManager::ReInit(JAVACC_CHARSTREAM *stream, int lexState) {
    clear();
    jjmatchedPos = jjnewStateCnt = 0;
    curLexState = lexState;
    input_stream = stream;
    ReInitRounds();
    debugStream = stdout; // init
    SwitchTo(lexState);
    errorHandler = new TokenManagerErrorHandler();
  }

  void RattleTokenManager::ReInitRounds() {
    int i;
    jjround = 0x80000001;
    for (i = 67; i-- > 0;)
      jjrounds[i] = 0x80000000;
  }

  /** Switch to specified lex state. */
  void RattleTokenManager::SwitchTo(int lexState) {
    if (lexState >= 1 || lexState < 0) {
      JJString message;
#ifdef WIDE_CHAR
      message += L"Error: Ignoring invalid lexical state : ";
      message += lexState; message += L". State unchanged.";
#else
      message += "Error: Ignoring invalid lexical state : ";
      message += lexState; message += ". State unchanged.";
#endif
      throw new TokenMgrError(message, INVALID_LEXICAL_STATE);
    } else
      curLexState = lexState;
  }

  /** Constructor. */
  RattleTokenManager::RattleTokenManager (JAVACC_CHARSTREAM *stream, int lexState)
  {
    input_stream = nullptr;
    ReInit(stream, lexState);
  }

  // Destructor
  RattleTokenManager::~RattleTokenManager () {
    clear();
  }

  // clear
  void RattleTokenManager::clear() {
    //Since input_stream was generated outside of TokenManager
    //TokenManager should not take care of deleting it
    //if (input_stream) delete input_stream;
    if (errorHandler) delete errorHandler, errorHandler = nullptr;    
  }


}
