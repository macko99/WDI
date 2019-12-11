#include <iostream>
#include <algorithm>
#define M 5
using namespace std;
int suma(int tab[M][M], int i, int j)
{
    int sumka=0;
    if (j+1<M)
        sumka+=tab[i][j+1];
    if (j-1>=0)
        sumka+=tab[i][j-1];
    if(i-1>=0)
        sumka+=tab[i-1][j];
    if(i+1<M)
        sumka+=tab[i+1][j];

    if(i-1>=0 && j+1<M)
        sumka+=tab[i-1][j+1];
    if(i-1>=0 && j-1>=0)
        sumka+=tab[i-1][j-1];
    if(i+1<M && j+1<M)
        sumka+=tab[i+1][j+1];
    if(i+1<M && j-1>=0)
        sumka+=tab[i+1][j-1];

    return sumka;
}
void maxSumka(int tab[M][M])
{
    int kopia[M][M], maks=0, wiersz, kolumna;

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            kopia[i][j]=tab[i][j];

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            kopia[i][j]=suma(tab, i, j);

    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(kopia[i][j]>maks)
            {
                maks=kopia[i][j];
                wiersz=i;
                kolumna=j;
            }
        }
    }
    cout<<wiersz<<" "<<kolumna;
}
int main()
{
    int tab[M][M];

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            tab[i][j]=1;

    tab[0][0]=4;
    maxSumka(tab);
    return 0;
}

