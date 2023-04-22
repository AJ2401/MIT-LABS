// Insertion Sort
#include <stdlib.h>
#include <stdio.h>
int max;
void Sort(int arr[])
{
     for (int i = 1; i < max; i++)
     {
          int min = arr[i];
          int j = i - 1;
          while (arr[j] > min && j >= 0)
          {
               arr[j + 1] = arr[j];
               j--;
          }
          arr[j + 1] = min;
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
     printf("Enter the Size of the Array : \n");
     scanf("%d",&max);
     int arr[max];
     printf("Enter the Array Elements : \n");
     for(int i=0;i<max;i++)
     {
          printf("Element %d : ",i+1);
          scanf("%d",&arr[i]);
     }
     printf("The Array is : \n");
     display(arr);
     printf("The Sorted Array is : \n");
     Sort(arr);
     display(arr);

}