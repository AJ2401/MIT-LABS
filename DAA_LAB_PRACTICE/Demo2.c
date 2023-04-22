// Two Methods are there:
//  1. ARRAY METHOD
//  2. TREE construction Method
#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *right;
     struct node *left;
};
struct node*append(struct node *root, int val)
{
     struct node *temp = (struct node *)malloc(sizeof(struct node));
     temp->data = val;
     temp->left = NULL;
     temp->right = NULL;
     struct node *t = root;
     if (root == NULL)
     {
          root = temp;
            return(root);
     }
     int opt;
     printf("Choose your option : \n1)Right\n2)Left\n3)Right_LeftMost\n4)Left_RightMost\n");
     scanf("%d", &opt);
     switch (opt)
     {
     case 1:
          while (t->right != NULL)
          {
               t = t->right;
          }
          t->right = temp;
          break;
     case 2:
          while (t->left != NULL)
          {
               t = t->left;
          }
          t->left = temp;
          break;
     case 3:
          t = t->right;
          while (t->left != NULL)
          {
               t = t->left;
          }
          t->left = temp;
          break;
     case 4:
          t = t->left;
          while (t->right != NULL)
          {
               t = t->right;
          }
          t->right = temp;
          break;
     }
     return(root);
}
void preorder(struct node *root)
{
     if (root == NULL)
     {
          return;
     }
     printf(" %d ", root->data);
     preorder(root->left);
     preorder(root->right);
}
int Check(struct node *root)
{
     struct node *t = root;
     while (t->left != NULL)
     {
          if (t->data > root->data)
          {
               return (0);
          }
          t=t->left;
     }
     t = root;
     while (t->right != NULL)
     {
          if (root->data < t->data)
          {
               return (0);
          }
          t=t->right;
     }
     return (1);
}
int main()
{
     struct node *root = NULL;
     int n = 1;
     int opt, val, check;
     while (n > 0)
     {
          printf("Choose your option : \n1)Append\n2)Preorder\n3)Check for BST\n4)EXIT\n");
          scanf("%d", &opt);
          switch (opt)
          {
          case 1:
               printf("Enter the Node : \n");
               scanf("%d", &val);
               root=append(root, val);
               break;
          case 2:
               printf("\nThe Preorder of the  Tree is : \n");
               preorder(root);
               break;
          case 3:
               check = Check(root);
               if (check == 1)
               {
                    printf("\nThe Tree is a Binary Search tree \n");
               }
               else if (check == 0)
               {
                    printf("\nThe Tree is not a Binary Search Tree \n");
               }
               break;
          case 4:
               n = 0;
               break;
          }
     }
}
