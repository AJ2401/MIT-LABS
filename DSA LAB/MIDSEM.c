#include<stdio.h>
//inlcude<stdlib.h>
struct stack
{
    char a;
    int top;
};
//void intial(struct stack*);
void push(struct stack*,char item);
char pop(struct stack*);
int main()
{
    struct stack S;
    int len=0;
    intial(&S);
    char arr;
    printf("Enter any String to be Reversed");
    while(len>=0)
    {
        scanf("%c",&arr);
        push(&S,arr);
        len++;
    }
    printf("The Reversed String is ");
    for(int i=0;i<len;i++)
    {
        if(arr== "\t"||arr==" ")
        {
            continue;
        }
        else
        {
            char i=pop(&S);
            printf("%c",i);
        }
    }
}
void push(struct stack* S,char data )
{
    S->top++;
    S->a=data;
}
char pop(struct stack* S)
{
    char data;
    data=S->a;
    return(data);
}
