#include<stdio.h>
#include<stdlib.h>
#include"display.c"
int size;
void Bubble_Sort(int arr[size])
{
     for(int i=0;i<size-1;i++)
     {
          for(int j=0;j<size-i-1;j++)
          {
               if(arr[j]>arr[j+1])
               {
                    swap(arr,j,j+1);
               }
          }
     }
}
void main()
{
     printf("Enter the Length of the Array : \n");
     scanf("%d",&size);
     int arr[size];
     printf("Enter the Array Elements : \n");
     for(int i=0;i<size;i++)
     {
          printf("Element %d : ",i+1);
          scanf("%d",&arr[i]);
     }
     Bubble_Sort(arr);
     printf("The Sorted Array is : \n");
     display(arr,size);

}