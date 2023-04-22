//Merge Sorting 
#include<stdio.h>
#include<stdlib.h>
#include"display.c"
int size;
void Merge(int arr[size],int l,int m,int u)
{
     int l1=m-l+1;
     int l2=u-m;
     int a1[l1];
     int a2[l2];
     for(int i=0;i<l1;i++)
     {
          a1[i]=arr[i+l];
     }
     for(int i=0;i<l2;i++)
     {
          a2[i]=arr[i+mid+1];
     }
}
void Merge_Sort(int arr[size],int l,int u)
{
     if(l==u)
     {
          printf("The Sorted Array Using Merge Sorting is : \n");
          display(arr);
     }
     if(l<u)
     {
          int mid=(l+u)/2;
          Merge_Sort(arr,l,mid);
          Merge_Sort(arr,mid+1,u);
          Merge(arr,l,m,u);
     }    
}
void main()
{
     printf("Enter the Size of the Array : \n");
     scanf("%d",&size);
     int arr[size];
     printf("Enter the Array Elements : \n");
     for(int i=0;i<size;i++)
     {
          printf("Element %d : ",i+1);
          scanf("%d",&arr[i]);
     }
     display(arr,size);
     Merge_Sort(arr,0,size-1);
}
