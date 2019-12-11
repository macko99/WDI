#include<iostream>
using namespace std;
bool pierwsza(int a)
{
    if(a==1) return false;
    if(a>2 && a%2==0) return false;
    for(int i=3; i<a; i+=2)
        if(a%i==0) return false;
    return true;
}
int buduj(int a, int b, int nowa, int level)
{
    int licz=0;
    if(a>0)
        licz+=buduj(a/10, b, nowa+(a%10)*level, level*10);
    if(b>0)
        licz+=buduj(a, b/10, nowa+(b%10)*level, level*10);
    if(a==0 && b==0 && pierwsza(nowa))
        licz=1;
    return licz;
}
int main()
{
    int liczba, liczba2;
    cin >>liczba>>liczba2;
    cout<<buduj(liczba, liczba2, 0, 1);
    return 0;
}
