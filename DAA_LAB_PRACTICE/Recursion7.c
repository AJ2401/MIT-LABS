// Inc And Dec order of n
#include<stdio.h>
#include<stdlib.h>
int max;
void inc(int n)
{
     if(n>max)
     {
          return;
     }
     if(n<=max)
     {
          printf(" %d ",n);
          inc(n+1);
     }
}
void dec(int n)
{
     if(n<0)
     {
          return;
     }
     if(n>=0)
     {
          printf(" %d ",n);
          dec(n-1);
     }

}
void main()
{
     printf("Enter the Number : \n");
     scanf("%d",&max);
printf("Increasing Order: \n");
inc(0);
     printf("\n\n");
     printf("Decreasing Order : \n");
     dec(max);
}