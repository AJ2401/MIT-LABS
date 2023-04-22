#include<stdio.h>
int main()
{
   printf("DANDA SRINATH(200904012)\n");
    int Num,X,a,Sum=0;
    printf("\nEnter Any Number check Its  Strong or Not\n");
    scanf("%d",&Num);
    X=Num;
    while(Num>0)
    {
        a=Num%10;
        int c=1;
        int s=1;
        while(c<=a)
        {
            s=s*c;
            c++;
        }
        printf("\n%d the Number's factorial is ---> %d\n",a,s);
        Sum=s+Sum;
        Num=Num/10;
    }
    if(X==Sum)
    {
        printf("\nIt %d is a Strong Number\n",X);
    }
    else
    {
        printf("\nIt %d is not a Strong Number ",X);
    }
    return 0;
}
