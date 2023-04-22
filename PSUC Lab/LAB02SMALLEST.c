#include<stdio.h>
int main()
{
    printf("ABHISHEK_JHAWAR(200905144)");
    int a,b,c;
    printf("\nEnter Three Numbers\n ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        if(a>c)
        {
            printf("%d is the Smallest ",c);
        }
        else
        {
            printf("%d is the Smallest",b);
        }
    }
    else
    {
        if(b>c)
        {
            printf("%d is the Smallest ",c);
        }
        else
        {
            printf("%d is the Smallest",a);
        }
    }
    return 0;
}
