#include "parser.h"

Token P_currentToken;

/*
 * 'return 0' means that the current pattern is not the given production.
 * 
 * It gives error only when it matches a certain part of the production
 * but doesn't match the rest, as it is a 'wrong syntax' in the latter case.
 * 
 * If the production has epsilon the production never 'returns 0'. 
 * It either 'returns 1' or gives an 'error'.
 * 
 * Break the process of making the full Recursive Descent Parser into two parts.
 *      1. Make the Grammar
 *      2. Implement it into code
 * 
 * If you try to do both at the same time you will be really confused. 
 */

void error(char* prompt, InputStream* stream)
{
    printf("Row: %d Col: %d\n", stream->row, stream->col);
    printf("%s\n", prompt);
    exit(EXIT_FAILURE);
}

int match_lex(char* target, char* lexeme, InputStream* stream)
{
    if((strncmp(target, lexeme, strlen(lexeme)) == 0))
    {
        P_currentToken = getNextToken(stream);
        return 1;
    }
    else return 0;
}

int match(Token* tkn, ParserTypes type, InputStream* stream)
{
    int result = 0;
    switch(type)
    {
        case P_ID:
            result = (tkn->type == IDENTIFIER);
            break;
        case P_NUM:
            result = (tkn->type == DATA_INT || 
                      tkn->type == DATA_FLOAT
            );
            break;
        case P_INT:
            result = (tkn->type == KEYWORD && 
                      strncmp(tkn->lexeme, "int", 3) == 0
            );
            break;
        case P_CHAR:
            result = (tkn->type == KEYWORD && 
                      strncmp(tkn->lexeme, "char", 3) == 0
            );
            break;
        case P_RELOP:
            result = (tkn->type == OP_REL_EQU || 
                      tkn->type == OP_REL_NOT_EQU ||
                      tkn->type == OP_REL_GREATER ||
                      tkn->type == OP_REL_GREATER_EQU ||
                      tkn->type == OP_REL_LESSER ||
                      tkn->type == OP_REL_LESSER_EQU
            );
            break;
        case P_ADDOP:
            result = (tkn->type == OP_ARITH_PLUS || 
                      tkn->type == OP_ARITH_MINUS
            );
            break;
        case P_MULOP:
            result = (tkn->type == OP_ARITH_MUL || 
                      tkn->type == OP_ARITH_DIV ||
                      tkn->type == OP_ARITH_MOD 
            );
            break;
        case P_IF:
            result = (tkn->type == KEYWORD &&
                      strncmp(tkn->lexeme, "if", 2) == 0
            );
            break;
        case P_ELSE:
            result = (tkn->type == KEYWORD &&
                      strncmp(tkn->lexeme, "else", 4) == 0
            );
            break;
        case P_WHILE:
            result = (tkn->type == KEYWORD &&
                      strncmp(tkn->lexeme, "while", 5) == 0
            );
            break;
        case P_FOR:
            result = (tkn->type == KEYWORD &&
                      strncmp(tkn->lexeme, "for", 3) == 0
            );
            break;
        default:
            return 0;
    }
    if(result) P_currentToken = getNextToken(stream);
    return result;
}

int Program(InputStream* stream)
{
    P_currentToken = getNextToken(stream);
    return (match_lex(P_currentToken.lexeme, "main", stream) && 
            match_lex(P_currentToken.lexeme, "(", stream) && 
            match_lex(P_currentToken.lexeme, ")", stream) && 
            match_lex(P_currentToken.lexeme, "{", stream) && 
            declarations(stream) && 
            statement_list(stream) && 
            match_lex(P_currentToken.lexeme, "}", stream));
}
int declarations(InputStream* stream)
{
    if(data_type(stream))
    {
        if(identifier_list(stream) && 
           match_lex(P_currentToken.lexeme, ";", stream) && 
           declarations(stream)) return 1;
        else error("ERROR: Expected identifier after data type", stream);
    }
    else return 1;
}
int data_type(InputStream* stream)
{
    return (
        match(&P_currentToken, P_INT, stream) ||
        match(&P_currentToken, P_CHAR, stream)
    );
}
int identifier_list(InputStream* stream)
{
    if(match(&P_currentToken, P_ID, stream))
    {
        if(match_lex(P_currentToken.lexeme, ",", stream))
        {
            if(identifier_list(stream)) return 1;
            else error("ERROR: Expecting an identifier after the comma", stream);
        }
        else if(match_lex(P_currentToken.lexeme, "[", stream))
        {
            if(match(&P_currentToken, P_NUM, stream) && 
               match_lex(P_currentToken.lexeme, "]", stream))
            {
                if(match_lex(P_currentToken.lexeme, ",", stream))
                {
                    if(identifier_list(stream)) return 1;
                    else error("ERROR: Expecting an identifier after the comma", stream);
                }
                else return 1;
            }
            else error("ERROR: Invalid array declaration", stream);
        }
        else return 1;
    }
    else return 0;
}
int assign_stat(InputStream* stream)
{
    if(match(&P_currentToken, P_ID, stream))
    {
        if(match_lex(P_currentToken.lexeme, "=", stream) &&
           expr(stream)) return 1;
        else error("ERROR: Expected '=' and an expression", stream);
    }
    else return 0;
}
int statement_list(InputStream* stream)
{
    statement(stream) && statement_list(stream);
    return 1;
}

int statement(InputStream* stream)
{
    if(assign_stat(stream))
    {
        if(match_lex(P_currentToken.lexeme, ";", stream)) return 1;
        else error("ERROR: Expected ';'", stream);
    }
    else return (decision_stat(stream) || looping_stat(stream));
}

int decision_stat(InputStream* stream)
{
    if(match(&P_currentToken, P_IF, stream))
    {
        if(
            match_lex(P_currentToken.lexeme, "(", stream) &&
            expr(stream) &&
            match_lex(P_currentToken.lexeme, ")", stream) &&

            match_lex(P_currentToken.lexeme, "{", stream) &&
            statement_list(stream) &&
            match_lex(P_currentToken.lexeme, "}", stream) &&
            dprime(stream)
        ) return 1;
        else error("ERROR: Invalid 'if' statement", stream);
    }
    else return 0;
}

int dprime(InputStream* stream)
{
    if(match(&P_currentToken, P_ELSE, stream))
    {
        if(
            match_lex(P_currentToken.lexeme, "{", stream) &&
            statement_list(stream) &&
            match_lex(P_currentToken.lexeme, "}", stream)
        ) return 1;
        else error("ERROR: Invalid 'if-else' statement", stream);
    }
    else return 1;
}

int looping_stat(InputStream* stream)
{
    if(match(&P_currentToken, P_WHILE, stream))
    {
        if(
            match_lex(P_currentToken.lexeme, "(", stream) &&
            expr(stream) &&
            match_lex(P_currentToken.lexeme, ")", stream) &&
            
            match_lex(P_currentToken.lexeme, "{", stream) &&
            statement_list(stream) &&
            match_lex(P_currentToken.lexeme, "}", stream)
        ) return 1;
        else error("ERROR: Invalid 'while' statement", stream);
    }
    else if(match(&P_currentToken, P_FOR, stream))
    {
        if(
            match_lex(P_currentToken.lexeme, "(", stream) &&
            
            assign_stat(stream) &&
            match_lex(P_currentToken.lexeme, ";", stream) &&

            expr(stream) &&
            match_lex(P_currentToken.lexeme, ";", stream) &&
            
            assign_stat(stream) &&
            
            match_lex(P_currentToken.lexeme, ")", stream) &&

            match_lex(P_currentToken.lexeme, "{", stream) &&
            statement_list(stream) &&
            match_lex(P_currentToken.lexeme, "}", stream)
        ) return 1;
        else error("ERROR: Invalid 'for' statement", stream);
    }
    else return 0;
}


int expr(InputStream* stream)
{
    if(simple_expr(stream)) 
    {
        if(eprime(stream)) return 1;
        else error("ERROR: Expected relop", stream);
    }
    else return 0;
}
int eprime(InputStream* stream)
{
    if(relop(stream))
    {
        if(simple_expr(stream)) return 1;
        else error("ERROR: Expected Simple Expression after Relational Operator", stream);
    }
    else return 1;
}
int simple_expr(InputStream* stream)
{
    if(term(stream))
    {
        if(seprime(stream)) return 1;
        else error("ERROR: Expected addop", stream);
    }
    else return 0;
}
int seprime(InputStream* stream)
{
    if(addop(stream))
    {
        if(term(stream) && seprime(stream)) return 1;
        else error("ERROR: Expected 'Term' after addop", stream);
    }
    else return 1;
}
int term(InputStream* stream)
{
    if(factor(stream))
    {
        if(tprime(stream)) return 1;
        else error("ERROR: Expected 'Mulop' after Factor", stream);
    }
    else return 0;
}
int tprime(InputStream* stream)
{
    if(mulop(stream))
    {
        if(factor(stream) && tprime(stream)) return 1;
        else error("ERROR: Expected a 'Factor' after 'Mulop'", stream);
    }
    else return 1;
}
int factor(InputStream* stream)
{
    return match(&P_currentToken, P_ID, stream) || 
       match(&P_currentToken, P_NUM, stream);
}
int relop(InputStream* stream)
{
    return match(&P_currentToken, P_RELOP, stream);
}
int addop(InputStream* stream)
{
    return match(&P_currentToken, P_ADDOP, stream);
}
int mulop(InputStream* stream)
{
    return match(&P_currentToken, P_MULOP, stream);
}