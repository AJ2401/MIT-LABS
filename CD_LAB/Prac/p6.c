#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define max 10200

int main()
{
	FILE *f1,*f2;
	char buff[max],file[25],c,c1;
	int i=0;

	f1=fopen("prog1.c","r");
	f2=fopen("prog2.c","w+");

	c=fgetc(f1);
	while(c!=EOF)
	{
		if(c=='/')
		{
			buff[i++]=c;
			putc(c,f2);
			c=fgetc(f1);
			if(c=='/')
			{
				while(c!='\n')
				{
					buff[i++]=c;
					putc(c,f2);
					c=fgetc(f1);
				}
			}
		}
		if(c=='#')
		{
				while(c!='\n')
				{
					c=fgetc(f1);
				}
		}
		buff[i++]=c;
		putc(c,f2);
		c=fgetc(f1);
	}
	printf("Contents is being Done !\n");
	printf("\n----------------------------------------------------------------------\n");
	printf("\n%s\n",buff);
}