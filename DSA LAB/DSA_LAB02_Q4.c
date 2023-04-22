#include<stdio.h>
#include<stdlib.h>
void tower(int n,char first_rod,char second_rod,char third_rod)
{
    if(n == 1)
    {
        printf("Move disk %d from Rod %c ",1,first_rod);
        printf("To Rod %c ",second_rod);
        printf("\n\n");
        return;
    }
        tower(n-1,first_rod,third_rod,second_rod);
        printf("Move disk %d ",n);
        printf("From Rod %c ",first_rod);
        printf("To Rod %c ",second_rod);
        printf("\n\n");
        tower(n-1,third_rod,second_rod,third_rod);
}
int main()
{
    printf("\n ABHISHEK JHAWAR(200905144)\n");
    int n=3;
    tower(n,'X','Y','Z');
    return 0;
}
