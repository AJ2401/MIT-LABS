//Remove Preprocessors .. Macros,Define,Micros,Libraries 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *F1,*F2;
	int a,b,c;

	F1=fopen("prog.c","r");

	if(F1==NULL)
	{
		printf("Cannot open the File !! "); 
	}

	//F2=fopen("out.c","w+");
	a=getc(F1);
	while(a!=EOF)
	{
		if(a=='#')
		{
				while(a!='\n')
				{
					a=getc(F1);
				}
		}
		else{
			putc(a,F2);
			}a=getc(F1);
	}
	printf("Copied the Content into the Another File Without any Preprocessors !! \n");
	fclose(F1);
	//fclose(F2);
	return(0);
}
