#ifndef common_h
#define common_h

#define MAX_LEX 1024

enum TokenType
{   
    L_NONE,
    L_ANY,

    KEYWORD,
    IDENTIFIER,
    FUNC,

    DATA_INT,
    DATA_FLOAT,
    DATA_STR,

    STR_LITERAL,
    SPECIAL_SYM,
    
    OP_ASSIGN,

    OP_PLUS_EQU,
    OP_MINUS_EQU,
    OP_MUL_EQU,
    OP_DIV_EQU,
    OP_MOD_EQU,

    OP_ARITH_PLUS,
    OP_ARITH_MINUS,
    OP_ARITH_MUL,
    OP_ARITH_DIV,
    OP_ARITH_MOD,
    OP_ARITH_POW,

    OP_REL_EQU,
    OP_REL_NOT_EQU,
    OP_REL_GREATER,
    OP_REL_GREATER_EQU,
    OP_REL_LESSER,
    OP_REL_LESSER_EQU
};
typedef enum TokenType TokenType;

struct Token
{
    TokenType type;
    char lexeme[MAX_LEX];
    unsigned int pos;
};
typedef struct Token Token;

#endif // common_h