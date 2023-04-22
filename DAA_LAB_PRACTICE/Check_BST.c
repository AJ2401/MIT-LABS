#include<stdio.h>
#include<stdlib.h>
struct node
{
     struct node*left;
     struct node*right;
     int data;
};
int Check_BST(struct node*root)
{

}
void main()
{
     int n;
     printf("Enter the Number of Iterations : \n");
     scanf("%d",&n);
     int arr[n],item;
     printf("Enter the Root data : \n");
     scanf("%d",&item);
     struct node*root;
     root->data=item;
     root->left=NULL;
     root->right=NULL;
     for(int i=0;i<n;i++)
     {
          printf("Node %d ",i+1);
          scanf("%d",&item);
     }
     

 }