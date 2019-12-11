#include<iostream>
#include <cstdlib>
#define MAX 1000
using namespace std;
bool czyNIEparzysta  (int n)
{
    while(n>0)
    {
        if(n%2==1)
            return true;
        n/=10;
    }
    return false;
}
int main()
{
    int tab[MAX];
    bool flaga= true;

    for (int i=0; i<MAX; i++)
        tab[i]=rand()%1000+1;

    for (int i=0; i<MAX; i++)
    if(czyNIEparzysta(tab[i])==false)
    {
        flaga=false;
        break;
    }

    if(flaga)
        cout <<"TAK";
    else
        cout <<"NIE";

    return 0;
}
