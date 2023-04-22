#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int n;
    int*Array;
    int top;
};
void intial(struct stack*S,int n)
{
    S->top=-1;
    S->n=n;
    S->Array=(int*)malloc(n*sizeof(int));
}
int isEmpty(struct stack*S)
{
    if(S->top==-1)
    {
        printf("** STACK UNDERFLOW **");
        return 1;
    }
}
int isFull(struct stack*S)
{
    if(S->top==S->n)
    {
        printf("** STACK OVERFLOW **");
        return 1;
    }
}
void push(struct stack*S,int item)
{
    if(isFull(&S)!=1)
    {
        S->top++;
        S->Array[S->top]=item;
    }
}
void pop(struct stack*S)
{
    if(isEmpty(&S)!=1)
    {
         int ele=S->Array[S->top];
        S->top--;
        printf("%d Element is POPED !! \n",ele);
    }
}
void display(struct stack*S)
{
    int c=0;
    while(S->top!=-1)
    {
        printf("|\t%d\t|\n",S->Array[S->top]);
        S->top--;
        c++;
    }
    printf("\nNumber of Characters are : %d",c);
}
int main()
{
    struct stack *S;
    int opt,n,item,ele;
    printf("Enter the Length of the Array : \n");
    scanf("%d",&n);
    intial(&S,n);
    while(n>0)
    {
        printf("Choose your Option\n1)PUSH\n2)POP\n3)DISPLAY\n4)RESIZE the Array \n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter the Element : \n");
            scanf("%d",&item);
            push(&S,item);
            break;
        case 2:
            pop(&S);
            break;

        case 3:
            printf("The Stack is : \n");
            display(&S);
            break;
        case 4:
            printf("Enter the NEW Array Length : \n");
            scanf("%d",&n);
            break;
        default:
            break;
        }
    }
    return 0;
}
