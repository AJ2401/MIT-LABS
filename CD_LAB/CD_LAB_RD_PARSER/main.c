#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "filehandler.h"
#include "parser.h"

#define MAX_BUF 1024

void lower(char* string)
{
    int len = strlen(string);
    for(int i = 0; i < len; i++)
        if(string[i] >= 'A' && string[i] <= 'Z')
            string[i] += 'a'-'A';
}

int main()
{
    char buffer[MAX_BUF], inbuf[MAX_BUF];
    while(1)
    {
        printf("Enter the path to file: ");
        scanf("%s",buffer);
        strcpy(buffer, inbuf);
        lower(inbuf);
        if(strcmp(inbuf, "exit") == 0) break;
        FILE* src = fopen(buffer, "r");
        InputStream* srcstream = createInputStream(src);
        if(Program(srcstream) && (getNextToken(srcstream).type == L_NONE)) return 1;
        else printf("It does not satisfy the grammar.\n");
    }
    return 0;
}

/*
int main()
{
    char buffer[] = "samples/test6.c";
    FILE* src = fopen(buffer, "r");
    InputStream* srcstream = createInputStream(src);
    if( Program(srcstream) && 
        getNextToken(srcstream).type == L_NONE) printf("It satisfies the grammar.\n");
    else printf("It does not satisfy the grammar.\n");
    return 0;
}
*/