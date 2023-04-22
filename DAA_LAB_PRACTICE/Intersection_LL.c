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
     int c=0;
     struct node*t=head;
     while(t!=NULL)
     {
          printf("%d  ->  ",t->data);
          t=t->link;
          c++;
     }
     printf("The Number of nodes are %d",c);
}
int length(struct node*head)
{
     int c=0;
     struct node*t=head;
     while(t->link!=NULL)
     {
          t=t->link;
          c++;
     }
     return(c);
}
void Create_inter(struct node**head1,struct node**head2,int item)
{
     struct node*h1=*head1;
     struct node*h2=*head2;
     while(h1->link!=NULL && h1->data!=item)
     {
          h1=h1->link;
     }
     while(h2->link!=NULL)
     {
          h2=h2->link;
     }
     h2->link=h1;
}
int Detect_Inter(struct node**head1,struct node**head2)
{
     int l1=length(head1);
     int l2=length(head2);


}
void main()
{
     struct node*head1=NULL;
     struct node*head2=NULL;
     int op,o,opt,item,n=1,res,ele;
     while(n>0){
          printf("Choose your Linked list : \n1)List 1 \n2)List 2 \n");
          scanf("%d",&o);
          switch (o)
          {
          case 1:
           printf("Choose your Option \n1)Add \n2)Display\n");
           scanf("%d",&opt);
           switch(opt)
           {
                case 1:
                printf("Enter your Number : ");
                scanf("%d",&item);
                append(&head1,item);
                break;
                case 2:
                printf("The Linked List is : ");
                display(head1);
                break;
           }
               break;
          case 2:
          printf("Choose your Option \n1)Add \n2)Display\n");
           scanf("%d",&opt);
           switch(opt)
           {
                case 1:
                printf("Enter your Number : ");
                scanf("%d",&item);
                append(&head2,item);
                break;
                case 2:
                printf("The Linked List is : ");
                display(head2);
                break;
           }
          break;
          default:
               break;
          }
}
while(n>0)
{
     printf("Choose your option\n1)Create Intersection \n2)Detect Intersection \n");
          scanf("%d",&op);
          switch(op)
          {
               case 1:
               printf("Enter the Number : ");
               scanf("%d",ele);
               Create_inter(&head1,&head2,ele);
               break;
               case 2:
               res=Detect_Inter(&head1,&head2);
               if(res==1)
               {
                    printf("Intersection is there Between the List 1 and List 2");
               }
               if(res==0)
               {
                    printf("No Intersection Between the Two Linked List !!");
               }

          }
}
}