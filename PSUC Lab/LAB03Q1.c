#include<stdio.h>
int main()
{
    printf("DANDA SRINATH(200904012)\n");
    int num,a;
    printf("Enter a number ");
    scanf("%d",&num);
    printf("\nThe palidrome of the Given Number is\n");
    while(num>0)
    {
        a=num%10;
        num=num/10;
        printf("%d",a);
    }
   return 0;
}
