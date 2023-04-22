#include <stdio.h>
#include <stdlib.h>
char *arr;
int max;
int top = -1;

void push(char val)
{
     if (top == max)
     {
          printf("Stack is Full \n\n");
          return;
     }
     top++;
     arr[top] = val;
}
char pop()
{
     char val;
     if (top == -1)
     {
          printf("Stack is Empty\n\n");
          return;
     }
     val = arr[top];
     top--;
     return (val);
}
void display()
{
     for (int i = 0; i < max; i++)
     {
          printf("  %c  ", arr[i]);
     }
}
int main()
{
     char *arr = (char *)malloc(max * sizeof(char));
     char*array;
     printf("Enter the Sentence : \n\n");
     scanf("%s",&array);
     max = sizeof(array) / sizeof(char);
     printf("The size of the Sentence is %d \n", max);
     for (int i = 0; i < max; i++)
     {
           printf("The Entered Input is : %c\n", array[i]);
           push(array[i]);
     }
     printf("The Reversed Sentence is : \t");
     display();
}