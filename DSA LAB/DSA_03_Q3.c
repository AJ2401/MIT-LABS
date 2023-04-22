#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
struct stack
{
    int top;
    char arr[max];
};
void push(struct stack* S,char item)
{
    S->top++;
    S->arr[S->top]=item;
}
char pop(struct stack* S)
{
    char data;
    data=S->arr[S->top];
    S->top--;
    return(data);
}
int main()
{
    printf("\n ABHISHEK JHAWAR(200905144)\n");
    struct stack S;
    int n,count=0;
    char a[max];
    printf("\n Enter any String to check whether it is palidrome or not ?\n");
    scanf("%s",a);
    n=strlen(a);
    for(int i=0; i<n; i++)
    {
        push(&S,a[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(a[i] == pop(&S))
        {
            count++;
        }
    }
    if(count == n)
    {
        printf("\n The String is Palidrome \n");
    }
    else
    {
        printf("\n The String is not Palidrome \n");
    }
}
