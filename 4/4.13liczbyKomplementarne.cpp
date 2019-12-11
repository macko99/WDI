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
bool czyKomplementarna (int tab[M][M], int a)
{
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(czyPierwsza((tab[i][j]+a))){
                return true;}
        }
    }
    return false;
}
void zerowanie(int tab[M][M])
{
     for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(czyKomplementarna(tab, tab[i][j])==false){
                tab[i][j]=0;}
        }
     }
     for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            cout<<tab[i][j]<<" ";
}
int main()
{
    int tab[M][M];

     for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            tab[i][j]=rand()%10000+1;

    zerowanie(tab);
    return 0;
}

