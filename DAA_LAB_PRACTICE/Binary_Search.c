#include <stdio.h>
#include <stdlib.h>
int max;
void swap(int arr[], int p1, int p2)
{
     int temp = arr[p1];
     arr[p1] = arr[p2];
     arr[p2] = temp;
}
int binary_search(int arr[], int s, int e, int key)
{
     int mid = (s + e) / 2;
     if (arr[mid] == key)
     {
          return (mid);
     }
     else if (arr[mid] > key)
     {
          binary_search(arr, mid + 1, max, key);
     }
     else
     {
          binary_search(arr, 0, mid - 1, key);
     }
}
void merges(int arr[], int l, int m, int u)
{
     int l1 = m - l+1;
     int l2 = u - m;

     int a1[l1];
     int a2[l2];

     for (int i = 0; i < l1; i++)
     {
          a1[i] = arr[l + i];
     }
     for (int i = 0; i < l2; i++)
     {
          a2[i] = arr[m + 1 + i];
     }
     int p = l, q = 0, r = 0;
     while (q<l1 && r<l2)
     {
          if (a1[q]>a2[r])
          {
               arr[p] = a2[r];
               r++;
               p++;
          }
          else 
          {
               arr[p] = a1[q];
               q++;
               p++;
          }
     }
     while (q<l1)
     {
          arr[p] = a1[q];
          q++;
          p++;
     }
     while (r<l2)
     {
          arr[p] = a2[r];
          r++;
          p++;
     }
}
void merge_sort(int arr[], int l, int u)
{
     if (l < u)
     {
          int mid = (l + u) / 2;
          merge_sort(arr, l, mid);
          merge_sort(arr, mid + 1, u);

          merges(arr, l, mid, u);
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
     int arr[max], key;
     printf("\nEnter the Elements : \n");
     for (int i = 0; i < max; i++)
     {
          printf("\nEnter the %d Element : ", i + 1);
          scanf("%d",&arr[i]);
     }
     printf("\nThe Array is : \n\n");
     display(arr);
     merge_sort(arr, 0, max);
     printf("\n\nThe Sorted Array is : \n\n");
     display(arr);
     printf("\nEnter the Key Element : \n");
     scanf("%d", &key);
     int res=-1; 
     res= binary_search(arr, 0, max, key);
     if (res > -1)
     {
          printf("The %d is Present at %d position ", key, res);
     }
     else
     {
          printf("%d is not Present in Array\n",key);
     }
}