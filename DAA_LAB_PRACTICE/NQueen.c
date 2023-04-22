#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define true 1
#define false 0
int size;
bool Safe(int arr[size][size],int row,int col)
{
    for(int i=0;i<row;i++)
    { 
     if(arr[i][col]==1)
     {
          return(false);
     }
    }
    int r,c;
    r=row;
    c=col;
    while(r>=0 && c>=0)
    {
         if(arr[r][c]==1)
         {
              return(false);
         }
          r--;
          c--;
    }
    r=row;
    c=col;
    while(r>=0 && c<size)
    {
         if(arr[r][c]==1)
         {
         return(false);
         }
         c++;r--;
    }
    return(true);
}
bool Queen(int arr[size][size],int row)
{
     if(row>=size)
     {
          return(true);
     }
     for(int i=0;i<size;i++)
     {
          if(Safe(arr,row,i)==true)
          {
               arr[row][i]=1;
               if(Queen(arr,row+1)==true)
               {
                    return(true);
               }
                arr[row][i]=0;
          }
     }
     return(false);
}
void display(int arr[size][size])
{
     for(int i=0;i<size;i++)
     {
          for(int j=0;j<size;j++)
          {
               printf("  %d  ",arr[i][j]);
          }
          printf("\n");
     }
}
void main()
{
     printf("Enter the Size of the Array : \n");
     scanf("%d",&size);
     int arr[size][size];
     for(int i=0;i<size;i++)
     {
          for(int j=0;j<size;j++)
          {
               arr[i][j]=0;
          }
     }
     bool res=Queen(arr,0);
     if(res==true)
     {
          printf("The Resulant Combinations is : \n");
          display(arr);
     }
   if(res==false)
     {
          printf("No Combinations of Queens Can be Made !! \n");
     }
}