#include <stdio.h>
int main()
{
   printf("DANDA SRINATH(200904012)\n");
    int i, sum;
    sum = 0;
    printf("Enter Any Number  ");
    scanf("%d",&i);
    do
    {
        if(i>11)
        {
            sum=i-10;
            break;
        }
        if(i<11)
        {
            sum=i+10;
            continue;
        }
        if(i==11)
        {
            sum=i;
        }
    }
    while (i>10);
    printf("\nThe Sum is = %d ",sum);
    return 0;

}
