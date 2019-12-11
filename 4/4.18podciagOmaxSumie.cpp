#include <iostream>
#include <algorithm>
#define M 10
using namespace std;
int maxPodciag (int tab[M][M])
{
    int maxSuma=tab[0][0], suma=0;
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            for(int k=j; k<j+10 && k<M; k++)
            {
                suma+=tab[i][k];
                if(suma>maxSuma)
                {
                    maxSuma=suma;
                }
            }
            suma=0;
        }
    }
    for(int j=0; j<M; j++){
        for(int i=0; i<M; i++){
            for(int k=i; k<i+10 && k<M; k++)
            {
                suma+=tab[j][k];
                if(suma>maxSuma)
                {
                    maxSuma=suma;
                }
            }
            suma=0;
        }
    }
    return maxSuma;
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

    cout <<maxPodciag(tab);
    return 0;
}

