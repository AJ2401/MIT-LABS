#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*left;
     struct node*right;
};
int max;
struct node*Create(int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->left=NULL;
     temp->right=NULL;
     return(temp);
}
int search(int inorder[max],int item, int start,int end)
{
     for(int i=start;i<=end;i++)
     {
          if(inorder[i]==item)
          {
               return(i);
          }
     }
     return(-1);

}
struct node*Build_Tree(int postorder[max],int inorder[max],int start,int end)
{
      static int idx=6;
      if(start>end)
      {
           return(NULL);
      }
      int current =postorder[idx];
       idx--;
      struct node*root=Create(current);
      int pos=search(inorder,current,start,end);
      if(start==end)
      {
           return(root);
      }
      root->right=Build_Tree(postorder,inorder,pos+1,end);
      root->left=Build_Tree(postorder,inorder,start,pos-1);
}
void postorder_dis(struct node*root)
{
     if(root==NULL)
     {
          return;
     }
     postorder_dis(root->left);
     postorder_dis(root->right);
     printf("  %d  ",root->data);
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
     printf("  %d  ",root->data);
     inorder_dis(root->right);
}
void main()
{
     int inorder[]={4,2,5,1,6,3,7};
     int postorder[]={4,5,2,6,7,3,1};
     max=7;
     struct node*root=Build_Tree(postorder,inorder,0,6);
     printf("\nThe Inorder Traversal is : \n");
     inorder_dis(root);
     printf("\nThe Preorder Traversal is : \n");
     preorder_dis(root);
     printf("\nThe Postorder Traversal is : \n");
     postorder_dis(root);
}