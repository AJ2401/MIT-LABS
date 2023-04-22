#include <stdio.h>
#include <stdlib.h>
int find(int arr[], int n)
{

    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void Replace(int m, int arr[m][m])
{

    int i, j;
    int primary[m];
    int secondary[m];
    for (i = 0; i < m; i++)
    {
        primary[i] = arr[i][i];
    }
    for (i = 0; i < m; i++)
    {
        secondary[i] = arr[i][m - i - 1];
    }
    int max_1 = find(primary, m);
    int max_2 = find(secondary, m);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == 0 || i == m - 1 || j == 0 || j == m - 1)
            {
                arr[i][j] = max_1;
            }
            else
            {
                arr[i][j] = max_2;
            }
        }
    }
}
int main()
{

    printf("ADITYA_PANDEY(200953098)\n");
    int M;
    printf("Enter the order of the matrix\n");
    scanf("%d",&M);
    int a[M][M];
    int i, j;
    printf("Enter the elements of the matrix\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The matrix is\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    Replace(M, a);
    printf("The matrix after replacing the elements \n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
