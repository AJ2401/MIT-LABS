#include<stdlib.h>
#include<stdio.h>

int fact(int n,int res)
{
     if(n>1)
     {
          fact(n-1,res*n);
     }
     if(n==1)
     {
          return(res);
     }
}
void main()
{
     int res,n;
     printf("Enter the Number : \n");
     scanf("%d",&n);
     res=fact(n,1);
     printf("\nThe Resultant Factorial is : %d \n",res);
}