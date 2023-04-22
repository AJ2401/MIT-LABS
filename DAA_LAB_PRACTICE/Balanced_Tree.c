#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*left;
     struct node*right;
};
void Create(struct node*root,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->left=NULL;
     temp->right=NULL;
     int opt;
     printf("Choose your Option \n1)Left\n2)Right\n3)Left_Root_Right\n4)Right_Root_Left\n");
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
     static int h1=0;
     if(root->left==NULL)
     {
          return(h1);
     }
     height1(root->left);
     h1++;
}
int height2(struct node*root)
{
     static int h2=0;
     if(root->right==NULL)
     {
          return(h2);
     }
     height2(root->right);
     h2++;
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
    inorder(root=root->right);
}
void  postorder(struct node*root)
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
     struct node*root=(struct node*)malloc(sizeof(struct node));
     int item,n;
     printf("Enter the Number : \n");
     scanf("%d",&item);
     root->data=item;
     root->left=NULL;
     root->right=NULL;
     printf("Enter the number of Iterations : ");
     scanf("%d",&n);
     while(n>0)
     {
          printf("Enter the Number : ");
          scanf("%d",&item);
          Create(root,item);
          n--;
     }
     printf("\nThe Preorder Traversal is : \n");
     preorder(root);
     printf("\nThe Inorder Traversal is : \n");
     inorder(root);
     printf("\nThe Postorder Traversal is : \n");
     postorder(root);
     int h1=height1(root);
     int h2=height2(root);
     int diff;
     if(h1>h2)
     {
          diff=h1-h2;
     }
     else
     {
          diff=h2-h1;
     }
     if(diff<=1)
     {
          printf("The Tree is Balanced Tree !! ");
     }
     else
     {
          printf("The Tree is Not Balanced Tree !! ");
     }
}