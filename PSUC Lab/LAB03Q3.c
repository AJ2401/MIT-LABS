#include<stdio.h>
int main()
{
   printf("DANDA SRINATH(200904012)\n");
    int Num,a,Sum=0,X;
    printf("Enter any Number to check whether it is Armstrong Number or Not\n");
    scanf("%d",&Num);
    X=Num;
    while(Num>0)
    {
        a=Num%10;
        Sum=Sum+(a*a*a);
        Num=Num/10;
    }
    if(X==Sum)
    {printf("The Number %d is an Armstrong Number ",X);}
    else
    {printf("The Number %d is not an Armstrong Number ",X);}
   return 0;
}
