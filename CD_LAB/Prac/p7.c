#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define max 25
char *arr[]={"char","long","int","float","double","unsinged","char*","int*"};
int search(char a[])
{
	int len=sizeof(arr)/sizeof(char*);
	for(int i=0;i<len;i++)
	{
		if(strcmp(arr[i],a)==0)
		{
			return(1);
		}
	}
	return(0);
}

void change(char arr[])
{
	int i=0;
	char a=(char)32;
	while(arr[i]!='\n')
	{
		arr[i]=arr[i]-a;
		i++;
	}
}
int main()
{
	FILE *f1;
	char file[25],c,c1;
	int i=0;

	f1=fopen("prog1.c","r");

	char buff[max];
	c=getc(f1);
	while(c!=EOF)
	{

		while(c!=' ' && c!=EOF)
		{
			buff[i++]=c;
			c=getc(f1);
		}
		if(search(buff)==1)
			{
				change(buff);
				printf("%s\n",buff);
			}
		i=0;
		c=fgetc(f1);
	}
}