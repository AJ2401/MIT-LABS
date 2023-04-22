#include<stdio.h>
#include<stdlib.h>
#define max 12
struct stack
{
int top;
int a[max];
};
void intial(struct stack* p)
{
p->top = -1;
}
void push(struct stack* p,int item)
{
if(p->top == max)
{
printf("\n The Stack is Full \n");
}
else
{
(p->top)++;
p->a[p->top] = item;
}
}
void display(struct stack* p)
{
for(int i=p->top;i>=0;i--)
{
printf("%d ",p->a[i]);
}
}
int main()
{
printf("\n ABHISHEK JHAWAR(200905144)\n");
struct stack S;
intial(&S);
int i=0,n,arr[max],num;
printf("\n Enter any Number to be Converted in Binary\n");
scanf("%d",&num);
while(num>0)
{
//arr[i++]=num%2;
push(&S,num%2);
num=num/2;
}
/*for(int i=max-1;i>=0;i++)
{
push(&S,arr[i]);
}*/
printf("\n The Binary Number is : \n");
display(&S);
}

