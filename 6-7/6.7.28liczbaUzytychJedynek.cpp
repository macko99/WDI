#include<iostream>
using namespace std;
const int N=5;
int jedynki (int a)
{
    int licz=0;
    while(a>0)
    {
        if(a%2==1) licz++;
        a/=2;
    }
    return licz;
}
bool podzial(int t[N], int i, int a, int b, int c)
{
    if(i==N && a==b && a==c)
        return true;
    if(i==N)
        return false;
    if(podzial(t, i+1, a+jedynki(t[i]), b, c) || podzial(t, i+1, a, b+jedynki(t[i]), c) || podzial(t, i+1, a, b, c+jedynki(t[i])))
        return true;
    return false;
}
int main()
{
    int t[N]={2,3,5,7,15};
    cout<<podzial(t, 0, 0, 0, 0);
    return 0;
}
