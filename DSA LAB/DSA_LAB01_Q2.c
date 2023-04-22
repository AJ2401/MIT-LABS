#include<stdio.h>
#include<stdlib.h>
#define max 3
int main()
{
    int Arr1[max][max],Arr2[max][max];

    printf("\n Enter the Elements of Array 1 : \n");
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            scanf("%d",&Arr1[i][j]);
        }
    }
    printf("\n The Array is :\n");
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            printf("%d\t",Arr1[i][j]);
        }
        printf("\n");
    }

    printf("\n Enter the Elements of Array 2 : \n");

    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            scanf("%d",&Arr2[i][j]);
        }
    }
   printf("\n The  Array is : \n");
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            printf("%d\t",Arr2[i][j]);
        }
        printf("\n");
    }

    printf("\n The Multiplication of Array 1 and Array 2 : \n");

    int Arr3[max][max];
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            Arr3[i][j]=0;
            for(int k=0;k<max;k++)
            {
                Arr3[i][j]=Arr3[i][j]+ Arr1[i][k] * Arr2[k][j];
            }
        }
    }
   for(int i=0;i<max;i++)
   {
       for(int j=0;j<max;j++)
       {
           printf("%d\t",Arr3[i][j]);
       }
       printf("\n");
   }
}

