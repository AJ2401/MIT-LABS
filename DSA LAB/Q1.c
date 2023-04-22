#include<stdio.h>
#include<stdlib.h>
struct node
{
char data;
struct node*link;
};
void append(struct node**head,char item)
{
   struct node*temp=(struct node*)malloc(sizeof(struct node));
   temp->data=item;
   temp->link=*head;
   if(*head==NULL)
   {
      *head=temp;
     // temp->link=*head;
   }
   else
   {
      struct node*t=*head;
      while(t->link!=*head)
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
   while(t->link!=head)
   {
      printf("%s -> ",t->data);
      t=t->link;
      c++;
   }
   printf("\nNumber of Nodes are %d\n",c);
}
void merge(struct node**head1,struct node**head2)
{

}
void  main()
{
   struct node*head1=NULL;
   struct node*head2=NULL;
   int n=1,opt,o,o1;
   char ele1,ele2;
   while(n>0)
   {
      printf("Choose your Option : \n1)Add Element  \n2)Display \n3)Merge \n");
      scanf("%d",&opt);
      switch (opt)
      {
      case 1:
      printf("Choose your List :\n1) List 1 \nOR\n2)List 2\n");
      scanf("%d",&o);
      switch (o)
      {
      case 1:
      printf("Enter the Element : \n");
      scanf("%s",&ele1);
      append(&head1,ele1);
         break;
      case 2: 
      printf("Enter the Element : \n");
      scanf("%s",&ele2);
      append(&head2,ele2);
         break;
      default:
         break;
      }
         break;
      case 2:
      printf("Choose your List :\n1) List 1 \nOR\n2)List 2\n");
      scanf("%d",&o1);
      switch (o1)
      {
      case 1:
      printf("The Linked List 1 is  :\n");
      display(head1);
         break;
      case 2 : 
      printf("The Linked List 2 is :\n");
      display(head2);
         break;
      default:
         break;
      }
         break;
      case 3:
      printf("Merging the Two Lists : \n");
      merge(&head1,&head2);
      display(head1);
      break;
      default:
         break;
      }
   }
}