//String matching
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int Match(char arr[],char pat[],int t,int p)
{
      int c=0;
     for(int i=0;i<t-p;i++)
     {
          int a=1;
          for(int j=0;j<p;j++)
          {
          if(arr[i+j]!=pat[j])
          {
               break;
          }
          if(a==p)
          {
               printf("%s is Matched in %s at Index %d\n",pat,arr,i);
               c++;
          }
          a++;
          }
     }
     return(c);
}
void main()
{
     char arr[max];
     char pat[max];
     printf("Enter the String :\n");
     scanf("%s",&arr);
     printf("Enter the Pattern :\n");
     scanf("%s",&pat);
     int t=strlen(arr);
     int p=strlen(pat);
     int res=Match(arr,pat,t,p);
     if(res>0)
     {
          printf("%s is Present in %s at %d times \n",pat,arr,res);
     }
     else
     {
          printf("%s is Not Present is  %s ",pat,arr);
     }
}