#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*left;
     struct node*right;
};
struct node*Create(struct node*root,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->left=NULL;
     temp->right=NULL;
     int opt;
     printf("Choose your Option \n1)Left \n2)Right\n3)Left_Root_Right\n4)Right_Root_Left\n");
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
int height1(struct node*root)
{
      static int h=0;
     if(root==NULL)
     {
          return(h);
     }
     height1(root->left);
     h++;
}
int height2(struct node*root)
{
     static int h1=0;
     if(root==NULL)
     {
          return(h1);
     }
     height2(root->right);
     h1++;
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
void main()
{
     struct node*root;
     int item,n;
     printf("Enter the Number : ");
     scanf("%d",&item);
     root->data=item;
     root->right=NULL;
     root->left=NULL;
     printf("Enter the Number of Iterations : ");
     scanf("%d",&n);
     while(n>0)
     {
          printf("Enter the Number : ");
          scanf("%d",&item);
          Create(root,item);
          n--;
     }
     printf("\nThe Preorder Traversal is : ");
     preorder(root);
     printf("\nThe Inorder Traversal is : ");
     inorder(root);
     printf("\nThe Postorder Traversal is : ");
     postorder(root);
     int h=height1(root);
     int h1=height2(root);
     if(h>h1){
     printf("The Height of the Tree is : %d",h);
     }
     if(h1>h)
     {
          printf("The Height of the Tree is %d ",h1);
     }
}