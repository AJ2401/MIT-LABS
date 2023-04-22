#include<stdio.h>
void func(int *Array,int pos,int val,int max)
{
    for(int i=max;i>=pos;i--)
    {
        Array[i]=Array[i-1];
    }
    Array[pos]=val;
}
int main()
{
    printf("\nABHISHEK_JHAWAR(200905144)\n");
    int A[25],n,m,num;
    printf("\nEnter the number of Elements in the Array :\n");
    scanf("%d",&n);
    printf("\nEnter the Elements in the Array: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nThe Original Array is :\n");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\nEnter the Position where the Element to be Inserted : \n");
    scanf("%d",&m);
    printf("\nEnter the Value which is to be Inserted : \n");
    scanf("%d",&num);

    func(A,m,num,n);

    printf("\nThe New Array is :\n");
    for(int i=0;i<n+1;i++)
    {
        printf(" %d ",A[i]);
    }
}
