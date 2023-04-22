// binary Search
#include <stdio.h>
#include <stdlib.h>
int max;
void Merge(int arr[], int l, int m, int u)
{
     int l1 = m - l+1;
     int l2 = u - m ;

     int a1[l1];
     int a2[l2];

     for (int i = 0; i < l1; i++)
     {
          a1[i] = arr[i + l];
     }
     for (int i = 0; i < l2; i++)
     {
          a2[i] = arr[i + m + 1];
     }
     int j = 0, k = 0, p = l;

     while (j < l1 && k < l2)
     {
          if (a1[j] < a2[k])
          {
               arr[p] = a1[j];
               j++;
               p++;
          }
          else
          {
               arr[p] = a2[k];
               k++;
               p++;
          }
     }
     while (j < l1)
     {
          arr[p] = a1[j];
          j++;
          p++;
     }
     while (k < l2)
     {
          arr[p] = a2[k];
          k++;
          p++;
     }
}
void Sort(int arr[], int l, int u)
{
     if (l < u)
     {
          int m = (l + u) / 2;
          Sort(arr, l, m);
          Sort(arr, m + 1, u);

          Merge(arr, l, m, u);
     }
}
int Binary_Search(int arr[], int L, int U, int key)
{
     if (L < U)
     {
          int mid = (L + U) / 2;
          if (arr[mid] == key)
          {
               return (1);
          }
          if (key > arr[mid])
          {
               Binary_Search(arr, mid + 1, U,key);
          }
          else
          {
               Binary_Search(arr, L, mid - 1,key);
          }
     }
}
void display(int arr[])
{
     for(int i=0;i<max;i++)
     {
          printf("  %d  ",arr[i]);
     }
     printf("\n");
}
void main()
{
     int arr[max], res, key;
     printf("Enter the Size of theh Array :\n");
     scanf("%d", &max);
     printf("Enter the Element \n");
     for (int i = 0; i < max; i++)
     {
          printf("Element %d : \n",i+1);
          scanf("%d",&arr[i]);
     }
     printf("the Array is :\n");
     display(arr);
     Sort(arr,0,max-1);
     printf("The Sorted Array is :\n");
     display(arr);
     printf("Enter the Key : \n");
     scanf("%d",&key);
     res=Binary_Search(arr,0,max-1,key);
     if(res==1)
     {
          printf("The  key is Preset \n");
     }
}