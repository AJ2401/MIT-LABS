//Comments and Multiline 
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#define max 10200

int main()
{
	char filename[25],buff[max],c,c1;
	FILE *f1,*f2;

	printf("Enter the filename : \n");
	scanf("%s",filename);
	f1=fopen(filename,"r");
	if(f1==NULL)
	{
		printf("ERROR\n");
	}
	printf("Enter the filename : \n");
	scanf("%s",filename);
	f2=fopen(filename,"w+");

	c=fgetc(f1);
	int i=0;
	while(c!=EOF)
	{
		if(c=='/')
		{
			c1=getc(f1);
			if(c1=='/'){
				while(c!='\n')
				{
					c=getc(f1);
				}
			}
			else if(c1=='*')
			{
				c=getc(f1);
				while(c!='*')
				{
					c=getc(f1);
				}

			}
		}
		buff[i++]=c;
		putc(c,f2);
		c=getc(f1);
	}
	printf("\nContents are being Transferred \n");
	printf("\n----------------------------------------------------------------------\n");
	printf("%s\n",buff);
}