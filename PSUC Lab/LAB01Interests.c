#include<stdio.h>
#include<math.h>
int main()
{
    printf("ABHISHEK_JHAWAR(200905144)");
    int N;
    float P,R;
    printf("\nEnter the Principle Amount ");
    scanf("%f",&P);
    printf("\nEnter the Rate of Interest ");
    scanf("%f",&R);
    printf("\nEnter the Time period of Repayment ");
    scanf("%d",&N);

    float SI,CI,x;
    SI=(P*N*R)/100;
    printf("\nThe Simple interest is : %f\n",SI);
    x=pow(1+R/100,N);
    CI=P*x-P;
    printf("\nThe Compound interest is : %f\n",CI);
    return 0;
}
