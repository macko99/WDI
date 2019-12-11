#include<iostream>
#include <cstdlib>
using namespace std;
bool Fib(int c)
{
    int a=1, b=2;
    for(int i=0; i*i<c; i++)
    {
        if(c==b) return true;
        b+=a;
        a=b-a;
    }
    return false;
}
bool pierwsza(int c)
{
    if(c==1) return false;
    for(int i=2; i*i<c; i++)
        if(c%i==0) return false;
    return true;
}
int main()
{
    const int MAX=100;
    int tab[MAX];
    bool fla1=true, fla2=false;

    for(int i=0; i<MAX; i++)
        tab[i]=rand()%100+1;

    for(int i=0; i<MAX; i++)
    {
        if(Fib(i)==true && pierwsza(tab[i])==true)
        {
             fla1=false;
             break;
        }
        if(Fib(i)==false && pierwsza(tab[i])==true)
            fla2=true;
    }

    if(fla2==true && fla1==true)
        cout <<"TAK";
    else
        cout <<"NIE";
    return 0;
}
