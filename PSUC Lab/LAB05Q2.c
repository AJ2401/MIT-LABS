#include<stdio.h>
int main()
{
    printf("\nABHISHEK_JHAWAR(200905144)\n");
    int A[25],n;
    printf("\nEnter the Number of Elements in an Array : \n");
    scanf("%d",&n);
    printf("\nEnter the Elements of the Array : \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nThe Array is : \n");
    for(int i=0; i<n; i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\nThe Prime Number In the Array is/are : \n");
    for(int i=0;i<n;i++)
    {
        if(A[i]==1)
        {
            continue;
        }
        int c=0;
        for(int j=2;j<A[i];j++)
        {
            if(A[i]%j==0)
            {
                c++;
                break;
            }
        }
        if(c==0)
        {
            printf(" %d ",A[i]);
        }
    }
return 0;
}
