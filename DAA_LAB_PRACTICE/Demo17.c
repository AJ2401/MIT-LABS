// Matrix Multiplication
#include <stdio.h>
#include <stdlib.h>
int max;
void display(int arr[][max])
{
     for (int i = 0; i < max; i++)
     {
          for (int j = 0; j < max; j++)
          {
               printf("  %d  ", arr[i][j]);
          }
          printf("\n");
     }
}
void Multi(int arr1[][max],int arr2[][max])
{
     int result[max][max];
     for (int i = 0; i < max; i++)
     {
          for (int j = 0; j < max; j++)
          {
               for (int k = 0; k < max; k++)
               {
                    result[j][k] = arr1[i][k] * arr2[k][j];
               }
          }
     }
     display(result);
}
void main()
{
     printf("Enter the Size of the Array : \n");
     scanf("%d", &max);
     int arr1[max][max];
     printf("Enter the Matrix Elements : \n");
     for (int i = 0; i < max; i++)
     {
          for (int j = 0; j < max; j++)
          {
               printf("Enter Element Arr[%d][%d] :\n", i, j);
               scanf("%d", &arr1[i][j]);
          }
     }
     printf("The Matrix One is : \n");
     display(arr1);
     int arr2[max][max];
     printf("Enter the Matrix Elements : \n");
     for (int i = 0; i < max; i++)
     {
          for (int j = 0; j < max; j++)
          {
               printf("Enter Element Arr[%d][%d] :\n", i, j);
               scanf("%d", &arr2[i][j]);
          }
     }
     printf("The Matrix One is : \n");
     display(arr2);
     printf("The Resultant Matrix is : \n");
     Multi(arr1,arr2);
}