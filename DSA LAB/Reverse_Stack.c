#include<stdio.h>
#include<stdlib.h>
#define max 10
struct stack
{
    int top;
    int Array[max];
};
void intial(struct stack*S)
{
    S->top=-1;
}
void push(struct stack*S,int item)
{
    if(S->top!=max)
    {
        S->top++;
        S->Array[S->top]=item;
    }
}
void pop(struct stack*S)
{
    if(S->top!=-1)
    {
        int item=S->Array[S->top];
        S->top--;
      //  printf("%d Element is POPED ! ! ",item);
    }
}
void Insert_Bottom(struct stack*S,int top)
{
    if(S->top==-1)
    {
        push(&S,top);
        return;
    }
    else
    {
        int ele=S->Array[S->top];
        pop(&S);
        Insert_Bottom(&S,top);
        push(&S,ele);
    }
}
void reverse(struct stack*S)
{
    if(S->top==-1)
    {
        return;
    }
    else
    {
        int top=S->Array[S->top];
        pop(&S);
        reverse(&S);
        Insert_Bottom(&S,top);
    }
}

void display(struct stack*S)
{
    while((S->top) > -1)
    {
        printf("|\t%d \t|\n",S->Array[S->top]);
        S->top--;
    }
}
int main()
{
    struct stack*S;
    intial(&S);
    int item,opt,n=1;
    while(n>0)
    {
        printf("Choose your option \n1)PUSH\n2)POP\n3)Reverse\n4)Display\n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter the Number : \n");
            scanf("%d",&item);
            push(&S,item);
            break;
        case 2:
            pop(&S);
            break;
        case 3:
            printf("Reversing the Stack !! \n");
            reverse(&S);
            display(&S);
            break;
        case 4:
            printf("The Stack is : \n");
            display(&S);
            break;
        default:
            printf("**ERROR**\n");
            break;
        }
    }

}
