#include<stdio.h>
int main()
{
    printf("\nABHISHEK_JHAWAR(200905144)\n");
    int L,S,n;
    int A[35];
    printf("\nEnter the number of Array Elements: \n");
    scanf("%d",&n);
    printf("\nEnter the Array Elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
        L=A[0];
        S=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>L)
        {
            L=A[i];
        }
        if(A[i]<S)
        {
            S=A[i];
        }
    }
    printf("\nThe Smallest Element is : %d",S);
    printf("\nThe Largest Element is : %d",L);
}
