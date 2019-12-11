#include <iostream>
using namespace std;
const int N=2;
void dosun (int t[N][N], int t2[N][N], int i, int n)
{
    for(int j=0; j<n-i; j++)
        for(int k=0; k<n; k++)
            t2[j][k]=t[j+1][k];
    for(int j=i; j<n-1; j++)
        for(int k=0; k<n-1; k++)
            t2[k][j]=t2[k][j+1];
}
int det (int t[N][N], int n)
{
    int t2[N][N], s=0, znak=1;
    if(n==1) return t[0][0];
    for(int i=0; i<n; i++)
    {
        dosun(t,t2,i,n);
        s+=t[0][i]*det(t2, n-1)*znak;
        znak=-znak;
    }
    return s;
}
int main()
{
    int t[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>t[i][j];
    cout<<det(t, N);
    return 0;
}
