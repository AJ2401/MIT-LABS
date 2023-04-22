#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse(string str,int end,int start)
{
     static char*arr;
     static int i=0;
     if(start==end)
     {
          printf("The Reversed String is :  %s ",arr);
          return;
     }
       i++;
    arr[i]=str[end];
  reverse(str,end-1,start);
}
void main()
{
     //char*string;
     string s;
     printf("Enter the String : \n");
     scanf("%s",&s);
     int i=s.lenght();
     /*while(string[i]!='\0')
     {
          i++;
     }*/
     printf("The String is : %s\n",s);
     reverse(s,i,0);
}