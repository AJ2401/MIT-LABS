//Taking the Scheme of Array  as (root,left,right,...same (left,right)combinations)
#include<stdio.h>
#include<stdlib.h>
int max;
int check(int arr[])
{
     int temp=arr[0];
     for(int i=1;i<max;i+=2)
     {
          if(arr[i]>temp)
          {
               return(1);
          }
     }
     for(int i=2;i<max;i+=2)
     {
          if(arr[i]<temp)
          {
               return(1);
          }
     }
     return(0);
}
void display(int arr[])
{
     for(int i=0;i<max;i++)
     {
          printf("  %d  ",arr[i]);
     }
}
void main()
{
     printf("Enter the Array Size : \n");
     scanf("%d",&max);
     int arr[max];
     for(int i=0;i<max;i++)
     {
          printf("Enter the Node %d  data : \n",i+1);
          scanf("%d",&arr[i]);
     }
     printf("The Preorder is : \n\n");
     display(arr);
     int c=check(arr);
     if(c==1)
     {
          printf("\nIs a Not A Binary Search Tree \n");
     }
     else if(c==0)
     {
          printf("\nIs a Binary Search Tree \n");
     }
}