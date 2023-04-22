#include<stdio.h>
int main()
{
    printf("DANDA SRINATH(200904012)\n");
    int K,N,i,j;
    printf("Enter the Number of columns :");
    scanf("%d",&N);
    printf("Enter the Number of Rows :");
    scanf("%d",&K);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=K;j++)
        {
            printf("%d\t",i*j);
        }
        printf("\n");
    }
    return 0;
}
