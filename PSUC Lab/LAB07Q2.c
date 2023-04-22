#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
   printf("\nADITYA_PANDEY(200953098)\n");
    char A[50];
    printf("\nEnter any Sentence:\n");
    gets(A);
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]>='a'&&A[i]<='z')
        {
            A[i]=A[i]-32;
        }
        else if(A[i]>='A'&&A[i]<='Z')
        {
            A[i]=A[i]+32;
        }
    }
    printf("\nResultant Sentence %s\t",A);

}
