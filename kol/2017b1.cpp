#include<iostream>
using namespace std;
const int N=8;
bool Prime(int a)
{
    if(a==0 || a==1) return false;
    if(a>2 && a%2==0) return false;
    for(int i=3; i<a; i+=2)
        if(a%i==0) return false;
    return true;
}
bool opcja(int wariant, int x, int y, int &nx, int &ny)
{
    switch(wariant)
    {
    case 1:
        nx = x+1;
        ny = y-2;
        break;
    case 2:
        nx = x+2;
        ny = y-1;
        break;
    case 3:
        nx = x+2;
        ny = y+1;
        break;
    case 4:
        nx = x+1;
        ny = y+2;
        break;
    case 5:
        nx = x-1;
        ny = y+2;
        break;
    case 6:
        nx = x-2;
        ny = y+1;
        break;
    case 7:
        nx = x-2;
        ny = y-1;
        break;
    case 8:
        nx = x-1;
        ny = y-2;
        break;
    }
    if(0<=nx && nx<N && 0<=ny && ny<N)
        return true;
    return false;
}
bool skoczki(int t[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int nx, ny;
            for(int k=1; k<9; k++)
            {
                if(opcja(k, i, j, nx, ny))
                    if(Prime(t[i][j]+t[nx][ny]))
                        return true;
            }
        }
    }
    return false;
}
int main()
{
    int t[N][N], a=0;
    for(int i=0; i<N; i++)
        for(int j=0;j<N; j++)
            t[i][j]=a++;
    cout<<skoczki(t);
    return 0;
}
