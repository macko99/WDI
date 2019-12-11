#include<iostream>
#include <cstdlib>
using namespace std;
bool czyOK (int tab[], int MAX)
{
    int najmniejszy=tab[0], najwiekszy=tab[0], ileNAJw=0, ileNAJm=0;
    for(int i=0; i<MAX; i++)
    {
        if(tab[i]<najmniejszy)
            najmniejszy=tab[i];
        if(tab[i]>najwiekszy)
            najwiekszy=tab[i];
    }
    for(int i=0; i<MAX; i++)
    {
        if(tab[i]==najmniejszy)
            ileNAJm++;
        if(tab[i]==najwiekszy)
            ileNAJw++;
    }

    if(ileNAJm==1 && ileNAJw==1)
        return true;
    return false;
}
int main()
{
    const int MAX=100;
    int tab[MAX];

    cout<<czyOK(tab, MAX);
    return 0;
}

