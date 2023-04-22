#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char *str1,a[50];
    char *str2,b[60];
    cout<<"Enter any two names "<<endl;
    cin>>a;
    cin>>b;
    str1=&a[50];
    str2=&b[60];
    int m=strlen(str1);
    int n=strlen(str2);

    for(int i=1;i<n;i++)
    {
        cout.write(str2,i);
        cout<<endl;
    }
    for(int i=n;i>0;i--)
    {
        cout.write(str2,i);
        cout<<endl;
    }
    cout<<endl;
    cout.write(str1,m).write(str2,n);
    cout<<endl;
    cout.write(str1,15);
    return 0;
}
