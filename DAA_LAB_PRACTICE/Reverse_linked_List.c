#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*link;
};
void append(struct node**head,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->link=NULL;
     if(*head==NULL)
     {
          *head=temp;
     }
     else{
          struct node*t=*head;
          while(t->link!=NULL)
          {
               t=t->link;
          }
          t->link=temp;
     }
}
void display(struct node*head)
{
     int c=0;
     struct node*t=head;
     while(t!=NULL)
     {
         printf("%d  ->  ",t->data);
          t=t->link;
          c++;
     }
     printf("\nNumber of Nodes are %d\n",c);
}
struct node*reverse(struct node**head)
{
     struct node*pre=NULL;
     struct node*current=*head;
     struct node*next;
     while(current!=NULL)
     {
          next=current->link;
          current->link=pre;

          pre=current;
          current=next;
     }
     return(pre);
}
void main()
{
     struct node*head=NULL;
     struct node*rev_head;
     int opt,item,n=2;
     while(n>0){
     printf("Choose your option \n1)ADD \n2)Display\n3)Reverse The Linked List \n");
     scanf("%d",&opt);
     switch(opt)
     {
          case 1:
          printf("Enter the Number : \n");
          scanf("%d",&item);
          append(&head,item);
          break;
          case 2:
          printf("The Linked List is : \n");
          display(head);
          break;
          case 3:
          rev_head=reverse(&head);
          printf("The Reversed Linked List is : \n");
          display(rev_head);
          break;
          default:
          break;
     }
     }
}