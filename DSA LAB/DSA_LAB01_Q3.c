#include<stdio.h>
#define max10
struct DOB
{
    int d,m,y;
};
struct add
{
    int house_no;
    long int pin;
    char state[25];
};
struct Employ
{
    char name[30];
    struct DOB bd;
    struct add Add;
};
int main()
{
    int n;
    printf("\n The Number of Employee \n");
    scanf("%d",&n);

    struct Employ emp[n];
    for(int i=0;i<n;i++)
    {
        printf("\nDetails of %d Employ is : ",i+1);

        printf("\n\nThe Name : ");
        scanf("%s",&emp[i].name);

        printf("\nBirth Date : ");
        scanf("%d""%d""%d",&emp[i].bd.d,&emp[i].bd.m,&emp[i].bd.y);

        printf("\nAddress is : ");

        printf("\nHouse Number : ");
        scanf("%d",&emp[i].Add.house_no);
        printf("\nPincode: ");
        scanf("%ld",&emp[i].Add.pin);
        printf("\nState: ");
        scanf("%s",&emp[i].Add.state);
    }
     for(int i=0;i<n;i++)
    {
        printf("Details of %d Employ is : ",i+1);

        printf("\n\nThe Name - ");
        printf("%s",emp[i].name);
        printf("\nBirth Date - ");
        printf("%d/""%d/""%d",emp[i].bd.d,emp[i].bd.m,emp[i].bd.y);
        printf("\nAddress is - ");
        printf("\nHouse Number - ");
        printf("%d",emp[i].Add.house_no);
        printf("\nPincode - ");
        printf("%ld",emp[i].Add.pin);
        printf("\nState - ");
        printf("%s",emp[i].Add.state);
    }
}
