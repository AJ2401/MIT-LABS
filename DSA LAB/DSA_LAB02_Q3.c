#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#define max 50
void check_pali(char[],int);
int main()
{
    printf("\n ABHISHEK JHAWAR(200905144)\n");
    char word[max];
    printf("\n Enter a String :\n");
    scanf("%s",word);
    check_pali(word,0);
    return 0;
}
void check_pali(char word[],int index)
{
    int len = strlen(word)-(index+1);
    if(word[index] == word[len])
    {
        if(index+1 == len || index == len)
        {
            printf("\nThe Word is Palidrome %s\n",word);
            return;
        }
        check_pali(word,index+1);
    }
        else
        {
            printf("\n The Word is not Palidrome %s\n",word);
        }
}
