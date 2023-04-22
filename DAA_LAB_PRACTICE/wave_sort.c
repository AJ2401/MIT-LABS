#include<stdio.h>
#include<stdlib.h>
int max;
void swap(int arr[],int p1,int p2)
{
     int temp=arr[p1];
     arr[p1]=arr[p2];
     arr[p2]=temp;
}
void wave(int arr[])
{
          for(int j=1;j<=max-1;j++)
          {
               if(arr[j]<arr[j+1])
               {
                    swap(arr,j,j+1);
               }
               if(arr[j]<arr[j-1])
               {
                    swap(arr,j-1,j);
               }
          }
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
     printf("\nEnter the Size of the Array : \n");
     scanf("%d", &max);
     int arr[max];
     printf("\nEnter the Elements : \n");
     for (int i = 0; i < max; i++)
     {
          printf("\nEnter the %d Element : ", i + 1);
          scanf("%d",&arr[i]);
     }
     printf("\nThe Array is : \n\n");
     display(arr);  
     wave(arr);
     printf("\nThe Sorted  Array is : \n\n");
     display(arr); 
}