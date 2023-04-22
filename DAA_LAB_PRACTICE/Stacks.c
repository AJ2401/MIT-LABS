#include<stdio.h>
#include<stdlib.h>
int*Stack;
int max;
int top=-1;
void push(int item)
{
     if(top==max)
     {
          printf("OverFlow Condition !! ");
          return;
     }
     else{
          top++;
          Stack[top]=item;
     }
}
int pop()
{
     if(top==-1)
     {
          printf("UnderFlow Condition !! ");
          return;
     }
     else{
          int item=Stack[top];
          top--;
          return(item);
     }
}
void peek()
{
     printf("%d is the Peek Element !! ",Stack[top]);
}
void display()
{
     for(int i=0;i<max;i++)
     {
          printf("|\t%d\t|",Stack[i]);
     }
}
void main()
{
     int op,ele;
     printf("Enter the Size of the Array : \n");
     scanf("%d",&max);
     Stack=calloc(max,sizeof(int));     
     printf("Choice the Option \n1)Push\n2)Pop\n3)Peek\n4)Display\n");
     scanf("%d",&op);
     switch(op)
     {
          case 1:
          printf("Enter the Element : \n");
          scanf("%d",&ele);
          push(ele);
          break;
          case 2:
          pop();
          break;
          case 3:
          peek();
          break;
          case 4:
          printf("The Stack is : \n");
          display();
          break;
     }
}