#ifndef RATTLETOKENMANAGER_H
#define RATTLETOKENMANAGER_H
#include "stdio.h"
#include "JavaCC.h"
#include "CharStream.h"
#include "Token.h"
#include "ErrorHandler.h"
#include "TokenManager.h"
#include "RattleConstants.h"

namespace RattleLang {
class Rattle;

/** Token Manager. */
class RattleTokenManager : public TokenManager {
public:

  FILE *debugStream;
  void  setDebugStream(FILE *ds);
 int  jjStopAtPos(int pos, int kind);
 int  jjMoveStringLiteralDfa0_0();
 int  jjMoveStringLiteralDfa1_0(unsigned long long active0, unsigned long long active1);
 int  jjMoveStringLiteralDfa2_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1);
 int  jjMoveStringLiteralDfa3_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1);
 int  jjMoveStringLiteralDfa4_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1);
 int  jjMoveStringLiteralDfa5_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1);
 int  jjMoveStringLiteralDfa6_0(unsigned long long old0, unsigned long long active0, unsigned long long old1, unsigned long long active1);
 int  jjMoveStringLiteralDfa7_0(unsigned long long old1, unsigned long long active1);
int jjMoveNfa_0(int startState, int curPos);
bool jjCanMove_0(int hiByte, int i1, int i2, unsigned long long l1, unsigned long long l2);
bool jjCanMove_1(int hiByte, int i1, int i2, unsigned long long l1, unsigned long long l2);
Token * jjFillToken();

public:
    int curLexState;
    int jjnewStateCnt;
    int jjround;
    int jjmatchedPos;
    int jjmatchedKind;

Token * getNextToken();
#define jjCheckNAdd(state)\
{\
   if (jjrounds[state] != jjround)\
   {\
      jjstateSet[jjnewStateCnt++] = state;\
      jjrounds[state] = jjround;\
   }\
}
#define jjAddStates(start, end)\
{\
   for (int x = start; x <= end; x++) {\
      jjstateSet[jjnewStateCnt++] = jjnextStates[x];\
   } /*while (start++ != end);*/\
}
#define jjCheckNAddTwoStates(state1, state2)\
{\
   jjCheckNAdd(state1);\
   jjCheckNAdd(state2);\
}

#define jjCheckNAddStates(start, end)\
{\
   for (int x = start; x <= end; x++) {\
      jjCheckNAdd(jjnextStates[x]);\
   } /*while (start++ != end);*/\
}

#ifndef JAVACC_CHARSTREAM
#define JAVACC_CHARSTREAM CharStream
#endif

private:
  void ReInitRounds();

public:
  RattleTokenManager(JAVACC_CHARSTREAM *stream, int lexState = 0);
  virtual ~RattleTokenManager();
  void ReInit(JAVACC_CHARSTREAM *stream, int lexState = 0);
  void SwitchTo(int lexState);
  void clear();
  const JJSimpleString jjKindsForBitVector(int i, unsigned long long vec);
  const JJSimpleString jjKindsForStateVector(int lexState, int vec[], int start, int end);

  JAVACC_CHARSTREAM*        input_stream;
  int                       jjrounds[67];
  int                       jjstateSet[2 * 67];
  JJString                  jjimage;
  JJString                  image;
  int                       jjimageLen;
  int                       lengthOfMatch;
  JJChar                    curChar;
  TokenManagerErrorHandler* errorHandler = nullptr;

public: 
  void setErrorHandler(TokenManagerErrorHandler *eh) {
      if (errorHandler) delete errorHandler, errorHandler = nullptr;
      errorHandler = eh;
    }
    
};
}
#endif
