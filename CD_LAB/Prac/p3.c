#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define max 10200

int main()
{
	FILE *f1,*f2;
	char buff[max],filename[25],c;

	printf("Enter the filename : \n");
	scanf("%s",filename);
	f1=fopen(filename,"r");

	printf("Enter the filename : \n");
	scanf("%s",filename);
	f2=fopen(filename,"w+");

	c=fgetc(f1);
	int i=0,j=0,k=0;
	while(c!=EOF)
	{
		if(c=='\n')
		{
			j++;
		}
		if(c== ' ')
		{
			k++;
		}
		buff[i++]=c;
		fputc(c,f2);
		c=fgetc(f1);
	}
	printf("\n----------------------------------------------Contents is being transferred !-----------------------------------------\n");
	printf("\n%s\n",buff);
	printf("\n---------------------------------------------- Details of FILE %s -----------------------------------------\n",filename);
	printf("\nThe Size of the File is : %d \n",i);
	printf("\nThe lines in the File is : %d \n",j);
	printf("\nNumber of Words are : %d\n",k);
	printf("\n\n");
}