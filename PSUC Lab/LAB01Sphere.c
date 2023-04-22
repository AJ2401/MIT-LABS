#include<stdio.h>
#include<math.h>
int main()
{
    printf("ABHISHEK_JHAWAR(200905144)\n");
    int r;
    printf("\nEnter the Radius of the Sphere :");
    scanf("%d",&r);
    float Vol,Ar;
    int x;
    x=pow(r,2);
    Ar=(4*3.14*x)/3;
    printf("\nThe required Area obtained is %f\n",Ar);
    x=pow(r,3);
    Vol=4*3.14*x;
    printf("\nThe required Volume obtained is %f\n",Vol);
}
