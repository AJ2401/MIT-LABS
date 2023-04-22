// Cycle Detection in LL
#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *link;
};
struct node *append(struct node *head, int item)
{
     struct node *temp = (struct node *)malloc(sizeof(struct node));
     temp->data = item;
     temp->link = NULL;

     if (head == NULL)
     {
          head = temp;
     }
     else
     {
          struct node *t = head;
          while (t->link != NULL)
          {
               t = t->link;
          }
          t->link = temp;
     }
     return (head);
}
void display(struct node *head)
{
     struct node *t = head;
     printf("\nThe Linked List is : \n");
     int c = 0;
     while (t != NULL)
     {
          printf(" %d -> ", t->data);
          t = t->link;
          c++;
     }
     printf("\nNumber of Nodes : %d \n", c);
}
void makecycle(struct node *head, int pos)
{
     struct node *start;
     struct node *t = head;
     int c = 1;
     while (t->link!= NULL)
     {
          if (c == pos)
          {
               start = t;
          }
          c++;
          t = t->link;
     }
     t->link = start;
}
int cycle_detection(struct node *head)
{
     struct node *fast = head;
     struct node *slow = head;

     while (fast!= NULL && fast->link != NULL)
     {
          slow = slow->link;
          fast = fast->link->link;

          if (fast == slow)
          {
               return (1);
          }
     }
     return (0);
}
int main()
{
     struct node *head = NULL;

     int opt, n, val, check, pos;
     n = 1;
     while (n > 0)
     {
          printf("Choose your option : \n1)Append\n2)Display\n3)Make_Cycle\n4)Detect Cycle\n5)EXIT\n\n");
          scanf("%d", &opt);
          switch (opt)
          {
          case 1:
               printf("Enter the  Data : \n");
               scanf("%d", &val);
               head = append(head, val);
               break;
          case 2:
               display(head);
               break;
          case 3:
               printf("Enter the Position for Cycle : \n");
               scanf("%d", &pos);
               makecycle(head, pos);
               break;
          case 4:
               check = cycle_detection(head);
               if (check == 1)
               {
                    printf("\nCycle Detected !! \n\n");
               }
               else if (check == 0)
               {
                    printf("\nCycle Not Found \n\n");
               }
               break;
          case 5:
               n = 0;
               break;
          }
     }
}