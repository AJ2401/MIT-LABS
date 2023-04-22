#include<stdio.h>
#include<string.h>
int main()
{
   printf("\nADITYA_PANDEY(200953098)\n");
   char A[50];
   int count=0;
   printf("\nEnter any Sentence :\n");
   gets(A);
   printf("\nThe Entered Sentence is :\n");
   puts(A);
   for(int i=0;A[i]!='\0';++i)
   {
      if(A[i]==' ')
      {
          count++;
      }
   }
   printf("\nThe Number of Words in the Sentence is :%d\t",count+1);
}
