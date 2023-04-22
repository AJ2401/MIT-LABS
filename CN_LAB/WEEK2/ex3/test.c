#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getnextspace(char* text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
            return i;
    }
    return -1;
}

void strtoints(char* buffer, int* nums, int size)
{
    char* iterate = buffer;
    for(int i = 0; i < size; i++)
    {
        nums[i] = atoi(iterate);
        iterate += getnextspace(iterate) + 1;
    }
}

void intstostr(char* buffer, int* nums, int size)
{
    char* iterate = buffer;
    for(int i = 0; i < size; i++)
    {
        sprintf(iterate, "%d ", nums[i]);
        iterate += getnextspace(iterate)+1;
    }
    *(iterate - 1) = '\0';
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    char buffer[1024];
    intstostr(buffer, array, 5);
    printf("%s\n", buffer);
    printf("%lu\n", strlen(buffer));
    return 0;
}