/* Generated By:JavaCC: Do not edit this line. Token.cc Version 7.0 */
/* JavaCCOptions:STATIC=false,SUPPORT_CLASS_VISIBILITY_PUBLIC=true,TOKEN_INCLUDES=,TOKEN_EXTENDS= */
#include "Token.h"

namespace RattleLang {

/**
 * Describes the input token stream.
 */

  /**
   * An optional attribute value of the Token.
   * Tokens which are not used as syntactic sugar will often contain
   * meaningful values that will be used later on by the compiler or
   * interpreter. This attribute value is often different from the image.
   * Any subclass of Token that actually wants to return a non-NULL value can
   * override this method as appropriate.
   */
  void * Token::getValue() {
    return nullptr;
  }

  /**
   * No-argument constructor
   */
  Token::Token() :
  	beginLine(0), beginColumn(0), endLine(0), endColumn(0)
  {
    this->next = nullptr;
    this->specialToken = nullptr;
  }

  /**
   * Constructs a new token for the specified Image.
   */
  Token::Token(int kind) :
  	beginLine(0), beginColumn(0), endLine(0), endColumn(0) 
  {
    this->kind = kind;
    this->next = nullptr;
    this->specialToken = nullptr;
  }

  /**
   * Constructs a new token for the specified Image and Kind.
   */
  Token::Token(int kind, const JJString& image)
  	: beginLine(0), beginColumn(0), endLine(0), endColumn(0) 
  {
    this->kind = kind;
    this->image = image;
    this->next = nullptr;
    this->specialToken = nullptr;
  }

  /**
   * Returns the image.
   */
  const JJString& Token::toString()
  {
    return image;
  }

  /**
   * Returns a new Token object, by default. However, if you want, you
   * can create and return subclass objects based on the value of ofKind.
   * Simply add the cases to the switch for all those special cases.
   * For example, if you have a subclass of Token called IDToken that
   * you want to create if ofKind is ID, simply add something like :
   *
   *    case MyParserConstants.ID : return new IDToken(ofKind, image);
   *
   * to the following switch statement. Then you can cast matchedToken
   * variable to the appropriate type and use sit in your lexical actions.
   */
  Token *Token::newToken(int ofKind, const JJString& image)
  {
    switch(ofKind)
    {
      default : return new Token(ofKind, image);
    }
  }

  Token *Token::newToken(int ofKind)
  {
    return newToken(ofKind, "");
  }

  Token::~Token() {
    if (specialToken) delete specialToken;
    this->kind = 0;
    this->next = nullptr;
    this->specialToken = nullptr;
  }

}
/* JavaCC - OriginalChecksum=5704344de3ae5952e02b2b66544eca3d (do not edit this line) */
