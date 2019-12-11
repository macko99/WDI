#include<iostream>
using namespace std;
const int N=4;
bool Prime(int a)
{
    if(a==0 || a==1) return false;
    if(a>2 && a%2==0) return false;
    for(int i=3; i<a; i+=2)
        if(a%i==0) return false;
    return true;
}
int generuj(int t1[N], int t2[N], int suma, int i)
{
    int licz=0;
    if(i==N)
    {
        if(Prime(suma))
        {
            cout<<suma<<endl;
            licz=1;
        }
    }
    else
    {
        licz+=generuj(t1, t2, suma+t1[i], i+1);
        licz+=generuj(t1, t2, suma+t2[i], i+1);
        licz+=generuj(t1, t2, suma+t1[i]+t2[i], i+1);
    }
    return licz;
}
int main()
{
    int t1[N]={1,3,2,4}, t2[N]={9,7,4,8};
    cout<<endl<<generuj(t1, t2, 0, 0);
    return 0;
}
