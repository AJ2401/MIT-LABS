#include<stdio.h>
#include<stdlib.h>

struct node
{
     struct node*left;
     struct node*right;
     int data;
};
struct node*BST(struct node*root,int item)
{
     if(root==NULL)
     {
          struct node*temp=(struct node*)malloc(sizeof(struct node));
          temp->data=item;
          temp->right=NULL;
          temp->left=NULL;
          return(temp);
     }
     if(item<root->data)
     {
          root->left=BST(root->left,item);
     }
     else
     {
          root->right=BST(root->right,item);
     }
     return(root);
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
void main()
{
     int size;
     struct node*root=NULL;
     printf("Enter the  Size of the Array : \n");
     scanf("%d",&size);
     int arr[size];
      printf("Enter the Array elements : \n");
      for(int i=0;i<size;i++)
      {
           scanf("%d",&arr[i]);
      }
      for(int i=0;i<size;i++){
          root=BST(root,arr[i]);
      }
      printf("The Preorder of the Tree is : \n");
      preorder(root);
      printf("\nThe Inorder of the Tree is : \n");
      inorder(root);
}