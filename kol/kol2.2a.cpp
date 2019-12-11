#include<iostream>
using namespace std;
const int N=7;
bool przekatne(int t[N][N], int suma, int moc1, int moc2, int p)
{
    if(suma==0 && (moc1+moc2==N || moc1+moc2==N+1) && moc1==moc2)
        return true;
    for(int i=p; i<N; i++)
    {
        if((i!=N-1-i) && (przekatne(t, suma+t[i][i], moc1+1, moc2, i+1) || przekatne(t, suma+t[i][N-1-i], moc1, moc2+1, i+1)))
            return true;
        if((i==N-1-i) && (przekatne(t, suma+t[i][i], moc1+1, moc2+1, i+1)))
            return true;
    }
    return false;
}
int main()
{
    int t[N][N], a=-27;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            t[i][j]=a++;
    cout<<przekatne(t, 0, 0, 0, 0);
    return 0;
}
