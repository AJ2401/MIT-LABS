//Array is Equal or not
#include<stdio.h>
#include<stdlib.h>
int max;
int Equal(int a1[],int a2[])
{
     int c=0;
     for(int j=0;j<max;j++)
     {
           for(int i=0;i<max;i++)
          {
               if(a2[i]==a1[j])
               {
                    c++;
               }
          }
     }
     if(c==max)
     {
          return(1);
     }
     return(0);
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
     printf("\nEnter the Size of the Arrays : \n");
     scanf("%d",&max);
     int arr1[max],arr2[max],res;
     printf("\nEnter the Elements of Array 1: \n\n");
     for(int i=0;i<max;i++)
     {
          printf("Element %d ",i+1);
          scanf("%d",&arr1[i]);
     }
     printf("\nThe First Array is : \n");
     display(arr1);
     printf("\nEnter the Elements of Array 2: \n\n");
     for(int i=0;i<max;i++)
     {
          printf("Element %d ",i+1);
          scanf("%d",&arr2[i]);
     }
     printf("\nThe Second Array is : \n");
     display(arr2);

     res=Equal(arr1,arr2);
     if(res==1)
     {
          printf("\nBoth Arrays are Equal ! ");
     }
     else
     {
          printf("\nBoth Arrays are Not Equal ! ");
     }
}