#include <iostream>
using namespace std;
const int N=4;
bool balance(int j, int suma, int t[N][N], int wiersze[N], int p, int k, int kolumny[N])
{
    if(suma==0)
        return true;
    if(j==N || suma<0 )
        return false;
    else
    {
        wiersze[p]+=k;
        kolumny[j]+=k;
        for(int m=0; m<N; m++)
            for(int n=0; n<N; n++)
                if(wiersze[m]==0 && kolumny[n]==0)
                    if(balance(n, suma-t[m][n], t, wiersze, m, 1, kolumny) || balance(n, suma, t, wiersze, m, 0, kolumny))
                        return true;
    }
    wiersze[p]-=1;
    kolumny[j]-=1;
    return false;
}
int main()
{
    int t[N][N], wiersze[N], kolumny[N], suma, a=1;
    cin>>suma;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            t[i][j]=a++;
            wiersze[i]=0;
            kolumny[i]=0;
        }
        t[2][2]=1;
        t[3][0]=1;
    cout<<balance(0, suma, t, wiersze, 0, 0, kolumny);
    return 0;
}

