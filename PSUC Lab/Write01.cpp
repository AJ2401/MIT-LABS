#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char *str1="C++";
    char *str2="Programming";
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
    cout.write(str1,8);
    return 0;
}
