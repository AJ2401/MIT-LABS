#include<stdio.h>
int main()
{
 printf("DANDA SRINATH(200904012)\n");
    int num,s,r,count=0,i,x,p=0;
    printf("Enter the Number :");
    scanf("%d",&num);
    s=num;
        do
        {
            printf("%d\n",num);
            num-=1;
        }
        while(num>-2);

        {while(s!=1)
        {
            x=0;
            for(i=2; i<s; i++)
            {
                r=s%i;
                if(r==0)
                {
                    count++;
                    x=1;
                    break;
                }
            }
            if(x==0)
            {
                p+=1;
            }
            else
            {
                s-=1;
            }
        }
        }
    printf("Total Number of Prime Numbers %d\t",p);
    printf("Total Number of Composite Numbers %d\t",count);
    return 0;
}
