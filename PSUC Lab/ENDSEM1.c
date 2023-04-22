#include<stdio.h>
#include<stdlib.h>
/*int find(int*Arr,int m)
{
    if(Arr[0]>Arr[1])
    {
        if(Arr[0]>Arr[2])
        {
            printf("%d",Arr[0]);
            return Arr[0];
        }
        else
        {
            printf("%d",Arr[2]);
            return Arr[2];
        }

    }
    else

        if(Arr[1]>Arr[2])
        {
            printf("%d",Arr[1]);
            return Arr[1];
        }
        else
        {
            printf("%d",Arr[2]);
            return Arr[2];
        }
}
void Replace(int Array[][3],int s,int max,int Max)
{
    for(int i=1; i<=s; i++)
    {
        for(int j=1; j<=s; j++)
        {
            Array[i][j]=max;

            if(i==2 && j==2)
            {
                Array[i][j]=Max;
            }
        }
    }
      printf("The Modified Array is :");
    for(int i=1; i<=s; i++)
    {
        for(int j=1; j<=s; j++)
        {
            printf(" %d ",Array[i][j]);
        }
        printf("\n");
    }


}*/
int main()
{
    int M;
    printf("Enter the number of the Matrix : M*M \n");
    scanf("%d",&M);
    int A[M][M],P[M],S[M];
    printf("Enter the Elements of the Array :\n");
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("\nThe Matrix is :\n");
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
    int K=0;
     for(int i=0;i<M;i++)
     {
         for(int j=0;j<M;j++)
         {
             if(i==j)
             {
                P[K] =A[i][j];
                K++;
             }
             if(j==M-1-i)
             {
                 S[K]=A[i][j];
                 K++;
             }
         }
     }
     printf("\nThe Primary Diagonal is :\n");
     for(int i=0;i<M;i++)
     {
         printf(" %d ",P[i]);
     }
     printf("\nThe Secondary Diagonal is :\n");
     for(int i=0;i<M;i++)
     {
         printf(" %d ",S[i]);
     }
   /* printf("The Largest Number in the Primary Diagonal is:\n");
     find(&P,M);
    printf("\nThe Largest Number in the Secondary Diagonal is:\n");
     find(&S,M);

    printf("Before Array is :\n");
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=M; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
 void Replace(int M,int A[][M],int a,int b);*/
}
