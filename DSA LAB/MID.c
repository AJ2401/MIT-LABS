#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    char a[];
};
void intial(struct stack* S)
{
    S->top=-1;
}
void push(struct stack* S,char c)
{
    S->top++;
    S->a[S->top]=c;
}
void pop(struct stack*S)
{
    char data;
    data=S->a[S->top];
    printf("%c",data);
    S->top--;
}
int main()
{
    struct stack S;
    char sen;
    int a=0;
    printf("\n Enter any String :\n");
    while(a>=0)
    {
        sen=(char)malloc(sizeof(char));
        scanf("%c",&sen);
        push(&S,sen);
        a++;
    }
    for(int i=0;i<a;i++)
    {
        pop(&S);
    }
}
