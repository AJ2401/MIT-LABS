#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*left;
     struct node*right;
};
int max;
struct node*create(int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->left=NULL;
     temp->right=NULL;
     return(temp);
}
int Search(int inorder[max],int ele,int start,int end)
{
     for(int i=start;i<=end;i++)
     {
          if(ele==inorder[i])
          {
               return(i);
          }
     }
     return(-1);
}
struct node*build_Tree(int inorder[max],int preorder[max],int start,int end)
{
     if(start>end)
     {
          return(NULL);
     }
     static int idx=0;
     int current=preorder[idx];
     idx++;
     struct node*root=create(current);
     int pos=Search(inorder,current,start,end);
     if(start==end)
     {
          return(root);
     }
     root->left=build_Tree(inorder,preorder,start,pos-1);
     root->right=build_Tree(inorder,preorder,pos+1,end);
}
void preorder_dis(struct node*root)
{
     if(root==NULL)
     {
          return;
     }
     printf(" %d ",root->data);
     preorder_dis(root->left);
     preorder_dis(root->right);
}
void inorder_dis(struct node*root)
{
     if(root==NULL)
     {
          return;
     }
     inorder_dis(root->left);
     printf(" %d ",root->data);
     inorder_dis(root->right);
}
void postorder(struct node*root)
{
     if(root==NULL)
     {
          return;
     }
     postorder(root->left);
     postorder(root->right);
     printf(" %d ",root->data);
}
void main()
{
     int inorder[]={4,2,5,1,6,3,7};
     int preorder[]={1,2,4,5,3,6,7};
     max=7;
     struct node*root=build_Tree(inorder,preorder,0,6);
     printf("\nThe Preorder of the Tree is : \n");
     preorder_dis(root);
     printf("\nThe Postorder of the Tree is : \n");
     postorder(root);
     printf("\nThe  Inorder of the Tree is : \n");
     inorder_dis(root);
}