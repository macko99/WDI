#include <iostream>
#include <algorithm>
#define M 5
using namespace std;
bool czyPierwsza(int a)
{
    if(a==1) return false;
    for(int i=2; i*i<=a; i++)
        if(a%i==0) return false;
    return true;
}
bool czyLiczbaOkej (int a)
{
    while(a>0)
    {
        if(czyPierwsza(a%10))
            return true;
        a/=10;
    }
    return false;
}
bool czyWierszOkej (int tab[M][M], int i)
{
    for(int j=0; j<M; j++){
        if(czyLiczbaOkej(tab[i][j])==false) {
            return false;}
    }
    return true;
}
bool czyIstniejeWiersz (int tab[M][M])
{
    for(int i=0; i<M; i++){
        if(czyWierszOkej(tab, i)){
            return true;}
    }
    return false;
}
int main()
{
    int tab[M][M], j=0;

     for(int i=0; i<M; i++)
      //  for(int j=0; j<M; j++)
            tab[i][j++]=2;

    cout<<czyIstniejeWiersz(tab);
    return 0;
}

