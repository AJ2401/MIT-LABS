#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#define max 10200

int main()
{
	char buff[max],filename[25],c;
	FILE *f1,*f2;

	printf("Enter the filename : \n");
	scanf("%s",filename);
	f1=fopen(filename,"r");

	printf("Enter the filename : \n");
	scanf("%s",filename);
	f2=fopen(filename,"w+");

	int i=0;
	int j=0;
	c=fgetc(f1);
	while(c!=EOF)
	{
		while(j<=5 && c!=EOF)
		{
			if(c=='\n')
			{
				j++;
			}
			buff[i++]=c;
			fputc(c,f2);
			c=fgetc(f1);
		}
				fputc('\n',f2);
				fputc('\n',f2);
				fputc('\n',f2);
		printf("\n------------------------------------------------------------------\n");
		printf("\n%s\n",buff);
			j=0;
			i=0;
	}
	printf("\nContents is Done !!\n");

}