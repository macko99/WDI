#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;
int roznicaPoziomu(int tab[MAX][MAX])
{
    int poziomMAX=0;
    int poziomMIN=0;

    for(int i=1;i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(tab[i][j]<tab[poziomMAX][j])
                break;
            if(tab[i][j]>tab[poziomMAX][j])
            {
                poziomMAX=i;
                break;
            }
        }
    }

    for(int i=1;i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(tab[i][j]>tab[poziomMIN][j])
                break;
            if(tab[i][j]<tab[poziomMIN][j])
            {
                poziomMIN=i;
                break;
            }
        }
    }

    if(poziomMAX-poziomMIN>0)
        return poziomMAX-poziomMIN;
    return poziomMIN-poziomMAX;
}
int main()
{
    int tab[MAX][MAX];

    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            tab[i][j]=rand()%2;

    for(int j=0; j<MAX; j++)
    {
        tab[1][j]=1;
        tab[4][j]=0;
    }

    cout<<roznicaPoziomu(tab);

    return 0;
}
