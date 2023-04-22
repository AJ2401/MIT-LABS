#include<stdio.h>
#include<stdlib.h>

void removing(FILE*F1,FILE*F2)
{
	char a;
	if(F1==NULL)
	{
		printf("Cannot open the File !! "); 
	}

	F2=fopen("out.c","w+");
	a=fgetc(F1);
	while(a!=EOF)
	{
		if(a==' ')
		{
			putc(a,F1);
			a=fgetc(F1);
			if(a==' '&& a=='\t')
			{
				while(a!=' ')
				{
					a=fgetc(F1);
				}
			}
			else
			{
				putc(a,F2);
			}
		}
		else{
			putc(a,F2);
			}
	a=getc(F1);
}
	while(a!=EOF){
		if(a=='#')
		{
				while(a!='\n')
				{
					a=fgetc(F1);
				}
		}
		else{
			putc(a,F2);
			}
		a=fgetc(F1);
	}

}