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
void wieze(int t[N][N], int w[N])
{
    int mocWiezy[N], wynik[2], maksik=0, a=0;
    for(int i=0; i<N; i++)
        mocWiezy[i]=suma(w[i], i, t);
    while(a<2)
    {
        for(int i=0; i<N; i++)
        {
            if(mocWiezy[i]>maksik)
            {
                maksik=mocWiezy[i];
                wynik[a]=i;
            }
        }
        maksik=0;
        mocWiezy[wynik[a]]=0;
        a+=1;
    }
    cout<<wynik[0]<<endl<<wynik[1];
}
int main()
{
    int t[N][N], w[N]={0,1,2,3,4,5,6,7}, a=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            t[i][j]=a++;
    wieze(t, w);
    return 0;
}
