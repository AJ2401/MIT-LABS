#include <stdio.h>
int main()
{
    printf("DANDA SRINATH(200904012)\n");
    int a,b,i=2,S;
    printf("Enter the Highest interval: ");
    scanf("%d",&b);
    printf("Enter the Lowest interval: ");
    scanf("%d",&a);
    printf("Prime numbers between %d and %d are:\n", a, b);
    while (a<b)
    {
        S=0;
        if (a<= 1)
        {
            ++a;
            continue;
        }
        while(i<=a/2)
        {

            if (a%i == 0)
            {
                S=1;
                ++i;
                break;
            }
        }
        if (S == 0)
            printf("%d , ",a);
        ++a;
    }

    return 0;
}
