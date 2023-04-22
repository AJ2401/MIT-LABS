#include<stdio.h>
int main()
{
    printf("\nADITYA_PANDEY(200953098)\n");
    int A[8][8],B[8][8],count=0,n;
    printf("\nEnter the Number of Elements in the Matrix :\n");
    scanf("%d",&n);
    printf("\nEnter the First Array Elements :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nEnter the Second Array Elements :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    printf("\nThe First Matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\nThe Second Matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %d ",B[i][j]);
        }
        printf("\n");
    }
    printf("\nChecking Whether both are Symmetric or not :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==B[i][j])
            {
                count=1;
                break;
            }
        }
    }
    if(count==1)
    {
      printf("\tBoth are Symmetric");
    }
    else
    {
      printf("\tBoth are not Symmetric");
    }
    printf("\n");
}
