#include<stdio.h>
int main()
{
   printf("\nADITYA_PANDEY(200953098)\n");
    int A[3][3],n,count=0;
    printf("\nEnter the Element in the Array :\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nThe Array is :\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("  %d  ",A[i][j]);
        }
        printf("\n");
    }
    printf("\nThe Number to be Searched :\n");
    scanf("%d",&n);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(A[i][j]==n)
            {
                count++;
            }
        }
    }
    printf("\nThe Number  %d  occurred  %d  times in the Array :\n",n,count);
}
