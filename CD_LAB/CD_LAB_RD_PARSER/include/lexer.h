#include "common.h"
#include "filehandler.h"

#ifndef lexer_h
#define lexer_h

#define isAlphabet(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define isDigit(c) ((c >= '0' && c <= '9'))
#define isAlphaNum(c) (isAlphabet(c) || isDigit(c))
#define isAlphaNumUnder(c) (isAlphabet(c) || isDigit(c) || c == '_')
#define isArith(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
#define isSpecial(c) (c == ';' || c == ',' || c == ':' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == '?' || c == '@')
#define isRel(c) (c == '<' || c == '>' || c == '!' || c == '=')
#define isWhite(c) (c == ' ' || c == '\t' || c == '\n')

int isKeyword(char* lexeme);

Token getNextToken(InputStream* stream);
void printToken(Token* tkn, int row, int col);

#endif //lexer_h