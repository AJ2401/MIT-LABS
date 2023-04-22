#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 25
struct stack
{
    int top;
    int a[max];
};
void intial(struct stack*);
void push(struct stack*,int item);
int pop(struct stack*);
int evaluate(char opr,int n1,int n2);
int main()
{
    printf("\n ABHISHEK JHAWAR 200905144 \n");
    struct stack S;
    intial(&S);
    char exp[max];
    char c;
    int op1,op2,result,i=0;
    printf("Enter any prefix Expression : \n");
    scanf("%s",exp);
    printf("%s",exp);
    strrev(exp);
    while((c=exp[i++]) != '\0')
    {
        if(isdigit(c))
        {
            push(&S,c-'0');
        }
        else
        {
            op1=pop(&S);
            op2=pop(&S);
            result = evaluate(c,op1,op2);
            push(&S,result);
        }
    }
    printf("\n The Result is = %d ",pop(&S));
    return(0);
}
void intial(struct stack* S)
{
    S->top=-1;
}
void push(struct stack* S,int item)
{
    S->top++;
    S->a[S->top]=item;
}
int pop(struct stack* S)
{
    int data;
    data=S->a[S->top];
    S->top--;
    return(data);
}
int evaluate(char opr,int n1,int n2)
{
    switch(opr)
    {
    case '+':
        return(n1+n2);
    case '-':
        return(n1-n2);
    case '/':
        return(n1/n2);
    case '*':
        return(n1*n2);
    case '$':
         return(pow(n1,n2));
    }
}
