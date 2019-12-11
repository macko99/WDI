#include <iostream>
#include<cstdio>
using namespace std;
const int N=6;
bool ruch(int tab[N][N], int wariant, int x, int y, int& nx, int& ny)
{
    switch (wariant)
    {
        case 1:
            nx = x+1;
            ny = y-2;
            break;
        case 2:
            nx = x+2;
            ny = y-1;
            break;
        case 3:
            nx = x+2;
            ny = y+1;
            break;
        case 4:
            nx = x+1;
            ny = y+2;
            break;
        case 5:
            nx = x-1;
            ny = y+2;
            break;
        case 6:
            nx = x-2;
            ny = y+1;
            break;
        case 7:
            nx = x-2;
            ny = y-1;
            break;
        case 8:
            nx = x-1;
            ny = y-2;
            break;
    }
    if (0<=nx && nx<N && 0<=ny && ny<N && tab[nx][ny]==0)
        return true;
    return false;
}
bool skoczek(int tab[N][N], int x, int y, int ktory)
{
    tab[x][y] = ktory;
    if(ktory==N*N)
    {
        for(int i=0 ; i<N ; i++)
        {
            for(int j=0 ; j<N ; j++)
                cout<<tab[i][j]<<" ";
            cout<<endl;
        }
        return true;
    }
    else
    {
        int nx, ny;
        for(int w=1; w<9; w++)
            if(ruch(tab, w, x, y, nx, ny))
                if (skoczek(tab, nx, ny, ktory+1))
                    return true;
   }
   tab[x][y]=0;
   return false;
}
int main()
{
    int tab[N][N], wiersz, kolumna;
    cin >>wiersz>>kolumna;

    for(int i=0 ; i<N ; i++)
        for(int j=0 ; j<N ; j++)
            tab[i][j] = 0;

    cout<<"start: wiersz: "<<wiersz<<" kolumna: "<<kolumna<<endl;
    if(skoczek(tab, wiersz, kolumna, 1)==false)
        cout<<"brak";

    return 0;
}
