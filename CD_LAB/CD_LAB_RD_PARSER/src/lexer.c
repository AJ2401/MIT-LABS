#include "lexer.h"

#define N_KEYS 36

char* py_keywords[] = {
    "__INVALID__\0",
    "False",
    "None", 
    "True", 
    "and", 
    "as", 
    "assert", 
    "async", 
    "await",
    "break",
    "class", 
    "continue", 
    "def", 
    "del",
    "elif",
    "else", 
    "except", 
    "finally", 
    "for", 
    "from", 
    "global", 
    "if", 
    "import", 
    "in", 
    "is", 
    "lambda", 
    "nonlocal", 
    "not", 
    "or", 
    "pass", 
    "raise", 
    "return", 
    "try", 
    "while", 
    "with", 
    "yield"
};

char* py_type[] = {   
    "NONE",
    "ANY",

    "KEYWORD",
    "IDENTIFIER",
    "FUNC",

    "INT",
    "FLOAT",
    "STRING",

    "STR_LITERAL",
    "SPECIAL_SYM",
    
    "OP_ASSIGN",

    "OP_PLUS_EQU",
    "OP_MINUS_EQU",
    "OP_MUL_EQU",
    "OP_DIV_EQU",
    "OP_MOD_EQU",

    "OP_ARITH_PLUS",
    "OP_ARITH_MINUS",
    "OP_ARITH_MUL",
    "OP_ARITH_DIV",
    "OP_ARITH_MOD",
    "OP_ARITH_POW",

    "OP_REL_EQU",
    "OP_REL_NOT_EQU",
    "OP_REL_GREATER",
    "OP_REL_GREATER_EQU",
    "OP_REL_LESSER",
    "OP_REL_LESSER_EQU"
};

char* c_keywords[] = {
    "auto",
	"break",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",	
    "float",
	"for",
	"goto",
	"if",
	"int",
	"long",
	"register",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"void",
	"volatile",
	"while"
};

char* c_type[] = {   
    "NONE",
    "ANY",

    "KEYWORD",
    "IDENTIFIER",
    "FUNC",

    "INT",
    "FLOAT",
    "STRING",

    "STR_LITERAL",
    "SPECIAL_SYM",
    
    "OP_ASSIGN",

    "OP_PLUS_EQU",
    "OP_MINUS_EQU",
    "OP_MUL_EQU",
    "OP_DIV_EQU",
    "OP_MOD_EQU",

    "OP_ARITH_PLUS",
    "OP_ARITH_MINUS",
    "OP_ARITH_MUL",
    "OP_ARITH_DIV",
    "OP_ARITH_MOD",
    "OP_ARITH_POW",

    "OP_REL_EQU",
    "OP_REL_NOT_EQU",
    "OP_REL_GREATER",
    "OP_REL_GREATER_EQU",
    "OP_REL_LESSER",
    "OP_REL_LESSER_EQU"
};

int isKeyword(char* lexeme)
{
    for(int i = 0; i < N_KEYS; i++)
        if(strncmp(c_keywords[i], lexeme, strlen(c_keywords[i])) == 0) 
            return i;
    return 0;
}

Token getNextToken(InputStream* stream)
{
    Token token;
    token.pos = stream->pos;
    memset(token.lexeme, '\0', sizeof(char) * MAX_LEX);
    token.type = L_NONE;
    int pos = 0 ;
    char buffer[MAX_LEX];

    char c = nextchar(stream);
    while(c != '\0')
    {
        if(isAlphabet(c))
        {
            buffer[pos++] = c;
            c = nextchar(stream);
            while(c != '\0' && isAlphaNumUnder(c))
            {
                buffer[pos++] = c;
                c = nextchar(stream);
            }
            buffer[pos++] = '\0';
            streamRetract(stream);

            if(isKeyword(buffer))
            {
                token.type = KEYWORD;
                break;
            }
            if(c == ' ')
            {
                while(c == ' ')
                    c = nextchar(stream);
                streamRetract(stream);
            }
            if(c == '(')
            {
                token.type = FUNC;
                break;
            }
            token.type = IDENTIFIER;
            break;
        }
        else if(isDigit(c))
        {
            buffer[pos++] = c;
            c = nextchar(stream);
            while(c != '\0' && isDigit(c))
            {
                buffer[pos++] = c;
                c = nextchar(stream);
            }
            if(c == '.')
            {
                buffer[pos++] = c;
                c = nextchar(stream);
                while(c != '\0' && isDigit(c))
                {
                    buffer[pos++] = c;
                    c = nextchar(stream);
                }
                streamRetract(stream);
                buffer[pos++] = '\0';
                token.type = DATA_FLOAT;
                break;
            }
            streamRetract(stream);
            buffer[pos++] = '\0';
            token.type = DATA_INT;
            break;
        }
        else if(isArith(c))
        {
            switch(c)
            {
                case '+':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_PLUS_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = OP_ARITH_PLUS;
                    break;
                case '-':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_MINUS_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = OP_ARITH_MINUS;
                    break;
                case '*':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_MUL_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = OP_ARITH_MUL;
                    break;
                case '/':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_DIV_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = OP_ARITH_DIV;
                    break;
                case '%':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_MOD_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = OP_ARITH_MOD;
                    break;
                default:
                    break;
            }
            break;
        }
        else if(isSpecial(c))
        {
            buffer[pos++] = c;
            buffer[pos++] = '\0';
            token.type = SPECIAL_SYM;
            break;
        }
        else if(isRel(c))
        {
            switch(c)
            {
                case '>':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_REL_GREATER_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = OP_REL_GREATER;
                    break;
                case '<':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_REL_LESSER_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = OP_REL_LESSER;
                    break;
                case '!':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_REL_NOT_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = SPECIAL_SYM;
                    break;
                case '=':
                    buffer[pos++] = c;
                    c = nextchar(stream);
                    if(c == '=')
                    {
                        buffer[pos++] = c;
                        buffer[pos++] = '\0';
                        token.type = OP_REL_EQU;
                        break;
                    }
                    streamRetract(stream);
                    buffer[pos++] = '\0';
                    token.type = OP_ASSIGN;
                    break;
                default:
                    break;
            }
            break;
        }
        else if(c == '"')
        {
            buffer[pos++] = c;
            c = nextchar(stream);
            while(c != '"')
            {
                buffer[pos++] = c;
                c = nextchar(stream);
            }
            buffer[pos++] = c;
            buffer[pos++] = '\0';

            token.type = STR_LITERAL;
            break;
        }
        else if(isWhite(c))
        {
            int temp = 0;
            while(c != '\0' && isWhite(c))
            {
                c = nextchar(stream);
                temp++;
            }
            token.pos += temp + 2;
            continue;
        }
        else if(c == '#')
        {
            int temp = 0;
            while(c != '\n')
            {
                c = nextchar(stream);
                temp++;
            }
            c = nextchar(stream);
            token.pos += temp + 2;
            continue;
        }
        else break;
    }
    strncpy(token.lexeme, buffer, strlen(buffer)+1);
    return token;
}

void printToken(Token* tkn, int row, int col)
{ printf("< %s, %s, %d, %d >", py_type[tkn->type], tkn->lexeme, row, col); }

Token copyToken(Token* tkn)
{
    Token newToken;
    newToken.type = tkn->type;
    newToken.pos  = tkn->pos;
    strncpy(newToken.lexeme, tkn->lexeme, strlen(tkn->lexeme));
    return newToken;
}

TokenType getType(char* lexeme)
{
    if(strncmp(lexeme, "int", 3) == 0)
        return DATA_INT;
    else if(strncmp(lexeme, "float", 5) == 0)
        return DATA_FLOAT;
    else if(strncmp(lexeme, "char", 4) == 0)
        return DATA_STR;
    else return L_ANY;
}

/*

global_node* createEmptyTable()
{
    global_node* table = (global_node*)calloc(SYM_GLOBAL, sizeof(global_node));
    
    for(int i = 0; i < SYM_GLOBAL; i++)
    {
        table[i].next = NULL;
        table[i].returnType = NONE;
    }
    return table;
}

int global_hash(char* lexeme)
{
    int size = strlen(lexeme), index = 0;
    for(int i = 0; i < size; i++)
        index += lexeme[i];
    return index % SYM_GLOBAL;
}

int local_hash(char* lexeme)
{
    int size = strlen(lexeme), index = 0;
    for(int i = 0; i < size; i++)
        index += lexeme[i];
    return index % SYM_LOCAL;
}

int getTypeSize(TokenType type)
{
    switch(type)
    {
        case DATA_INT:
            return 4;
        case DATA_FLOAT:
            return 4;
        case DATA_STR:
            return 1;
        default:
            return 0;
    }
}

int global_present(global_node* table, Token* tkn)
{
    int idx = global_hash(tkn->lexeme);
    global_node* iter = &(table[idx]);
    if(iter != NULL && strncmp(iter->tkn.lexeme, tkn->lexeme, strlen(tkn->lexeme) != 0))
        iter = iter->next;
    if(iter == NULL) return 0;
    else return 1;
}

int local_present(local_node* table, Token* tkn)
{
    int idx = local_hash(tkn->lexeme);
    local_node* iter = &(table[idx]);
    if(iter != NULL && strncmp(iter->tkn.lexeme, tkn->lexeme, strlen(tkn->lexeme) != 0))
        iter = iter->next;
    if(iter == NULL) return 0;
    else return 1;
}

int insert_global(global_node* table, Token* tkn, TokenType returnType)
{
    int idx = global_hash(tkn->lexeme);
    global_node* iter = &(table[idx]);
    if(iter->returnType != NONE)
    {
        while(iter->next != NULL)
            iter = iter->next;
        iter->next = (global_node*)malloc(sizeof(global_node));
        iter = iter->next;
    }
    iter->returnType = returnType;
    iter->next = NULL;
    
    iter->tkn.type = tkn->type;
    iter->tkn.pos = tkn->pos;
    strncpy(iter->tkn.lexeme, tkn->lexeme, strlen(tkn->lexeme));
    return idx;
}

int insert_local(local_node* table, Token* tkn, TokenType datatype)
{
    int idx = local_hash(tkn->lexeme);
    local_node* iter = &(table[idx]);
    if(iter->datatype != NONE)
    {
        while(iter->next != NULL)
            iter = iter->next;
        iter->next = (local_node*)malloc(sizeof(local_node));
        iter = iter->next;
    }
    iter->datatype = datatype;
    iter->size = getTypeSize(datatype);
    iter->next = NULL;
    
    iter->tkn.type = tkn->type;
    iter->tkn.pos = tkn->pos;
    strncpy(iter->tkn.lexeme, tkn->lexeme, strlen(tkn->lexeme));
    return idx;
}

global_node* createSymbolTable(InputStream* stream)
{
    global_node* table = createEmptyTable();
    
    Token tkn = getNextToken(stream);
    Token prev = copyToken(&tkn);
    while(tkn.type != NONE)
    {
        if(tkn.type == KEYWORD && getType(tkn.lexeme) >= DATA_INT && getType(tkn.lexeme) <= DATA_STR)
        {
            prev = copyToken(&tkn);

            tkn = getNextToken(stream);
            int global_idx = global_hash(tkn.lexeme);
            if(table[global_idx].returnType == NONE)
            {
                table[global_idx].returnType = getType(prev.lexeme);
                tkn = getNextToken(stream);
                int param_idx = 0;
                while(tkn.type != NONE && (tkn.lexeme, "{", 1) != 0)
                {
                    if(tkn.type == DATA_INT || tkn.type == DATA_FLOAT || tkn.type == DATA_STR)
                    {
                        strncpy(table[global_idx].parameters[param_idx].lexeme, tkn.lexeme, strlen(tkn.lexeme));
                        table[global_idx].parameters[param_idx].type = tkn.type;
                        table[global_idx].parameters[param_idx++].pos = tkn.pos;
                    }
                    tkn = getNextToken(stream);
                }
                createLocalTable(table+global_idx, stream);
                table[global_idx].next = NULL;
            }
            else
            {
                global_node* iter = &(table[global_idx]);
                while(iter->next != NULL)
                    iter = iter->next;
                iter->next = (global_node*)malloc(sizeof(global_node));
                iter = iter->next;
                createLocalTable(iter, stream);
                iter->next = NULL;
            }
        }
        tkn = getNextToken(stream);
    }
}

void printTable(global_node* table)
{
    printf("returnType functionName\n");
    for(int i = 0; i < SYM_GLOBAL; i++)
    {
        global_node* iter = &(table[i]);
        while(iter != NULL)
        {
            printf("%s %s\n", py_type[iter->returnType], iter->tkn.lexeme);
            for(int j = 0; j < SYM_LOCAL; j++)
            {
                printf("dataType Name Size\n");
                local_node* loc_iter = &(iter->table[j]);
                while(loc_iter != NULL)
                {
                    printf("%s %s %d\n", py_type[loc_iter->datatype], loc_iter->tkn.lexeme, loc_iter->size);
                    loc_iter = loc_iter->next;
                }
            }
            iter = iter->next;
            printf("\n---------------------------------------------\n");
        }
    }
}


*/