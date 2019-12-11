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
    return suma-t[I][J];
}
bool wieze(int t[N][N], int x1, int y1, int x2, int y2)
{
    int sumy[N][N], maksik=0;
    for(int i=0; i<N;i++)
        for(int j=0; j<N; j++)
            sumy[i][j]=suma(i, j, t);
            sumy[7][7]=686;
    for(int i=0; i<N; i++)
    {
        if(sumy[x1][i]>sumy[x1][y1] || sumy[i][y1]>sumy[x1][y1] || sumy[x2][i]>sumy[x2][y2] || sumy[i][y2]>sumy[x2][y2])
            return true;
    }
    return false;
}
int main()
{
    int t[N][N], a=0, x1=7, y1=4, x2=7, y2=7;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            t[i][j]=a++;
    cout<<wieze(t, x1, y1, x2, y2);
    return 0;
}
