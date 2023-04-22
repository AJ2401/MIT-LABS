#include<stdio.h>
#include<stdlib.h>
int sorted(int arr[],int n)
{
     if(n==1)
     {
          return(1);
     }
     int res=sorted(arr+1,n-1);
     if(arr[0]<arr[1] && res)
     {
          return(1);
     }
     else
     {
          return(0);
     }
}
void display(int arr[],int n)
{
     for(int i=0;i<n;i++){
     printf("  %d  ",arr[i]);
}
printf("\n");
}
void main()
{
     int n;
     printf("\nEnter the Number of Intergers :\n");
     scanf("%d",&n);
     int arr[n];
     for(int i=0;i<n;i++)
     {
          printf("\nEnter the Element %d : ",i+1);
          scanf("%d",&arr[i]);
     }
     printf("\nThe Array is : \n");
     display(arr,n);
     printf("\nThe Array is Sorted or Not ?\n");
     int res=sorted(arr,n);
     if(res==1)
     {
          printf("\nThe Array is Sorted  !!\n");
     }
     else
     {
          printf("The Array is not Sorted !! ");
     }
}