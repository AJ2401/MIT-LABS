#include<stdio.h>
void func(int *Array,int pos,int max)
{
    int i;
    for(i=pos;i<max;i++)
    {
        Array[i-1]=Array[i];
    }
     Array[i-1]=0;

}
int main()
{
    printf("\nABHISHEK_JHAWAR(200905144)\n");
    int A[35],n,m;
    printf("\nEnter the Number of elements in an Array : \n");
    scanf("%d",&n);
    printf("\nEnter the Elements of an Array : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nOriginal Array is : \n");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\nEnter the Array Element which is to be Deleted : \n");
    scanf("%d",&m);
    func(A,m,n);
    printf("\nThe New Array is :\n");
    for(int i=0;i<n-1;i++)
    {
        printf(" %d ",A[i]);
    }
}
