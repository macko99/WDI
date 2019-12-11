#include<iostream>
#define M 5
using namespace std;
int czyJestTuKwadrat(int tab[M][M], int I, int J, int k)
{
    for(int i=2;; i+=2)
    {
        if(i+I<M && i+J<M)
        {
            if(tab[I][J]*tab[I+i][J]*tab[I][J+i]*tab[I+i][J+i]==k)
                return i;
        }
        else
            return 0;
    }
}
bool czyJestKwadrat(int tab[M][M], int k)
{
    for(int i=0 ; i<M; i++){
        for(int j=0; j<M; j++){
            if(czyJestTuKwadrat(tab, i, j, k)!=0)
            {
                cout<<"wiersz: "<<i+czyJestTuKwadrat(tab, i, j, k)/2<<" kolumna: "<<j+czyJestTuKwadrat(tab, i, j, k)/2<<endl;
                return true;
            }
        }
    }
    cout<<"brak";
    return false;
}
int main()
{
    int tab[M][M], k;
    cin >>k;

    for(int i=0 ; i<M; i++)
        for(int j=0; j<M; j++)
            tab[i][j]=0;
    tab[0][0]=2;
    tab[0][2]=2;
    tab[2][0]=2;
    tab[2][2]=2;
    czyJestKwadrat(tab, k);
    return 0;
}
