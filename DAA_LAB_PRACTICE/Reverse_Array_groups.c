// Grouping Array and Reversing
#include <stdio.h>
#include <stdlib.h>
int max;
void swap(int arr[],int p1,int p2)
{
     int temp=arr[p1];
     arr[p1]=arr[p2];
     arr[p2]=temp;
}
void reverse(int arr[], int pack, int l,int u)
{
     if (u<max)
     {
          for (int i = l; i <=u/2; i++)
          {
               swap(arr, l + i, u - i);
          }
          l=u;
          u=u+pack;
          reverse(arr, pack, l, u);
     }
}
void display(int arr[])
{
     for (int i = 0; i < max; i++)
     {
          printf("  %d  ", arr[i]);
     }
}
void main()
{
     printf("Enter the Array size : \n");
     scanf("%d",&max);
     int arr[max];
     printf("Enter the Array Elements : \n");
     for(int i=0;i<max;i++)
     {
          printf("Element %d ",i+1);
          scanf("%d",&arr[i]);
     }
     printf("The Array is : \n\n");
     display(arr);
     int pack;
     printf("Enter the Value of the Pack : \n");
     scanf("%d",&pack);
     reverse(arr,pack,0,pack);
     printf("The Reversed Array is : \n");
     display(arr);
}