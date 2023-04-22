#include<stdio.h>
#include<math.h>
int main()
{
    printf("ABHISHEK_JHAWAR(200905144)");
    int a,b,c,x,x1;
    printf("\nEnter the a,b and c to get the roots of Quadratic equation\n");
    scanf("%d""%d""%d",&a,&b,&c);
    int discriminant=(b*b)-(4*a*c);
    switch(discriminant>0)
    {
    case 1:
        x= (-b-sqrt(discriminant))/(2*a);
        x1= (-b+sqrt(discriminant))/(2*a);
        printf("The First root is %d\n",x);
        printf("The Second root is %d\n",x1);
        break;

    case 0:
        switch(discriminant<0){
        case 1:
            x=x1=(-b+sqrt(discriminant))/(2*a);
            printf("The First root is %d\n",x);
            printf("The Second root is %d\n",x1);
            break;
        case 0:
            x=x1=-b/(2*a);
            printf("The First root is %d\n",x);
            printf("The Second root is %d\n",x1);
            break;
        }
        break;

  }
    return 0;
}
