#include<iostream>
#include<math.h>
using namespace std;
bool czy235 (int a)
{
    while(a%2==0)
        a/=2;
    while(a%3==0)
        a/=3;
    while(a%5==0)
        a/=5;
    if(a==1) return true;
    return false;
}
int main()
{
    int n=0, ile=0;
    cout <<"enter"<<endl;
    cin >>n;
    for(int i=1; i<=n; i++)
    {
        if(czy235(i))
            ile++;
    }
    cout <<ile;
    return 0;
}
