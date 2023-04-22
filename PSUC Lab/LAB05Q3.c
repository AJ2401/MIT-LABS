#include<stdio.h>
int main()
{
 printf("\nABHISHEK_JHAWAR(200905144)\n");
  int A[10];
  printf("\nEnter The Elements in the Array :\n");
  for(int i=0;i<10;i++)
  {
      scanf("%d",&A[i]);
  }
  printf("\nThe Original Array is : \n");
  for(int i=0;i<10;i++)
  {
      printf("%d ,",A[i]);
  }
for(int j=0;j<10;j++)
 {
     for(int i=0;i<10;i++)
  {
      if(A[i]>A[i+1])
      {
          int temp;
          temp=A[i];
          A[i]=A[i+1];
          A[i+1]=temp;
      }
  }
 }
  printf("\nThe Sorted Array is :\n");
  for(int i=0;i<10;i++)
  {
      printf("%d ,",A[i]);
  }
}
