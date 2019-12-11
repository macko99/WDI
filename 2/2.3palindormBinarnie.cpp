#include<iostream>
#include<math.h>
using namespace std;
string naString (int c)
{
    string liczba="";
    while(c>0)
    {
        char temp=c%10+'0';
        liczba=temp+liczba;
        c/=10;
    }
    return liczba;
}
string binary (int c)
{
    string bin="";
    while(c>0)
    {
        char temp=c%2+'0';
        bin=temp+bin;
        c/=2;
    }
    return bin;
}
bool palindrom (string c)
{
    for (int i=0; 2*i<c.size()-1; i++)
    {
        if(c[i] != c[c.size()-i-1])
            return false;
    }
    return true;
}
int main()
{
    int  n=0;
    cout <<"enter"<<endl;
    cin>>n;
    if(palindrom(naString(n)))
        cout <<"jest"<<endl;
    else
        cout <<"nie jest"<<endl;
    if(palindrom(binary(n)))
        cout <<"binarnie jest";
    else
        cout<<"binarnie nie jest";
    return 0;
}
