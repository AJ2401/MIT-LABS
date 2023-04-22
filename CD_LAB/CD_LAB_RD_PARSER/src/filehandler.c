#include "filehandler.h"

void input(char* prompt, char* buffer, int size)
{
    if(buffer == NULL) return;
    memset(buffer, '\0', sizeof(char) * size);
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strlen(buffer) - 1] = '\0';
}

InputStream* createInputStream(FILE* src)
{
    InputStream* stream = (InputStream*)malloc(sizeof(InputStream));
    memset(stream->buffer, '\0', sizeof(char) * MAX_BUF);
    stream->pos = -1;
    stream->row = 1;
    stream->col = 1;
    stream->src = src;

    fread(stream->buffer, sizeof(char), MAX_BUF, stream->src);
    return stream;
}

void streamRetract(InputStream* stream)
{
    stream->pos--;
    if(stream->pos < 0)
    {
        memset(stream->buffer, '\0', sizeof(char) * MAX_BUF);
        int goback = - (MAX_BUF + 1 + (MAX_BUF/4));
        fseek(stream->src, goback, SEEK_CUR);
        fread(stream->buffer, sizeof(char), MAX_BUF, stream->src);
        stream->pos = MAX_BUF / 4;
    }
    if(stream->buffer[stream->pos] == '\n')
    {
        stream->row--;
        int temp = 0;
        while(stream->pos - temp >= 0 && stream->buffer[stream->pos - temp] != '\n') temp++;
        stream->col = temp;
    }
}

char nextchar(InputStream* stream)
{
    if(stream->buffer[stream->pos] == '\n')
    {
        stream->row++;
        stream->col = 1;
    }
    stream->pos++;
    
    if(stream->pos >= MAX_BUF)
    {
        memset(stream->buffer, '\0', sizeof(char) * MAX_BUF);
        fread(stream->buffer, sizeof(char), MAX_BUF, stream->src);
        stream->pos = 0;
    }
    return stream->buffer[stream->pos];
}