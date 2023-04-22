#include<stdio.h>
int main()
{
    printf("\nADITYA_PANDEY(200953098)\n");
    int A[8][8],B[8][8],P[8][8],Sum=0,an,am,bn,bm;
    printf("\nEnter the Number rows and columns of the  First Matrix( rows,columns)resp :\n");
    scanf("%d %d",&am,&an);
    printf("\nEnter the Number rows and columns of the Second Matrix(rows,columns)resp :\n");
    scanf("%d %d",&bm,&bn);
    printf("\nEnter the First Array Elements :\n");
    for(int i=0;i<am;i++)
    {
        for(int j=0;j<an;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nEnter the Second Array Elements(rows,columns)resp :\n");
    for(int i=0;i<bm;i++)
    {
        for(int j=0;j<bn;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    printf("\nThe First Matrix is :\n");
    for(int i=0;i<am;i++)
    {
        for(int j=0;j<an;j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\nThe Second Matrix is :\n");
    for(int i=0;i<bm;i++)
    {
        for(int j=0;j<bn;j++)
        {
            printf(" %d ",B[i][j]);
        }
        printf("\n");
    }
    if(bm!=an)
    {
        printf("The Multiplication cannot be performed ");
    }
    else
    {
        for(int i=0;i<am;i++)
        {
            for(int j=0;j<bn;j++)
            {
                for(int k=0;k<bm;k++)
                {
                   Sum=Sum+(A[i][j]*B[i][j]);
                }
                P[i][j]=Sum;
                Sum=0;
            }
        }
    }
   printf("\nThe Resultant Matrix is :\n");
    for(int i=0;i<am;i++)
    {
        for(int j=0;j<an;j++)
        {
            printf(" %d ",P[i][j]);
        }
        printf("\n");
    }
}
