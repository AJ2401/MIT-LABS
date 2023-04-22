#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef filehandler_h
#define filehandler_h

#define MAX_BUF 1024

struct InputStream 
{
    char buffer[MAX_BUF];
    FILE* src;
    int pos, row, col;
};
typedef struct InputStream InputStream;

void input(char* prompt, char* buffer, int size);

InputStream* createInputStream(FILE* src);
void streamRetract(InputStream* stream);
char nextchar(InputStream* stream);

#endif //filehandler_h