#include <iostream>
#define MAX 10
using namespace std;
double sumaWiersza(int i, int (&tab)[MAX][MAX])
{
    double suma=0.0;
    for(int j=0; j<MAX; j++)
        suma+=tab[i][j];
    return suma;
}
double sumaKolumny(int j, int (&tab)[MAX][MAX])
{
    double suma=0.0;
    for(int i=0; i<MAX; i++)
        suma+=tab[i][j];
    return suma;
}
int main()
{
    int tab[MAX][MAX], wynik[2];
    double iloraz, maksik=0.0;  //4.5 --> maksik=-cos

    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
        {
            iloraz=sumaKolumny(j,tab)/sumaWiersza(i,tab);
            if(iloraz>maksik)
            {
                maksik=iloraz;
                wynik[0]=i; wynik[1]=j;
            }
        }

    cout <<"wiersz: "<<wynik[0]<<" kolumna: "<<wynik[1];
    return 0;
}
