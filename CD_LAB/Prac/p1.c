#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define max 10020

int main()
{
	FILE *f1,*f2;
	char buff[max],c,filename[25];

	printf("Enter the filename :\n");
	scanf("%s",filename);
	f1=fopen(filename,"r");

	printf("Enter the filename :\n");
	scanf("%s",filename);
	f2=fopen(filename,"w+");

	c=fgetc(f1);
	int i=0;
	while(c!=EOF)
	{
		buff[i++]=c;
		fputc(c,f2);
		c=fgetc(f1);
	}
	printf("The Contents is being Transfered : \n");
	printf("\n-----------------------------------------------------------\n");
	printf("\n%s\n",buff);
}