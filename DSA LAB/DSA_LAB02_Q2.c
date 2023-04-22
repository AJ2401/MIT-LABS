#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
void copy(char str1[],char str2[],int index)
{
    str2[index]= str1[index];
    if(str1[index] =='\0')
    {
        return;
    }
    copy(str1,str2,index+1);
}
int main()
{
    printf("\n ABHISHEK JHAWAR(200905144)\n");
    char str1[max],str2[max];
    printf("\n Enter a String to be Copied \n");
    gets(str1);
    copy(str1,str2,0);
    printf("\n Copied Successfully \n\n");
    printf("\n String 2 is %s ",str2);
    printf("\n\n");
    return 0;
}
