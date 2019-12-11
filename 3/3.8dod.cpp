#include<iostream>
#include <cstdlib>
#define MAX 1000
using namespace std;
bool czyNIEparzysta  (int n)
{
    int ile=0, i=0;
    while(n>0)
    {
        if(n%2==1)
            ile++;
        n/=10;
        i++;
    }
    if(i==ile) return true;
    return false;
}
int main()
{
    int tab[MAX];
    bool flaga=false;

    for (int i=0; i<MAX; i++)
        tab[i]=rand()%1000+1;

    for (int i=0; i<MAX; i++)
    if(czyNIEparzysta(tab[i])==true)
    {
        flaga=true;
        break;
    }

    if(flaga)
        cout <<"TAK";
    else
        cout <<"NIE";

    return 0;
}
