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
        if(czyPierwsza(a%10)==false)
            return false;
        a/=10;
    }
    return true;
}
bool czyWierszOkej (int tab[M][M], int i)
{
    for(int j=0; j<M; j++){
        if(czyLiczbaOkej(tab[i][j])==true) {
            return true;}
    }
    return false;
}
bool czyKazdyWiersz (int tab[M][M])
{
    for(int i=0; i<M; i++){
        if(czyWierszOkej(tab, i)==false){
            return false;}
    }
    return true;
}
int main()
{
    int tab[M][M], j=0;

     for(int i=0; i<M; i++)
      //  for(int j=0; j<M; j++)
            tab[i][j++]=21;

    cout<<czyKazdyWiersz(tab);
    return 0;
}

