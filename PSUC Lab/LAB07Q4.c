#include<stdio.h>
void func(int* B,int max)
{
    int L=B[0];
    int S=B[0];
    for(int i=1;i<max;i++)
    {
        if(B[i]>L)
        {
            L=B[i];
        }
        if(B[i]<S)
        {
            S=B[i];
        }
    }
    printf("\nThe Smallest Element is : %d",S);
    printf("\nThe Largest Element is : %d",L);
}
int main()
{
     printf("\nADITYA_PANDEY(200953098)\n");
    int n;
    int A[35];
    printf("\nEnter the number of Array Elements: \n");
    scanf("%d",&n);
    printf("\nEnter the Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    func(A,n);
}

