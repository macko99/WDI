#include <iostream>
using namespace std;
const int N=201;
void zmiana(bool tab[N][N])
{
    int szachowane[N][N];
    int licz=0, wiersze[N], kolumny[N];
    for(int i=0; i<N; i++)
        if(tab[i][0]==1)
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(tab[i][j]==1)
                licz++;
        }
        wiersze[i]=licz;
        licz=0;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(tab[j][i]==1)
                licz++;
        }
        kolumny[i]=licz;
        licz=0;
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(wiersze[i]>1 && kolumny[j]>1 && tab[i][j]==1)
                cout<<"przesuwamy wieze z "<<i <<" "<<j <<" na pole ";
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(tab[i][j]==0)
                cout<<i<<" "<<j;
}
int main()
{
    bool t[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            t[i][j]=0;
    for(int i=0; i<N; i++)
        t[i][0]=1;
    for(int i=0; i<N; i++)
        t[0][i]=1;
    t[0][3]=0;
    t[3][0]=0;
    t[2][50]=1;
    zmiana(t);
    return 0;
}
