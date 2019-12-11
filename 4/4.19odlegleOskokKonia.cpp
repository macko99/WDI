#include <iostream>
#include <algorithm>
#include<cstdlib>
#define M 10
using namespace std;
bool czyDobraOdleglosc(int I, int J, int i, int j)
{
    if((I-i==2 || I-i==-2) && (J-j==1 || J-j==-1))
        return true;
    if((I-i==1 || I-i==-1) && (J-j==2 || J-j==-2))
        return true;

    return false;
}
bool dobryIloczyn(int tab[M][M], int a, int I, int J, int iloczyn)
{
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(tab[i][j]*a==iloczyn){
                if(czyDobraOdleglosc(I, J, i, j))
                    return true;
            }
        }
    }
    return false;
}
int ilePar(int tab[M][M], int iloczyn)
{
    int licznik=0;
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(dobryIloczyn(tab, tab[i][j], i, j, iloczyn)){
                licznik++;
            }
        }
    }
    return licznik;
}
int main()
{
    int tab[M][M], iloczyn;
    cin >>iloczyn;

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            tab[M][M]=2;

    cout<<ilePar(tab, iloczyn);

    return 0;
}


