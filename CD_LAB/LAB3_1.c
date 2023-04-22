#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <ctype.h>
#include "Relation.c"
#include "Keyword.c"
#include "Special.c"
#include<string.h>
#include "Remove.c"
#define max 1024
int main()
{
	FILE *f1,*f2;
	int b=0,c=0;
	char a;
	int count=0;
	char buff[max];

	f2=fopen("prog2.c","r");
	if(f2==NULL)
	{
		printf("Cannot Open the File \n");
	}
	//f2=fopen("prog2.c","w+");
	//removing(f1,f2);
	a=fgetc(f2);

	while(a!=EOF)
	{
		buff[b++]=a;
		a = fgetc(f2);
		if(isalpha(a))
		{
			while(isalnum(a))
			{
				buff[b++]=a;
				a = fgetc(f2);
			}
			buff[b] = '\0';
			fseek(f2, -1, SEEK_CUR);
			if(Keyword(buff)==1){

			}
			else{
				count++;
				printf("Identifier is <ID,%d> is : %s\n",count,buff);
			}
		}
		else if(isdigit(a))
		{
			printf("\nIs a Number : %d\n",a);
		}
		else if(a=='"')
		{
			while(a!='"')
			{
				a=fgetc(f2);
			}
		}
		else if(Special(buff)==1)
		{
			buff[b] = '\0';
			//a=fgetc(f2);
			//break;
			//continue;
		}
		
		else if(Relational(a,f2)==1)
		{
			//a=fgetc(f2);
			//break;
			//continue;
		}
		b=0;
		a=fgetc(f2);
	}
}
