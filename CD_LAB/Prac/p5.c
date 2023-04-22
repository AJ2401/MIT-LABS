#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define max 10200

int main()
{
	FILE *f1,*f2;
	char buff[max],filename[25],c,c1;

	printf("Enter the filename : \n");
	scanf("%s",filename);
	f1=fopen(filename,"r");

	printf("Enter the filename : \n");
	scanf("%s",filename);
	f2=fopen(filename,"w+");

	c=fgetc(f1);
	int i=0;
	while(c!=EOF)
	{
		if(c==' ')
		{
			buff[i++]=c;
			fputc(c,f2);
			c=fgetc(f1);
			while(c==' ' && c=='\t')
			{
				c=fgetc(f1);
			}
		}
		buff[i++]=c;
		fputc(c,f2);
		c=fgetc(f1);
	}
	printf("Contents is being Modified !!\n");
	printf("\n---------------------------------------------------------------\n");
	printf("\n%s\n",buff);
}