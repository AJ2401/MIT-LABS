#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*right;
     struct node*left;
};
void Create(struct node*root,int item)
{
     int opt;
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->left=NULL;
     temp->right=NULL;
     printf("Choose your option\n1)Left\n2)Right\n3)Left_Root_right\n4)Right_root_Left\n");
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
int count(struct node*root)
{
      static int c=0;
     if(root==NULL)
     {
          return(c);
     }
     count(root->left);
     count(root->right);
     c++;
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
     struct node*root;
     int item,n;
     printf("Enter the Root Node : ");
     scanf("%d",&item);
     root->data=item;
     root->left=NULL;
     root->right=NULL;
     printf("Enter the Number of Nodes : ");
     scanf("%d",&n);
     while(n>0)
     {
          printf("Enter the Root : ");
          scanf("%d",&item);
          Create(root,item);
          n--;
     }
     printf("\nThe Inorder Traversal is : ");
     inorder(root);
     printf("\nThe Postorder Traversal is : ");
     postorder(root);
     printf("\nThe Inorder Traversal is :");
     inorder(root);
     int c=count(root);
     printf("\nThe Number of Nodes are %d ",c);

}