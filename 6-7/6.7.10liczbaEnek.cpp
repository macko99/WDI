#include<iostream>
using namespace std;
const int N=4;
int licz;
void nKi (int t[N], int n, int iloczyn, int p)
{
    if(n==1)
    {
        for(int i=p; i<N; i++)
            if(t[i]==iloczyn)
                licz++;
    }
    else
    {
        for(int i=p; i<N; i++)
            if(iloczyn%t[i]==0)
                nKi(t, n-1, iloczyn/t[i], i+1);
    }
}
int main()
{
    int t[N], iloczyn, n;
    for(int i=0; i<N; i++)
        cin>>t[i];
    cin >>iloczyn;
    cin>>n;
    nKi(t, n, iloczyn, 0);
    cout<<licz;
    return 0;
}
