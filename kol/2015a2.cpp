#include<iostream>
#include <algorithm>
using namespace std;
const int N=8;
int suma(int I, int J, int t[N][N])
{
    int suma=0;
    for(int i=0; i<N; i++)
    {
        suma+=t[I][i];
        suma+=t[i][J];
    }
    return suma;
}
void gdzie(int t[N][N])
{
    int sumy[N][N], maksik, wynik[4], a=0;
    for(int i=0; i<N;i++)
        for(int j=0; j<N; j++)
            sumy[i][j]=suma(i, j, t);
    while(a<4)
    {
        maksik=-40;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(sumy[i][j]>maksik)
                {
                    maksik=sumy[i][j];
                    wynik[a]=i;
                    wynik[a+1]=j;
                }}}
        sumy[wynik[0]][wynik[1]]=-40;
        a+=2;
    }
        cout<<wynik[0]<<", "<<wynik[1]<<endl<<wynik[2]<<", "<<wynik[3];
}
int main()
{
    int t[N][N], a=0, x1=0, y1=0, x2=7, y2=7;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            t[i][j]=a++;
    gdzie(t, x1, y1, x2, y2);
    return 0;
}
