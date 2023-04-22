#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int*array;
    int n1;
    int top;
};
void intial(struct stack*S)
{
    S->top=-1;
    S->n1=100;
    S->array=(int*)malloc(100*sizeof(int));
}
void push(struct stack*S,int num)
{
    if(S->top!=S->n1)
    {
        S->top++;
        S->array[S->top]=num;
    }
}
void display(struct stack*S)
{
    while(S->top!=-1)
    {
        printf(" %d ",S->array[S->top]);
        S->top--;
    }
}
void main()
{
    struct stack*S;
      intial(&S);
    int num,ele[50],i=0;
    printf("Enter the Number to be Converted in Binary : \n");
    scanf("%d",&num);
    while(num>0)
    {
        ele[i]=num%2;
        num=num/2;
        push(&S,ele[i]);
        i++;
    }
    printf("The Binary Number is : \n");
    display(&S);
    return 0;
}

