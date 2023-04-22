#include<stdio.h>
/*int Swap(int m,int n)
{
    int temp=0;
    m=temp;
    m=n;
    n=temp;
return(m,n);
}*/
int main()
{
   int A[8]={12,2,3,9,7,5,18,7};
   int i=0;
   int j=7;
   int temp;
   while(j>=i)
   {
       while(i<j)
       {
      if(A[i]>A[j])
       {
           temp=A[i];
           A[i]=A[j];
           A[j]=temp;
       }
       i++;
        }
       j--;

   }
   while(j>=i)
   {
    printf(" %d ",A[i]);
    i++;
   }
}
