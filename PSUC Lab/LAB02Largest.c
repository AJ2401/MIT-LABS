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
            printf("%d is the largest ",a);
        }
        else
        {
            printf("%d is the largest ",c);
        }
    }
    else
    {
        if(b>c)
        {
            printf("%d is the largest ",b);
        }
        else
        {
            printf("%d is the largest ",c);
        }
    }
    return 0;
}
