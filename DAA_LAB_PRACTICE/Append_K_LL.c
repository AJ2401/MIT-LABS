//Logical Errror ....Do it Afterwards
#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*left;
     struct node*right;
};
void append(struct node**head,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->left=NULL;
     temp->data=item;
     temp->right=NULL;
     if(*head==NULL)
     {
          *head=temp;
     }
     else
     {
          struct node*t=*head;
          while(t->right!=NULL)
          {
               t=t->right;
          }
          t->right=temp;
          temp->left=t;
     }
}
void display(struct node*head)
{
     int c=0;
     struct node*t=head;
     while(t->right!=NULL)
     {
          printf(" <- %d -> ",t->data);
          t=t->right;
          c++;
     }
     printf("Number of Nodes are %d ",c);
}
void Append_K_nodes(struct node**head,int k)
{
     int count=0;
     struct node*t=*head;
     struct node*t1=*head;
     struct node*t2=*head;
     while(t->right!=NULL)
     {
          t=t->right;
          count++;
     }
     int pos=count-k+1;
     int c=0;
     while(t2->right!=NULL && c<=pos)
     {
          t2=t2->right;
          c++;
     }
     struct node*temp=t2->right;
     temp->left=NULL;
     t2->right=NULL;
     t1->left=t;
     t->right=t1;
     *head=t1;
}
void main()
{
     struct node*head=NULL;
     int k,item,opt,n=1;
     while(n>0)
     {
          printf("Choose your option \n1)ADD \n2)Display\n3)Reverse K Nodes\n");
          scanf("%d",&opt);
          switch(opt)
          {
               case 1:
               printf("Enter the Number : ");
               scanf("%d",&item);
               append(&head,item);
               break;
               case 2:
               printf("The Linked List is : ");
               display(head);
               break;
               case 3:
               printf("Enter the Value of K : ");
               scanf("%d",&k);
               Append_K_nodes(&head,k);
               printf("After Appending %d nodes from the Linked List .... The Linked List is : ");
               display(head);
               break;
               default:
               break;
          }
     }
} 