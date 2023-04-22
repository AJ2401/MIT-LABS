#include<stdio.h>
#define max 50
void display(int*,int);
void smallest(int*,int);
int main()
{
    int n;
    int arr[max];
    printf("\n Enter the Value of n : \n\n");
    scanf("%d",&n);

    printf("\n Enter the Elements of the Array : \n\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n The Array is : \n\n");
    display(arr,n);
    smallest(arr,n);
    printf("\n\n");
}
void display(int* Arr,int limit)
{
    for(int i=0;i<limit;i++)
    {
        printf("%d\t",Arr[i]);
    }
}
void smallest(int* Arr,int limit)
{
    int temp;
    for(int i=0;i<limit-1;i++)
    {
        for(int j=0;j<limit-i-1;j++)
        {
            if(Arr[j]>Arr[j+1])
            {
                temp=Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j+1]=temp;
            }
        }
    }
    int a=Arr[0];
    printf("\n\n The Smallest Element in the Array is %d ",a);
}
