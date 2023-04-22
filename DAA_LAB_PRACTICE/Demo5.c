// Merge two sorted array
#include <stdio.h>
#include <stdlib.h>

struct node
{
     struct node *link;
     int data;
};
void append(struct node **head, int val)
{
     struct node *temp = (struct node *)malloc(sizeof(struct node));
     temp->data = val;
     temp->link = NULL;

     if (*head == NULL)
     {
          *head = temp;
     }
     else
     {
          struct node *t = *head;
          while (t->link != NULL)
          {
               t = t->link;
          }
          t->link = temp;
     }
}
void display(struct node *head)
{
     struct node *t = head;
     int c = 0;
     while (t!= NULL)
     {
          printf("%d - > ", t->data);
          t = t->link;
          c++;
     }
     printf("\nThe Number of Nodes are %d \n", c);
}
struct node *Merge(struct node *head1, struct node *head2)
{
     struct node *t1 = head1;
     struct node *t2 = head2;
     struct node*d=(struct node*)malloc(sizeof(struct node));
     d->data=-1;
     d->link=NULL;
     struct node *dummy=d;
     while (t1!= NULL && t2!= NULL)
     {
          if (t1->data > t2->data)
          {
               dummy->link = t2;
               t2 = t2->link;
          }
          else
          {
               dummy->link = t1;
               t1 = t1->link;
          }
          dummy = dummy->link;
     }
     while(t1!=NULL)
     {
               dummy->link = t1;
               t1 = t1->link;
               dummy = dummy->link;
     }

     while(t2!=NULL)
     {
               dummy->link = t2;
               t2 = t2->link;
               dummy = dummy->link;
     }

     return (d->link);
}
void main()
{
     int opt1, opt, val, c, n = 1;
     struct node *head1 = NULL;
     struct node *head2 = NULL;
     struct node *head = NULL;
     while (n > 0)
     {
          printf("Choose your option \n1)First Linked List\n2)Second Linked List\n3)Merge two sorted Linked list :\n");
          scanf("%d", &opt);
          switch (opt)
          {
          case 1:
               printf("Choose your option \n1)Append\n2)Display\n\n");
               scanf("%d", &opt1);
               switch (opt1)
               {
               case 1:
                    printf("Enter the Value : \n");
                    scanf("%d", &val);
                    append(&head1, val);
                    break;
                    ;
               case 2:
                    printf("First Linked List is : \n");
                    display(head1);
                    break;
               }
               break;

          case 2:
               printf("Choose your option \n1)Append\n2)Display\n\n");
               scanf("%d", &opt1);
               switch (opt1)
               {
               case 1:
                    printf("Enter the Value : \n");
                    scanf("%d", &val);
                    append(&head2, val);
                    break;
               case 2:
                    printf("Second Linked List is : \n");
                    display(head2);
                    break;
               }
               break;
          case 3:
               printf("Merging two Sorted Linked List ... \n");
               head = Merge(head1, head2);
               display(head);
               break;
          }
     }
}