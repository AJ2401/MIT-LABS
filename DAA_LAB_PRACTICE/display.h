#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int max)
{
     printf("\nThe Array is :\n");
     for(int i=0;i<max;i++)
     {
          printf("  %d ",arr[i]);
     }
     printf("\n");
}