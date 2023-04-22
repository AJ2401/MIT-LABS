#include<stdio.h>
#define max 25
int arr[max];
int top1= -1;
int top2=max;

void push1(int item);
void pop1(int n2);
void push2(int item1);
void pop2(int n2,int n3);

int main()
{
    printf("\nABHISHEK JHAWAR 200905144 \n");
    int ar[max];
    int n1,n2,i;
    printf("\n Enter  the number of Elements in Stack 1 \n");
    scanf("%d",&n1);
    printf("\n Enter the number of  Elements in Stack 2 \n");
    scanf("%d",&n2);
    for( i=0; i< n1;i++)
    {
        push1(i);
        printf("%d is pushed in Stack 1 \n",i);
    }
    int n3=n1+n2;
    for(i=n1; i<=n3; i++)
    {
        push2(i);
        printf("%d is pushed in Stack 2\n",i);
    }

    n3=n3+1;
    while(n3>n2)
    {
        pop2(n2,n3);
        --n3;
    }
    while(n2)
    {
        pop1(n2);
        --n2;
    }
    return(0);
}
void push1(int item)
{
    if(top1+1 < top2-1)
    {
        top1++;
        arr[top1]=item;
    }
    else
    {
        printf("\n Stack1 is Full ");
    }
}
void push2(int item)
{
    if(top1+1 < top2-1)
    {
        top2++;
        arr[top2]=item;
    }
    else
    {
        printf("\n Stack2 is Full ");
    }
}
void pop1(int n2)
{
    top1=n2;
    if(top1>=0)
    {
        int data;
        data=arr[top1+1];
        --top1;
        printf("\n %d element is Poped from Stack  \n",data);
    }
    else
    {
        printf("Stack 1 is Empty\n");
    }
}
void pop2(int n2,int n3)
{
    top2=(n3-1);
    if(top2>=n2)
    {
        int data;
        data=arr[top2-1];
         --top2;
        printf("\n %d element is Poped from Stack  \n",data);
    }
    else
    {
        printf("Stack 2 is Empty\n");
    }
}
