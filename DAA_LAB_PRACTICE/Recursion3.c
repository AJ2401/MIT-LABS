#include<stdio.h>
#include<stdlib.h>

int power(int n,int p,int res)
{
     if(p==1)
     {
          return(res);
     }
     if(p>1)
     {
          power(n,p-1,res*n);
     }
}
void main()
{
     int p,n,res;
     printf("Enter the Number : \n");
     scanf("%d",&n);
     printf("\nEnter the power : \n");
     scanf("%d",&p);
     res=power(n,p,n);
     printf("The resultant of %d  raise to %d is  = %d ",n,p,res);    
}