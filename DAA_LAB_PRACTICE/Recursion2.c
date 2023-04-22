#include<stdio.h>
#include<stdlib.h>

int sum(int n,int s)
{
     if(n>0)
     {
          s=s+n;
          sum(n-1,s);
     }
     else
     {
          return(s);
     }
}
void main()
{
     int res,n;
     printf("Enter the Number : \n");
     scanf("%d",&n);
     res=sum(n,0);
     printf("\nThe Sum is = %d \n",res);
}