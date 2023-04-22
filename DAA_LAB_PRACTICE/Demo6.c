//Even After Odd
#include<stdio.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node*link;
};
void append(struct node**head,int val)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node*));
     temp->data=val;
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
     int c=1;
     struct node*t=head;
     while(t!=NULL)
     {
          printf("  %d -> ",t->data);
          t=t->link;
          c++;
     }
     printf("\nNumber of nodes are  : %d ",c);
}
struct node*convert(struct node**head)
{
     /*struct node*d=(struct node*)malloc(sizeof(struct node));
     d->data=-1;
     d->link;
     d=d->link;
     struct node*d_h=(struct node*)malloc(sizeof(struct node));
     d_h->data=-1;
     d_h->link=NULL;
     d_h=d_h->link;*/
     struct node*dummy;
     struct node*dummy_head;
     struct node*t=*head;
     int c=0;
     while(t->link!=NULL)
     {
          if(c%2!=0)
          {
               dummy_head->link=t;
               dummy_head=dummy_head->link;
          }
          else if(c%2==0)
          {
               dummy->link=t;
               dummy=dummy->link;
          }
          c++;
          t=t->link;
     }
    struct node*d1=dummy_head;
     while(dummy_head->link!=NULL)
     {
          dummy_head=dummy_head->link;
     }
     dummy_head->link=dummy;
     return(d1);
}
void main()
{
     struct node*head=NULL;
     int val,n;
     printf("Enter the Number of Nodes : \n");
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
          printf("Node %d : \n",i+1);
          scanf("%d",&val);
          append(&head,val);
     }    
     printf("\nThe Linked List \n");
     display(head);
     struct node*head1=convert(&head);
     display(head1);
}