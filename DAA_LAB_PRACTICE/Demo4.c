// Intersection of Two linked list
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
     while (t != NULL)
     {
          printf("%d  -> ", t->data);
          c++;
          t = t->link;
     }
     printf("\nNumber of nodes are %d\n", c);
}
int detect(struct node *head1, struct node *head2, int l1, int l2)
{
     int len;
     if (l1 > l2)
     {
          int c = 1;
          struct node *t = head1;
          len = l1 - l2;
          while (t->link != NULL && c < len)
          {
               t = t->link;
          }
          head1 = t;
     }
     else
     {
          len = l2 - l1;
          int c = 1;
          struct node *t = head2;
          while (t->link != NULL && c < len)
          {
               t = t->link;
          }
          head2 = t;
     }
     int c = 1;
     struct node *t1 = head1;
     struct node *t2 = head2;
     while (t1->link != NULL && t2->link != NULL)
     {
          if (t1 == t2)
          {
               return (c);
          }
          c++;
          t1 = t1->link;
          t2 = t2->link;
     }
     return (0);
}
int len(struct node *head)
{
     int c = 1;
     struct node *t = head;
     while (t != NULL)
     {
          c++;
          t = t->link;
     }
     return (c);
}
void main()
{
     struct node *head1 = NULL;
     struct node *head2 = NULL;
     struct node *t1 = head1;
     struct node *t2 = head2;
     int n = 1;
     int opt, opt1, val, l1, l2, d, pos, c = 1;
     while (n > 0)
     {
          printf("Choose your Linked List \n1)First Linked List \n2)Second Linked List\n3)Intersection Point\n");
          scanf("%d", &opt);
          switch (opt)
          {
          case 1:
               printf("Choose your option : \n1)Append \n2)Display\n3)Length of Linked list\n");
               scanf("%d", &opt1);
               switch (opt1)
               {
               case 1:
                    printf("\nEnter the Value : \n");
                    scanf("%d", &val);
                    append(&head1, val);
                    break;
               case 2:
                    printf("\nThe First Linked List is : \n\n");
                    display(head1);
                    break;
               case 3:
                    l1 = len(head1);
                    printf("\nThe Lenght of the first Linked List is : %d\n");
                    break;
               }
               break;
          case 2:
               printf("Choose your option : \n1)Append \n2)Display\n3)Length of Linked list\n");
               scanf("%d", &opt1);
               switch (opt1)
               {
               case 1:
                    printf("\nEnter the Value : \n");
                    scanf("%d", &val);
                    append(&head2, val);
                    break;
               case 2:
                    printf("\nThe Second Linked List is : \n\n");
                    display(head2);
                    break;
               case 3:
                    l1 = len(head2);
                    printf("\nThe Lenght of the Second Linked List is : %d\n");
                    break;
               }
               break;
          case 3:
               printf("Choose your option : \n1)Create Intersection point \n2)Detect Intersection \n");
               scanf("%d", &opt1);
               switch (opt1)
               {
               case 1:
                    printf("Enter the Position : \n");
                    scanf("%d", &pos);
                    while (t2->link != NULL)
                    {
                         t2 = t2->link;
                    }
                    while (t1->link != NULL)
                    {
                         if (c == pos)
                         {
                              t2->link = t1;
                         }
                         c++;
                         t1 = t1->link;
                    }
                    break;
               case 2:
                    l1 = len(head1);
                    l2 = len(head2);
                    d = detect(head1, head2, l1, l2);
                    if (d > 0)
                    {
                         printf("The Two linked List are Intersecting at %d point \n", d);
                    }
                    else if (d == 0)
                    {
                         printf("The Two Linked List are Not Intersecting \n\n");
                    }
                    break;
               }
               break;
          }
     }
}