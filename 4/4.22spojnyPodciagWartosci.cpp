#include <iostream>
#include <algorithm>
#define M 10
using namespace std;
int maxPodciag (int tab[M][M])
{
    int licznik=1, maxWiersz=1, globalMAX=1, wiersz;

    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            for(int k=j; k<M-1; k++)
            {
                if(tab[i][k]==tab[i][k+1]){
                    licznik++;
                }
                else
                    break;
            }
            if(licznik>maxWiersz){
                maxWiersz=licznik;
            }
            licznik=1;
        }
        if(maxWiersz>globalMAX){
                globalMAX=maxWiersz;
                wiersz=i;
            }
        maxWiersz=1;
    }
    return globalMAX;
}
int main()
{
    int tab[M][M], a=1;

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
        {
             tab[i][j]=a;
             a++;
        }

    for(int j=0; j<M; j++)
        {
             tab[5][j]=5;
        }
    tab[5][9]=6;

    cout <<maxPodciag(tab);
    return 0;
}

