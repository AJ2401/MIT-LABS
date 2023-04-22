#include<stdio.h>
int main()
{
    printf("DANDA SRINATH(200904012)\n");
    int N,i,j,a=1;
    printf("Enter the Number till which you want the Floyd's Triangle\n");
    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=i; j++)
        {
           printf(" %d ",a++);
        }
        printf("\n");
    }
    return 0;
}
