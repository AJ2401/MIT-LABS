#include <stdio.h>
#include <stdlib.h>
#include "display.h"
int max;
int sortedasc(int arr[], int n)
{
     if (n < max)
     {
          if (arr[n] < arr[n + 1])
          {
               sortedasc(arr, n + 1);
          }
          else
          {
               return (0);
          }
     }
     return (1);
}
int sorteddes(int arr[], int n)
{
     if (n>0)
     {
          if (arr[n] < arr[n - 1])
          {
               sorteddes(arr, n - 1);
          }
          else
          {
               return (0);
          }
     }
     return (1);
}
void main()
{
     printf("Enter the Size of the Array : \n");
     scanf("%d", &max);
     int arr[max], res,res1;
     printf("Enter Array Elements : \n");
     for (int i = 0; i < max; i++)
     {
          printf("Element %d : \n", i + 1);
          scanf("%d", &arr[i]);
     }
     display(arr, max);
     max=max-1;
     if (arr[max] > arr[max - 1])
     {
          res = sortedasc(arr, 0);
          if (res == 0)
          {
               printf("The Array is Not Sorted !!");
          }
          else if (res == 1)
          {
               printf("The Array  is Sorted !! ");
          }
     }
     else if(arr[max] < arr[max - 1])
     {
          res1 = sorteddes(arr, max);
          if (res1 == 0)
          {
               printf("The Array is Not Sorted !!");
          }
          else if (res1 == 1)
          {
               printf("The Array  is Sorted !! ");
          }
     }
}