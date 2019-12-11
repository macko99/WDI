#include<iostream>
using namespace std;
const int N=8;
int suma (int I, int J, int t[N][N])
{
    int suma=0;
    for(int i=0; i<N; i++)
    {
        suma+=t[I][i];
        suma+=t[i][J];
    }
    return suma-t[I][J];
}
void wieze(int t[N][N])
{
    int kopia[N][N], maksik=0, a=0, wynik[4];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            kopia[i][j]=suma(i, j, t);
    while(a<4)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(kopia[i][j]>maksik)
                {
                    maksik=kopia[i][j];
                    wynik[a]=i;
                    wynik[a+1]=j;
                }
            }
        }
        kopia[wynik[0]][wynik[1]]=0;
        maksik=0;
        a+=2;
    }
    cout<<wynik[0]<<", "<<wynik[1]<<endl<<wynik[2]<<", "<<wynik[3];
}
int main()
{
    int t[N][N], a=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            t[i][j]=a++;
    wieze(t);
    return 0;
}
