#include<stdio.h>
#include<stdlib.h>
struct node
{
     struct node*left;
     struct node*right;
     int data;
};
void Create(struct node*root,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->left=NULL;
     temp->right=NULL;
     int opt;
     printf("Choose your option \n1)Left Side \n2)Right\n3)Left Root _ Right Side\n4)Right Root _ Left Side \n");
     scanf("%d",&opt);
     switch(opt)
     {
          case 1:
          while(root->left!=NULL)
          {
               root=root->left;
          }
          root->left=temp;
          break;
          case 2:
          while(root->right!=NULL)
          {
               root=root->right;
          }
          root->right=temp;
          break;
          case 3:
          root=root->left;
          while(root->right!=NULL)
          {
               root=root->right;
          }
          root->right=temp;
          break;
          case 4:
          root=root->right;
          while(root->left!=NULL)
          {
               root=root->left;
          }
          root->left=temp;
          break;
     }   
}
void preorder(struct node*root)
{
     if(root==NULL)
     {
          return;
     }
     printf("  %d  ",root->data);
     preorder(root->left);
     preorder(root->right);
}
void inorder(struct node*root)
{
     if(root==NULL)
     {
          return;
     }
     inorder(root->left);
     printf("  %d  ",root->data);
     inorder(root->right);
}
void postorder(struct node*root)
{
     if(root==NULL)
     {
          return;
     }
     postorder(root->left);
     postorder(root->right);
     printf("  %d  ",root->data);
}
int sum(struct node*root)
{
     static int Sum=0;
     if(root==NULL)
     {
          return(Sum);
     }
    sum(root->right);
    sum(root->left);
    Sum=Sum+root->data;
}
void main()
{
     int item,n;
     struct node*root;
     printf("\nEnter the Number : ");
     scanf("%d",&item);
     root->left=NULL;
     root->right=NULL;
     root->data=item;
     printf("\nEnter the Number of Iterations : ");
     scanf("%d",&n);
     while(n>0)
     {
          printf("\nEnter the Number : ");
          scanf("%d",&item);
          Create(root,item);
          n--;
     }
     printf("\nThe Inorder Traversal is : \n");
     inorder(root);
     printf("\nThe Postorder Traversal is :\n");
     postorder(root);
     printf("\nThe PreOrder Traversal is : \n");
     preorder(root);
     int Sum=sum(root);
     printf("\nThe Summation of the Nodes is : %d",Sum);
}