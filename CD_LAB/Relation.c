#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define max 1024
int Relational(char c,FILE*f1)
{
	int b=0;
	int i=0;
	char buf[max];
	if(c=='=')
	{
		buf[i++]=c;
		c = fgetc(f1);
	if(c=='=')
	{
		buf[i++]=c;
		buf[i]='\0';
		printf("\n Relational operator : %s",buf);
	}
	else
	{
		buf[i]='\0';
		printf("\n Assignment operator: %s",buf);
		}
		b=1;
		i=0;
	}
	else
	{
	if(c=='<'||c=='>'||c=='!')
	{
		buf[i++]=c;
		c = fgetc(f1);
	if(c=='=')
	{
		buf[i++]=c;
	}
		buf[i]='\0';
		printf("\nRelational operator : %s\n",buf);
		b=1;
		i=0;
	}
	else
	{
		buf[i]='\0';
		}
	}
	return(b);
}