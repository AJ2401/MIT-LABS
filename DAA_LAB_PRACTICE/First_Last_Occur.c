#include<stdio.h>
#include<stdlib.h>
int max;
void Method(int arr[],int start,int num)
{
     static int pos1=-1,pos2=-1;
     if(start==max)
     {
          if(pos1==-1){
          printf("%d Number is not Present in the Array !! ",num);
          return;
          }
          printf("\n %d First Occurrance in the Array is :  %d\n",num,pos1+1);
          printf("\n %d Last Occurance in the Array is : %d\n",num,pos2+1);
          return;
     }
     if(num==arr[start])
     {
           static int c=0;
           c++;
           if(c==1)
           {
                pos1=start;
           }
           pos2=start;
     }
     Method(arr,start+1,num);
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
     int n;
     printf("Enter the Length of the Array : \n");
     scanf("%d",&n);
     int arr[n];
     max=n;
     printf("Enter the  Array Elements : \n");
     for(int i=0;i<n;i++)
     {
          printf("Enter the Array Element %d : ",i+1);
          scanf("%d",&arr[i]);
     }
     printf("\nThe Array is  : \n");
     display(arr);
     int num;
     printf("\nEnter the Number to check its Occurance : \n");
     scanf("%d",&num);
     Method(arr,0,num);
}