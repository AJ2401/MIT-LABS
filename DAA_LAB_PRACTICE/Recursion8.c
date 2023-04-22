//First and Last Occurrence of the Number
#include<stdio.h>
#include<stdlib.h>
#include "display.h"
int max;
int top=-1;
void occur(int arr[],int l,int res[],int key)
{
     if(l==max)
     {
          return;
     }
     if(l<max)
     {
          if(arr[l] ==key && top==-1)
          {
               res[++top]=l;
          }
          if(arr[l]==key && top==0)
          {
               res[1]=l;
          }
          occur(arr,l+1,res,key);
     }
}
void main()
{
     printf("Enter the Size of the Array : \n");
     scanf("%d",&max);
     int arr[max],key,f,l;
     printf("Enter the Array Elements : \n");
     for(int i=0;i<max;i++)
     {
          printf("Element %d ",i+1);
          scanf("%d",&arr[i]);
     }
     display(arr,max);
     printf("Enter the Key to be Searched \n");
     scanf("%d",&key);
     int res[2];
     occur(arr,0,res,key);
     printf("The First Occurrence %d ",res[0]+1);
     printf("\nThe  Last Occurrence is %d ",res[1]+1);
}