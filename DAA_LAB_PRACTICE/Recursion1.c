//Basics of Recursion
#include<stdio.h>
#include<stdlib.h>
int max;
int sum(s,n)
{
     if(n<=max)
     {
          s=s+n;
          sum(s,n+1);
     }
     else{
          return(s);
     }
}
void main()
{
     printf("Enter the Number : \n");
     scanf("%d",&max);

     int res=sum(0,0);

     printf("The Summation is : %d \n",res);

}