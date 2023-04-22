// Bubble Sort of Strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
int n;
void swap(char arr[][max], int p1, int p2)
{
     char temp[max];
     strcpy(temp, arr[p1]);
     strcpy(arr[p1], arr[p2]);
     strcpy(arr[p2], temp);
}
void bubble(char arr[][max])
{
     for (int i = 0; i < n - 1; i++)
     {
          for (int j = 0; j < n - i - 1; j++)
          {
               if (strcmp(arr[j], arr[j + 1]) > 0)
               {
                    swap(arr, j, j + 1);
               }
          }
     }
}
void display(char arr[][max])
{
     for (int i = 0; i < n; i++)
     {
          printf("  %s  ",arr[i]);
     }
     printf("\n");
}
void main()
{
     printf("Enter the Number of Strings : \n");
     scanf("%d", &n);
     char arr[n][max];
     printf("Enter the Strings : \n");
     for (int i = 0; i < n; i++)
     {
          printf("String %d :\n",i+1);
          scanf("%s",arr[i]);
     }
     printf("The Strings are :\n\n");
     display(arr);
     bubble(arr);
     printf("The Sorted Strings are:\n");
     display(arr);
}