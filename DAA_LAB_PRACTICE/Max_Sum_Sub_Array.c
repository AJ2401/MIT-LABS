//Maximum sum of sub array
#include<stdio.h>
#include<stdlib.h>
int max;
void initialize(int arr[])
{
     for(int i=0;i<max;i++)
     {
          arr[i]=0;
     }
}
void swap(int arr[],int p1,int p2)
{
     int temp=arr[p1];
     arr[p1]=arr[p2];
     arr[p2]=temp;
}
void sort(int arr[])
{
    for(int i=0;i<max-1;i++)
    {
     for(int j=0;j<max-1-i;j++)
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
     printf("Enter the Array size : \n");
     scanf("%d",&max);
     int arr[max];
     int index[max];
     initialize(arr);
     initialize(index);
     printf("Enter the Array Elements : \n");
     for(int i=0;i<max;i++)
     {
          printf("Element %d ",i+1);
          scanf("%d",&arr[i]);
     }
     int k=0;
     for(int i=0;i<max;i++)
     {
          for(int j=i;j<max;j++)
          {
               if(arr[i]==arr[j])
               {
                    index[k]=arr[i];
                    k++;
               }
          }
     }
     sort(index);
     printf("The Smallest is : %d ",index[0]);
}