#include<iostream>
using namespace std;
const int N=4;
int licz;
int nKi (int t[N], int n, int suma, int p)
{
    int wynik=0;
    if(n==1)
    {
        for(int i=p; i<N; i++)
            if(t[i]==suma)
                wynik=1;
    }
    else
    {
        for(int i=p; i<N; i++)
            wynik+=nKi(t, n-1, suma-t[i], i+1);
    }
    return wynik;
}
int main()
{
    int t[N], suma, n;
    for(int i=0; i<N; i++)
        cin>>t[i];
    cin >>suma;
    cin>>n;
    cout<<nKi(t, n, suma, 0);
    return 0;
}
