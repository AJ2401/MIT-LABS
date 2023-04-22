#include<stdio.h>
#include<string.h>
int main()
{
     printf("\nADITYA_PANDEY(200953098)\n");
    char Names[10][10],X[20];
    int n;
    printf("\nEnter the Number of Names to be Entered :\n");
    scanf("%d",&n);
    printf("\nEnter the Names:\n");
    for(int i=0;i<n;i++)
    {
     scanf("%s",&Names[i]);
    }
   printf("\nThe Entered Names are :\n");
    for(int i=0;i<n;i++)
    {
     printf(" %s , ",Names[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(Names[i],Names[j])>0)
            {
                strcpy(X,Names[i]);
                strcpy(Names[i],Names[j]);
                strcpy(Names[j],X);
            }
        }
    }
    printf("\nThe Ordered Names are :\n");
    for(int i=0;i<n;i++)
    {
     printf(" %s , ",Names[i]);
    }


}
