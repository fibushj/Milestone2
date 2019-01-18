
#ifndef MILESTONE2_LEXER_H
#define MILESTONE2_LEXER_H

#include <string>
#include "Matrix.h"
#define COMMA ','
#define SPACE ' '
#define NEW_LINE '\n'
using namespace std;

class MatrixFactory {
public:
    static ISearchable<MatrixEntry>* GenerateMatrix(string str);

};


#endif //MILESTONE2_LEXER_H
