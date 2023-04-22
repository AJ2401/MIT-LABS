#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int size)
{
     printf("\nThe Array is : \n");
     for(int i=0;i<size;i++)
     {
          printf("  %d  ",arr[i]);
     }
}
void swap(int arr[],int p1,int p2)
{
     int temp=arr[p2];
     arr[p2]=arr[p1];
     arr[p1]=temp;
}