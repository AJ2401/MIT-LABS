#include<stdio.h>
#include<stdlib.h>
int size;
void swap(int arr[size],int p1,int p2)
{
     int temp=arr[p1];
     arr[p1]=arr[p2];
     arr[p2]=temp;
}
void display(int arr[size])
{
     for(int i=0;i<size;i++)
     {
          printf("  %d  ",arr[i]);
     }
     printf("\n");
}
void Bubble_Sort(int arr[size])
{
     for(int i=0;i<size-1;i++)
     {
          for(int j=0;j<size-i-1;j++)
          {
               if(arr[j]>arr[j+1])
               {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
               }
          }
     }
     printf("The Sorted Array using Bubble Sort is : \n");
     display(arr);
}
void Insertion_Sort(int arr[size])
{
     for(int i=1;i<=size-1;i++)
     {
          
     int current=arr[i];
     int j=i-1;
     while(arr[j]>current && j>=0)
     {
          arr[j+1]=arr[j];
          j--;
     }
     arr[j+1]=current;
     }
     printf("The Sorted Array using Insertion Sort is : \n");
     display(arr);
}
void Merge(int arr[size],int l,int m,int u)
{
     int l1=m-l+1;
     int l2=u-m;
     int a1[l1];
     int a2[l2];
     for(int i=0;i<l1;i++)
     {
          a1[i]=arr[l+i];
     }
     for(int i=0;i<l2;i++)
     {
          a2[i]=arr[m+i+1];
     }
     int i=0;
     int j=0;
     int k=l;
     while(i<l1 && j<l2)
     {
          if(a1[i]>a2[j])
          {
               arr[k]=a2[j];
               k++;
               j++;
          }
          else if(a2[j]>a1[i])
          {
               arr[k]=a1[i];
               k++;
               i++;
          }
          else{
               arr[k]=a1[i];
               i++;
               k++;
               j++;
          }
     }
     while(i<l1)
     {
          arr[k]=a1[i];
          i++;
          k++;
     }
     while(j<l2)
     {
          arr[k]=a2[j];
          j++;
          k++;
     }
}
void Merge_Sort(int arr[size],int l,int u)
{
     if(l==(size-1))
     {
          printf("The Sorted Array using Merge Sort is : \n");
          display(arr);
          return;
     }
     if(l<u)
     {
          int mid=(l+u)/2;
          Merge_Sort(arr,l,mid);
          Merge_Sort(arr,mid+1,u);
          Merge(arr,l,mid,u);
     }
}
int max(int arr[size],int k)
{
     for(int i=0;i<size;i++)
     {
          if(k<arr[i])
          {
               k=arr[i];
          }
     }
     return(k);
}
void Count_Sort(int arr[size])
{
     int k=arr[0];
     k=max(arr,k);
     int count[k];
     for(int i=0;i<=k;i++)
     {
          count[i]=0;
     }
     for(int i=0;i<size;i++)
     {
          count[arr[i]]++;
     }
     for(int i=1;i<=k;i++)
     {
          count[i]=count[i]+count[i-1];
     }     
     int sol[size];
     int n=size;
     for(int i=n-1;i>=0;i--)
     {
          sol[count[arr[i]]-1]=arr[i];
          count[arr[i]]--;
     }
     for(int i=0;i<size;i++)
     {
          arr[i]=sol[i];
     }
     printf("The Sorted Array Using Count Sort is : \n");
     display(arr);
}
int min(int arr[size],int l,int k)
{
     for(int i=l;i<size;i++)
     {
          if(arr[k]>arr[i])
          {
               k=i;
          }
     }
     return(k);
}
void Selection_Sort(int arr[size])
{
     for(int i=0;i<size-1;i++)
     {
          int k=arr[i];
          k=min(arr,i+1,k);
          swap(arr,i,k);
     }
     printf("The Sorted Array Using Selection Sort is : \n");
     display(arr);
}
void Wave_Sort(int arr[size])
{
     int n=0;
     while(n<size-1)
     {
          if(arr[n]>arr[n-1])
          {
               swap(arr,n,n-1);
          }
          if(arr[n]>arr[n+1] && n>=size-2)
          {
               swap(arr,n,n+1);
          }
          n=n+2;
     }
     printf("The Sorted Array using Wave_Sort : \n");
     display(arr);
}
void DNF_Sort(int arr[size])
{
     int low=0;
     int high=size-1;
     int mid=0;
     while(mid<=high)
     {
          if(arr[mid]==0)
          {
                mid++;
                low++;
               swap(arr,mid,low);
          }
          if(arr[mid]==1)
          {
               mid++;
          }
          if(arr[high]==2)
          {
               high--;
               swap(arr,high,mid);
          }
     }
     printf("The Sorted Array using DNF Sort is : \n");
     display(arr);
}
int part(int arr[size],int l,int u)
{
     int num=arr[u];
     int j=l-1;
     for(int i=l;i<=u-1;i++){
          if(arr[i]<num)
          {
               j++;
               swap(arr,i,j);
          }
          swap(arr,j+1,u);
     }
     return(j+1);
}
void Quick_Sort(int arr[size],int l,int u)
{
     static int c=0;
      c++;
     if(c==size)
    {
         printf("The Sorted Array using Quick Sort  is : \n");
         display(arr);
         return;
    }
     if(l<u)
     {
          int p=part(arr,l,u);
          Quick_Sort(arr,l,p-1);
          Quick_Sort(arr,p+1,u);
     }
}
void main()
{
     int opt,n;
     printf("Enter the Number of Iterations : \n");
     scanf("%d",&n);
     while(n>0){
     printf("Enter the Size of the Array : \n");
     scanf("%d",&size);
     int arr[size];
     printf("Enter the Array Elements : \n");
     for(int i=0;i<size;i++)
     {
          printf("Enter the Number %d : ",i+1);
          scanf("%d",&arr[i]);
     }
     printf("\n");
     printf("The Array is : \n");
     display(arr);
     printf("--- Sorting The Array using Different Techniques ---- \n\n");
     printf("Choose your Option  : \n1)Bubble Sort \n2)Merge Sort \n3)Quick Sort \n4)Insertion Sort \n5)DNF Sort \n6)Wave Sort \n7)Selection Sort \n8)Count Sort \n\n");
     scanf("%d",&opt);
     switch(opt)
     {
          case 1:
           Bubble_Sort(arr);
           break;
           case 2:
     Merge_Sort(arr,0,size-1);
     break;
     case 3:
     Quick_Sort(arr,0,size-1);
     break;
     case 4:
     Insertion_Sort(arr);
     break;
     case 5:
    DNF_Sort(arr);
    break;
    case 6:
    Wave_Sort(arr);
     break;
     case 7:
     Selection_Sort(arr);
     break;
     case 8:
     Count_Sort(arr);
     break;
     }
     n--;
     }
}