#include <iostream>
#include <algorithm>
#define M 5
using namespace std;
bool czyFriends (int a, int b)
{
    bool tab[10];

    for (int i=0; i<10; i++)
        tab[i]=0;

    while(a>0)
    {
        tab[a%10]=1;
        a/=10;
    }

    while(b>0)
    {
        if(tab[b%10]==0) return false;
        b/=10;
    }
    return true;
}
bool czySasiadkiPrzyjaciolki (int tab[M][M],int i, int j)
{
    int licznik=0, kontrola=0;
    if (j+1<M)
    {
        licznik++;
        if(czyFriends(tab[i][j],tab[i][j+1]))
            kontrola++;

    }
    if (j-1>=0)
    {
        licznik++;
        if(czyFriends(tab[i][j],tab[i][j-1]))
            kontrola++;
    }
    if(i-1>=0)
    {
        licznik++;
        if(czyFriends(tab[i][j],tab[i-1][j]))
            kontrola++;
    }
    if(i+1<M)
    {
        licznik++;
        if(czyFriends(tab[i][j],tab[i+1][j]))
            kontrola++;
    }

    if(licznik==kontrola) return true;

    return false;
}
int sasiadki (int tab[M][M])
{
    int licznik=0;
    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
    {
        if(czySasiadkiPrzyjaciolki(tab, i, j))
            licznik++;
    }
    return licznik;
}
int main()
{
    int tab[M][M];

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            tab[i][j]=22;

    tab[0][0]=4;

    cout<<sasiadki(tab);
    return 0;
}
