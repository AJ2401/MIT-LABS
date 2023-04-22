#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    char A[10];
};
void initial(struct stack*);
void display(struct stack*);
void push(struct stack*,char c);
char pop(struct stack*);
int isEmpty(struct stack*);
int isFull(struct stack*);

int main()
{
    printf("\n ABHISHEK JHAWAR(200905144) \n");
    struct stack S;
    intial(&S);
    push(&S,'H');
    push(&S,'A');
    push(&S,'P');
    push(&S,'P');
    push(&S,'Y');
    push(&S,'M');
    push(&S,'A');
    push(&S,'N');
    printf("\n The Stack is : \n");
    display(&S);
    char ele=pop(&S);
    if(ele!=NULL)
    {
        printf("\n The iten is Popoed %c\t",ele);
    }
    ele =pop(&S);
    if(ele!=NULL)
    {
        printf("\n The iten is Popoed %c\t",ele);
    }
    printf("\n After Deletion of Some Elements : \n");
    display(&S);
    return(0);
}
void intial(struct stack* P)
{
    P->top=-1;
}
void push(struct stack* P,char c)
{
    if(isFull(P)==1)
    {
        printf("\n The Stack is Full.\n");
    }
    else
    {
        P->top++;
        P->A[P->top]=c;
    }
}
int isFull(struct stack* P)
{
    if(P->top == 9)
    {
        // printf("\n Stack is Overflow \n");
        return(1);
    }
    else
    {
        return(0);
    }
}
char pop(struct stack* P)
{
    if(isEmpty(P) == 1)
    {
        printf("\n Stack is Empty \n");
    }
    else
    {
        char ch=P->A[P->top];
        P->A[P->top]=NULL;
        P->top--;
        return(ch);
    }
}
int isEmpty(struct stack* P)
{
    if(P->top == -1)
    {
        //  printf("\n Stack is Underflow \n");
        return(1);
    }
    else
    {
        return(0);
    }
}
void display(struct stack* P)
{
    for(int i=0; i<9; i++)
    {
        printf("%c ",P->A[i]);
    }
}


