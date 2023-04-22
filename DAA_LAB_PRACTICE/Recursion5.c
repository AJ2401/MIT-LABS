//Fibonnacci Number 
#include<stdio.h>
#include<stdlib.h>

int fibo(int n)
{
     if(n==0 || n==1)
     {
          return(n);
     }
     return(fibo(n-1)+fibo(n-2));
}
void main()
{
     int n,res;
     printf("Enter the Fibonnacci Series Till N : =\n");
     scanf("%d",&n);
     res=fibo(n);
     printf(" The Resultant Fibbonacci Number is =  %d  ",res);
}