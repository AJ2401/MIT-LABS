#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a=0;
void Spaces(FILE*f1,FILE*f2)
{
	a=getc(f1);

	while(a!=EOF)
	{
		if(a==' ')
		{
			putc(a,f1);

			if(a==' ' && a=='\t')
			{
				while(a!=' ')
				{
					a=getc(f1);
				}
			}
			else
			{
				putc(a,f1);
			}
		}
		else
		{

		}
		a=getc(f1);
	}
}