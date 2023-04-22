//N raise to 1/2 basic operations 
#include<stdlib.h>
#include<stdio.h>
int power(int num)
{
     int s=0;
     int end=num;
     int res;
     while(s<=end)
     {
          int mid=(s+end)/2;
          if(mid*mid==num)
          {
               res=mid*mid;
               return(res);
               break;
          }
          if(mid*mid<num)
          {
               res=s;
               s=mid+1;
          }
          else
          {
               end=mid-1;
          }
     }
}
void main()
{
     int n;
     printf("Enter the Number : \n");
     scanf("%d",&n);
     int res=power(n);
     printf("The Resultant is %d ",res);
}