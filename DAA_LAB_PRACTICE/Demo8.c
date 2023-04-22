//Merge Sort
#include<stdio.h>
#include<stdlib.h>
int max;
void display(int arr[])
{
     for(int i=0;i<max;i++)
     {
          printf("  %d  ",arr[i]);
     }
}
void merge(int arr[],int l,int m,int u)
{
     int l1=m-l+1;
     int l2=u-m;

     int a1[l1];
     int a2[l2];
     for(int q=0;q<l1;q++)
     {
          a1[q]=arr[l+q];
     }
     for(int p=0;p<l2;p++)
     {
          a2[p]=arr[m+1+p];
     }
    // int arr1[max];
     int i=0,j=0,k=l;
     while(i<l1 && j<l2)
     {
          if(a1[i]<a2[j])
          {
               arr[k]=a1[i];
               i++;
               k++;
          }
          else
          {
               arr[k]=a2[j];
               j++;
               k++;
          }
     }
     while(i<l1)
     {
          arr[k]=a1[i];
          k++;
          i++;
     }
     while(j<l2)
     {
          arr[k]=a2[j];
          j++;
          k++;
     }
     /*for(int i=0;i<max;i++)
     {
          arr[i]=arr1[i];
     }*/
}
void Sort(int arr[],int l,int u)
{
     if(l<u)
     {
          int mid=(u+l)/2;
          Sort(arr,l,mid);
          Sort(arr,mid+1,u);

          merge(arr,l,mid,u);
     }
}

void main()
{
     printf("Enter the Size of the Array : \n");
     scanf("%d",&max);
     int arr[max];
     printf("Enter the Array Elements :\n");
     for(int i=0;i<max;i++)
     {
          printf("Enter the %d Element \n",i+1);
          scanf("%d",&arr[i]);
     }
     printf("\nThe Array is : \n");
     display(arr);
     Sort(arr,0,max);
     printf("\nThe Sorted Array is : \n");
     display(arr);
}
