#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct DOB
{
 int date;
 char* month;
 int year;
};
struct STU_INFO
{
    int reg_no;
    char* name;
    char add[20];
};
struct CLG
{
     char* clg_name;
     char uni_name[20];
};
struct Student
{
    struct DOB dob;
    struct STU_INFO stu_info;
    struct CLG clg;
};
int main()
{
    printf("\n ABHISHEK JHAWAR(200905144)\n");
    struct Student S;
    char m[20];char n[20];char clgname[20];

    printf("\n Enter the Birth date :\n");
    scanf("%d",&S.dob.date);

    printf("\n Enter the Birth Month :\n");
    scanf("%s",&m);
    S.dob.month=(char*)malloc(sizeof(m));
    strcpy(S.dob.month,m);

    printf("\n Enter the  Birth Year : \n");
    scanf("%d",&S.dob.year);

    printf("\n Enter the Registration Number : \n");
    scanf("%d",&S.stu_info.reg_no);

    printf("\n Enter Your Name :\n");
    scanf("%s",&n);
    S.stu_info.name=(char*)malloc(sizeof(n));
    strcpy(S.stu_info.name,n);

    printf("\n Enter your Address : \n");
    scanf("%s",&S.stu_info.add);

    printf("\n Enter Your College Name : \n");
    scanf("%s",&clgname);
    S.clg.clg_name = (char*)malloc(sizeof(clgname));
    strcpy(S.clg.clg_name,clgname);

    printf("\n Enter your University : \n");
    scanf("%s",&S.clg.uni_name);

    printf("\n\n");
    printf("\n DISPLAYING STUDENT DETAILS : \n");
    printf("\n\tThe Birth date is: ");
    printf("%d",S.dob.date);

    printf("\n\tThe Birth Month is : ");
    printf("%s",m);

    printf("\n\tThe  Birth Year : ");
    printf("%d",S.dob.year);

    printf("\n\tThe Registration Number : ");
    printf("%d",S.stu_info.reg_no);

    printf("\n\tName : ");
    printf("%s",n);

    printf("\n\tAddress :  ");
    printf("%s",S.stu_info.add);

    printf("\n\tCollege Name : ");
    printf("%s",clgname);

    printf("\n\tUniversity : ");
    printf("%s",S.clg.uni_name);

    printf("\n\n");
    return 0;
}
