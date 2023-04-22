#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 12
struct stack
{
    int top;
    int a[max];
};
void intial(struct stack*);
void push(struct stack*,int item);
int pop(struct stack*);
int priority(char n);

int main()
{
    printf("\n ABHISHEK JHAWAR 200905144 ");
    struct stack S;
    intial(&S);
    int i=0,k=0;
    char infix[max],prefix[max],c,item,temp;
    printf("\nEnter your infix Expresion :");
    scanf("%s",infix);
    strrev(infix);
    while((c=infix[i++]) !='\0')
    {
        switch(c)
        {
        case')':
            push(&S,c);
            break;
        case'(':
            while(S.a[S.top]!=')')
            {
                temp=pop(&S);
                prefix[k++]=temp;
            }
            item=pop(&S);
            break;
        case'+':
        case'-':
        case'/':
            while(priority(S.a[S.top]>priority(c)))
            {
                temp=pop(&S);
                printf("\n Poped the Element %c",temp);
            }
            push(&S,c);
            printf("\n Pushing %c ",c);
            break;
        case'$':
            if(S.a[S.top]=='$')
            {
                temp=pop(&S);
                prefix[k++]=temp;
                printf("\n Pop and Append %c ",temp);
            }
            push(&S,'$');
            break;
        default:
            prefix[k++]=c;
        }
    }
    while(S.a[S.top]!='#')
    {
        temp=pop(&S);
        prefix[k++]=temp;
        prefix[k]='\0';
        strrev(prefix);
        strrev(infix);
        printf("\n Given Expression %s \n Prefix Expression %s ",infix,prefix);
    }
    return 0;
}
void intial(struct stack* S)
{
    S->top = -1;
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
int priority(char n)
{
    if(n == '-'|| n == '+')
    {
        return(1);
    }
    if(n =='*'||n =='/')
    {
        return(2);
    }
    if(n =='^')
    {
        return(3);
    }
    else
    {
        return(0);
    }
}
