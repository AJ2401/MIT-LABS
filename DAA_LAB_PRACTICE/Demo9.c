//Quick Sort
#include<stdio.h>
#include<stdlib.h>
int max;
void swap(int arr[],int p1,int p2)
{
     int temp=arr[p1];
     arr[p1]=arr[p2];
     arr[p2]=arr[p1];
}
int part(int arr[],int l,int h)
{
     int min=arr[h];
     int i=l-1;
     for(int j=l;j<h;j++){
          if(arr[j]<min)
          {
               i++;
               swap(arr,i,j);
          }
     }
     swap(arr,i+1,h);

return(i+1);
}
void Sort(int arr[],int l,int h)
{
     if(l<h)
     {
          int p=part(arr,l,h);

          Sort(arr,l,p-1);
          Sort(arr,p+1,h);
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
     int arr[max];
     printf("Enter the Array Size : \n");
     scanf("%d",&max);
     printf("Enter the Array Elements :\n");
     for(int i=0;i<max;i++)
     {
          printf("Element %d :\n",i+1);
          scanf("%d",&arr[i]);
     }
     printf("The Array is : \n");
     display(arr);
     printf("The Sorted Array is : \n");
     Sort(arr,0,max-1);
     display(arr);
}