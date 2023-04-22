#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define true 1
#define false 0
int size;
bool Safe(int arr[size][size],int r,int c)
{
     if(r<size && c<size && arr[r][c]==1)
     {
          return(true);
     }
     else
     {
          return(false);
     }
}
bool rat_maze(int arr[size][size],int r,int c,int sol[size][size])
{
     if(r==size-1 && c==size-1)
     {
          sol[r][c]=1;
          return(true);
     }
     if(Safe(arr,r,c)==true)
     {
          sol[r][c]=1;
          if(rat_maze(arr,r+1,c,sol)==true)
          {
               return(true);
          }
          if(rat_maze(arr,r,c+1,sol)==true)
          {
               return(true);
          }

               sol[r][c]=0;
               return(false);
     }
          return(false);
}
void display(int arr[size][size])
{
     for(int i=0;i<size;i++)
     {
          for(int j=0;j<size;j++)
          {
               printf(" %d ",arr[i][j]);
          }
          printf("\n");
     }
}
void main()
{
     printf("\nEnter the Size of the Matrix : \n");
     scanf("%d",&size);
     int arr[size][size];
     for(int i=0;i<size;i++)
     {
          for(int j=0;j<size;j++)
          {
               printf("\nEnter the Element  Array[%d] [%d] : \n",i+1,j+1);
               scanf("%d",&arr[i][j]);
               /*if(arr[i][j]!=0 || arr[i][j]!=1)
               {
                    scanf("%d",&arr[i][j]);
               }*/
          }
     }
     printf("The Array is : \n");
     display(arr);
     printf("\n\n");
     int sol[size][size];
     for(int i=0;i<size;i++)
     {
          for(int j=0;j<size;j++)
          {
               sol[i][j]=0;
          }
     }
     bool res=rat_maze(arr,0,0,sol);
     if(res==true)
     {
          printf("\nThe Solution Matrix is : \n\n");
          display(sol);
     }
     if(res==false)
     {
          printf("\nThe Maze Couldn't Find the Root : \n");
     }
}