#include<stdio.h>
void Func(int a,int b,int Arr[a][b]);
int main()
{
   printf("\nADITYA_PANDEY(200953098)\n");
   int A[5][5];
   int n,m;
   printf("\nEnter the Number of Rows:\n");
   scanf("%d",&m);
   printf("\nEnter the Numbers of Columns:\n");
   scanf("%d",&n);
   printf("\nEnter the Elements of the Matrix :\n");
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
         scanf("%d",&A[i][j]);
       }
   }
   printf("\nThe Matrix is :\n");
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
         printf(" %d ",A[i][j]);
       }
       printf("\n");
   }
   Func(m,n,A);
}
void Func(int a,int b,int Arr[][b])
{
    int Sum=0;
    int x=b-1;
    Sum=Arr[0][0]+Arr[0][b-1]+Arr[a][b-x]+Arr[a][b];
    printf("\nThe Sum of Conner Elements is: %d\t",Sum);
}
