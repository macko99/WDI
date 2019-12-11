#include<iostream>
using namespace std;
const int N=9;
bool Prime(int a)
{
    if(a==0 || a==1) return false;
    if(a>2 && a%2==0) return false;
    for(int i=3; i<a; i+=2)
        if(a%i==0) return false;
    return true;
}
int modul(int x)
{
    if(x>0) return x;
    return -x;
}
bool warunki(int t[N])
{
    int licz=0, licz2=0;
    for(int i=0; i<N-1; i++)
        if((Prime(t[i]) && Prime(t[i+1])) || (modul(t[i]-t[i+1])<2))
            return false;
    return true;
}
void generuj(int t[N], int p)
{
    if(p==1 && warunki(t))
    {
        for(int i=0; i<N; i++)
            cout<<t[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=1; i<p; i++)
        {
            swap(t[i],t[p-1]);
            generuj(t, p-1);
            swap(t[i],t[p-1]);
        }
    }
}
int main()
{
    int t[N]={1,2,3,4,5,6,7,8,9};
    generuj(t, N);
    return 0;
}
