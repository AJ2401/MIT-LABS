#include<stdio.h>
#include<stdlib.h>
#include"display.c"
int size;
struct node
{
     int data;
     struct node*left;
     struct node*right;
};
struct node*BST(struct node*root,int arr[size],int start)
{
   //  static int i=0;
     if(start==size-1)
     {
          return(root);
     }
     if(root==NULL)
     {
          struct node*temp=(struct node*)malloc(sizeof(struct node));
          temp->data=arr[start];
          temp->left=NULL;
          temp->right=NULL;
          return(temp);
     }
     if(arr[start]>root->data)
     {
          root->right=BST(root->right,arr,start+1);
          // i++;
     }
     else
     {
          root->left=BST(root->left,arr,start+1);
           //i++;
     }
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
void main()
{
     struct node*root;
     printf("Enter the Size of the Array : \n");
     scanf("%d",&size);
     int arr[size];
     printf("Enter the Array Elements of the Array : \n");
     for(int i=0;i<size;i++)
     {
          printf("Element %d  : ",i+1);
          scanf("%d",&arr[i]);
     }
     printf("The Preorder Array is : \n");
     display(arr,size);
     root=BST(root,arr,0);
     printf("The Tree is Build Up  ... So finding Inorder and Postorder \n");
     inorder(root);
     postorder(root);
}
