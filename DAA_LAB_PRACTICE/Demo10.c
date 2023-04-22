//Selection Sort
#include<stdio.h>
#include<stdlib.h>
int max;
void swap(int arr[],int p1,int p2)
{
     int temp=arr[p1];
     arr[p1]=arr[p2];
     arr[p2]=temp;
}
void Selection_Sort(int arr[])
{
     for(int i=0;i<max;i++)
     {
          int min=i;
          for(int j=i+1;j<max;j++){
          if(arr[j]<arr[min])
          {
               min=j;
          }
          }
          swap(arr,min,i);
     }
}
void display(int arr[])
{
     printf("ARRAY is : \n");
     for(int i=0;i<max;i++)
     {
          printf("  %d  ",arr[i]);
     }
}
void main()
{
     int arr[max];
     printf("Enter the  Array Elements : \n");
     scanf("%d",&max);
     printf("Enter the Elements : \n");
     for(int i=0;i<max;i++)
     {
          printf("Element %d ",i+1);
          scanf("%d",&arr[i]);
     }
     printf("\nThe Array is : \n");
     display(arr);
     printf("\nThe Sorted Array is : \n");
     Selection_Sort(arr);
     display(arr);
}