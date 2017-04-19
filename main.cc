#include <fstream>
#include <iomanip>
#include <iostream>



#include "gen/RattleConstants.h"
#include "gen/CharStream.h"
#include "gen/RattleVisitor.h"
#include "gen/RattleTokenManager.h"
#include "gen/ParseException.h"
#include "gen/Rattle.h"
#include "transpiler/Parser.h"

using namespace RattleLang;
using namespace std;


JAVACC_STRING_TYPE ReadFileFully(char *file_name) {
  JAVACC_STRING_TYPE s;
  ifstream fp_in;
  fp_in.open(file_name, ios::in);


  if (fp_in.is_open()) { 
    while (!fp_in.eof()) {
    s += fp_in.get();
    }
  }

  return s;
}


int main(int argc, char **argv) {

    if (argc < 2) {
      cout << "Usage: rattle <inputfile>" << endl;
      exit(1);
    }

    JAVACC_STRING_TYPE s = ReadFileFully(argv[1]);
    CharStream *stream = new CharStream(s.c_str(), s.size() - 1, 1, 1);
    RattleTokenManager *scanner = new RattleTokenManager(stream);
    Rattle parser(scanner);
    //parser.set ErrorHandler(new MyErrorHandler());
    ASTCode* code;
    try {
        ASTCode* code = parser.code();
        Parser* nodeVisitor = new Parser(code);
        StateMachineParserDecorator<Parser>* visitorDecorator = new StateMachineParserDecorator<Parser>(nodeVisitor);
        visitorDecorator->StartParsing(code);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

}