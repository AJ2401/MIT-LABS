#include<stdio.h>
int main()
{
    printf("\nADITYA_PANDEY(200953098)\n");
    int A[3][3];
    printf("\nEnter the Element in the Array :\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nThe Array is :\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("  %d  ",A[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int tempo;
            int temp;
            if(i==0 && j==0)
            {
                tempo = A[i][j];
                A[i][j]= A[i][j+2];
                A[i][j+2]=tempo;
            }
            if(i=j=2)
            {
                temp=A[i][j];
                A[i][j]=A[i][j-2];
                A[i][j-2]=temp;
            }
        }
    }
    printf("\nThe New Array is :\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("  %d  ",A[i][j]);
        }
        printf("\n");
    }
return 0;
}
