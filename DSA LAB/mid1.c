#include<stdio.h>
#include<stdlib.h>
struct stack
{
    char data;
    struct stack* link;
};
void push(struct stack** S,char c)
{
    struct stack*temp;
    temp=(char)malloc(sizeof(char));
    if(temp==NULL)
    {
        printf("Stack is Full");
    }
    else
    {
        temp->data=c;
        temp->link=*S;
        *S=temp;
    }
}
char pop(struct stack**S)
{
    struct stack*temp;
    char item;
    if(*S==NULL)
    {
        printf("The Stack is Empty");
    }
    else
    {
        temp=*S;
        item=temp->data;
        *S=(*S)->link;
        free(temp);
        return(item);
    }
}
int main()
{
    struct stack* S=NULL;
    char c;
    char sen;
    int count=0;
    printf("Enter the String:");
    while(sen)
    {
        sen=(char)malloc(sizeof(char));
        scanf("%c",&sen);
        push(&S,sen);
        count++;
    }
    for(int i=0;i<count;i++)
    {
        c=pop(&S);
        printf("%c",c);
    }

}
