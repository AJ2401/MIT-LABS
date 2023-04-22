#include<stdio.h>
#include<math.h>
int main()
{
    printf("\nADITYA_PANDEY(200953098)\n");
    int A[10][10],sum=0,norm,Sum=0,n,m,a;
    printf("\nEnter the Number of Elements in the Matrix(rows and columns) :\n");
    scanf("%d %d",&m,&n);
    printf("\nEnter the Array Elements :\n");
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
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           a=A[i][j]*A[i][j];
          sum=sum+a;
        }
    }
    norm=sqrt(sum);
    printf("\nThe norm of the Matrix is :%d\t",norm);
    printf("\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
         Sum=Sum+A[i][j];
        }
    }
    printf("\nThe Trace of the Matrix is :%d\t",Sum);
    printf("\n");
}
