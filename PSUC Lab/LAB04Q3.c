#include<stdio.h>
#include<math.h>
double fact(int j)
{
    double Sum=1;
    for(int i=1;i<=j;i++)
    {
       Sum=Sum*i;

    return(Sum);
    }
}
void calculate(float a,int c,float *b)
{
    int S=1;int d=1;
    for(int i=1;(d<c);i+=2)
    {
        S=-1*S*(-1);
        *b=*b+S*(pow(a,i)/fact(i));
        d++;
    }
}

int main()
{
    int X,n;
    const float pi=3.1459;
     float r,Formula=0;
    printf("DANDA SRINATH(200904012)\n");
    printf("Enter the Value of x in Degrees ");
    scanf("%d",&X);
    printf("Enter the Value so How many times to Iterate it ");
    scanf("%d",&n);
    r=X*(pi/180);
    calculate(r,n,&Formula);
    printf("Sin(%d) =%f ",X,Formula);
 return 0;
}
