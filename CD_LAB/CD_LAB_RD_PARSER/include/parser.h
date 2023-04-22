#include "lexer.h"
#include <string.h>

#ifndef parser_h
#define parser_h

/*
 * Grammar:
 * --------------------------------------------------------------
 * Program -> main() { declarations statement-list }
 * declarations -> data_type identifier-list; declarations | ?
 * data_type -> int | char
 * identifier-list -> id | id,identifier-list | id[number],identifier-list | id[number]
 * statement-list -> statement statement-list | ?
 * statement -> assign-stat; | decision-stat | looping-stat
 * assign_stat -> id = expr
 * expr -> simple-expr e'
 * e' -> relop simple-expr | ?
 * simple-expr -> term se'
 * se' -> addop term se' | ?
 * term -> factor t'
 * t' -> mulop factor t'
 * factor -> id | num
 * 
 * decision-stat -> if (expr) {statement-list} d'
 * d' -> else {statement_list} | ?
 * looping-stat -> while(expr) {statement-list} | for(assign-stat; expr; assign-stat)
 * {statement-list}
 * 
 * relop -> == | != | <= | >= | > | <
 * addop -> + | -
 * mulop -> * | / | %
 * --------------------------------------------------------------
 */

///////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------------//
// GRAMMAR //

enum ParserTypes
{
    P_NONE,
    
    P_ID,
    P_NUM,

    P_IF,
    P_ELSE,
    P_WHILE,
    P_FOR,

    P_INT,
    P_CHAR,

    P_RELOP,
    P_ADDOP,
    P_MULOP,
};
typedef enum ParserTypes ParserTypes;

// Utility functions
void error(char* prompt, InputStream* stream);
int match_lex(char* target, char* lexeme, InputStream* stream);
int match(Token* tkn, ParserTypes type, InputStream* stream);

// Actual Grammar functions
int Program(InputStream* stream);

int statement_list(InputStream* stream);
int statement(InputStream* stream);
int assign_stat(InputStream* stream);
int expr(InputStream* stream);
int eprime(InputStream* stream);
int simple_expr(InputStream* stream);
int seprime(InputStream* stream);
int term(InputStream* stream);
int tprime(InputStream* stream);
int factor(InputStream* stream);

int decision_stat(InputStream* stream);
int dprime(InputStream* stream);
int looping_stat(InputStream* stream);

int relop(InputStream* stream);
int addop(InputStream* stream);
int mulop(InputStream* stream);

int declarations(InputStream* stream);
int data_type(InputStream* stream);
int identifier_list(InputStream* stream);

#endif //parser_h