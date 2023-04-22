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
      temp->link=NULL;
      temp->data=item;
     if(*head==NULL)
     {
          *head=temp;
     }
     else
     {
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
     struct node*t=head;
     int c=0;
     while(t!=NULL)
     {
          printf("%d  ->  ",t->data);
          c++;
          t=t->link;
     }
     printf("\nThe Number of Nodes are %d ",c);
}
struct node*reverse(struct node**head,int k)
{
     struct node*pre=NULL;
     struct node*current=*head;
     struct node*next;
     struct node*temp=*head;
     int count=0;
     while(current!=NULL &&  count!=k)
     {
          next=current->link;
          current->link=pre;

          pre=current;
          current=next;
          count++;
     }
     if(next!=NULL){
     temp->link=reverse(&next,k);
     }
     return(pre);
}
void main()
{
     struct node*head=NULL;
     struct node*rev_head;
     int opt,item,k,n=1;
     while(n>0)
     {
          printf("Choose your option\n1)ADD \n2)Display\n3)Revers Till K Nodes\n");
         scanf("%d",&opt);
          switch(opt){
          case 1:
          printf("Enter the Number  : \n");
          scanf("%d",&item);
          append(&head,item);
          break;
          case 2:
          printf("The Linked List is  : \n");
          display(head);
          break;
          case 3:
          printf("Enter the Number of Nodes to Reversed : \n");
          scanf("%d",&k);
          rev_head=reverse(&head,k);
          printf("The Revesed Linked List is : \n");
          display(rev_head);
          break;
          default:
          break;
     }
     }
}