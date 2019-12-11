#include <iostream>
#include <algorithm>
#define M 5
using namespace std;
bool czyJestWiersz (int tab[M][M], int j)
{
    for(int i=0; i<M; i++)
        if(tab[i][j]==0)
            return true;
    return false;
}
bool czyJestKolumna (int tab[M][M], int i)
{
    for(int j=0; j<M; j++)
        if(tab[i][j]==0)
            return true;
    return false;
}
bool czyOkej(int tab[M][M])
{
    for(int i=0; i<M; i++)
        if(czyJestKolumna(tab, i)==false || czyJestWiersz(tab, i)==false)
            return false;
    return true;
}
int main()
{
    int tab[M][M], j=0;

    for(int i=0; i<M; i++)
        tab[i][j++]=0;

    cout<<czyOkej(tab);
    return 0;
}
