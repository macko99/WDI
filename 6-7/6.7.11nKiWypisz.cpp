#include<iostream>
using namespace std;
const int N=4;
void nKi (int t[N], bool wziete[N], int n, int iloczyn, int p)
{
    if(n==1)
    {
        for(int i=p; i<N; i++)
            if(t[i]==iloczyn)
            {
                wziete[i]=1;
                for(int j=0; j<N; j++)
                    if(wziete[j]==1)
                        cout<<t[j]<<" ";
                cout <<endl;
            }
    }
    else
    {
        for(int i=p; i<N; i++)
            if(iloczyn%t[i]==0)
            {
                wziete[i]=1;
                nKi(t, wziete, n-1, iloczyn/t[i], i+1);
            }

    }
    wziete[p-1]=0;
}
int main()
{
    int t[N], iloczyn, n;
    bool wziete[N];
    for(int i=0; i<N; i++)
    {
        cin>>t[i];
        wziete[i]=0;
    }
    cin >>iloczyn;
    cin>>n;
    nKi(t,wziete, n, iloczyn, 0);
    return 0;
}

