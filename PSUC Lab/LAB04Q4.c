#include<stdio.h>
int main()
{
    printf("DANDA SRINATH(200904012)\n");
    int Num,a,X,Sum=0,i;
    printf("Enter any Number to check whether it is Perfect or Not\n");
    scanf("%d",&Num);
    X=Num;
    for(i=1; i<Num; i++)
    {
        a=Num%i;
        if(a== 0)
        {
            Sum = Sum + i;
        }

    }
    if(Sum == X)
    {
        printf("\n%d is a Perfect Number ",X);
    }
    else
    {
        printf("\n%d is not a Perfect Number ",X);
    }

    return 0;

}
