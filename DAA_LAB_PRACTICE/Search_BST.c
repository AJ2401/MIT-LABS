#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*left;
     struct node*right;
};
struct node*BST(struct node*root,int item)
{
     if(root==NULL)
     {
          struct node*temp=(struct node*)malloc(sizeof(struct node));
          temp->data=item;
          temp->left=NULL;
          temp->right=NULL;
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
int Search(struct node*root,int item)
{
     if(root->data==item)
     {
          return(1);
     }
     int res=Search(root->left,item);
     res=Search(root->right,item);
     return(0);
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
void preorder(struct node*root)
{
     if(root==NULL)
     {
          return;
     }
     preorder(root->left);
     printf("  %d  ",root->data);
     preorder(root->right);
}
void main()
{
     struct node*root=NULL;
     int size;
     printf("Enter the Size : \n");
     scanf("%d",&size);
     int arr[size];
     printf("Enter the Elements : \n");
     for(int i=0;i<size;i++)
     {
          scanf("%d",&arr[i]);
     }
     for(int i=0;i<size;i++)
     {
         root=BST(root,arr[i]);
     }
     printf("\nThe Preorder of the Tree is : \n");
     preorder(root);
     printf("\nThe Inorder of the Tree is  : \n");
     inorder(root);
     int item;
     printf("\nEnter the Number : \n");
     scanf("%d",&item);
     int res=Search(root,item);
     if(res==1){
     printf("\nThe %d Element is Present in the Tree !! \n",item);
}
else
{
     printf("\nThe %d element is Not present in the Tree !! \n",item);
} 
