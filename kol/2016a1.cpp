#include<iostream>
using namespace std;
bool almostPrime(int a, int b)
{
    if(a==0 || b==0) return false;
    while(a!=b)
    {
        if(a>b)
            a-=b;
        if(b>a)
            b-=a;
    }
    if(a==1) return true;
    return false;
}
int generuj(int a, int nowa1, int nowa2)
{
    int licz=0;
    if(a==0 && almostPrime(nowa1, nowa2))
    {
        cout<<nowa1<<" "<<nowa2<<endl;
        licz=1;
    }
    if(a>0)
    {
        licz+=generuj(a/10, nowa1*10+a%10, nowa2);
        licz+=generuj(a/10, nowa1, nowa2*10+a%10);
    }
    return licz;
}
int main()
{
    int a;
    cin >>a;
    cout<<generuj(a, 0, 0);
    return 0;
}
