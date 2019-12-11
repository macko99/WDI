#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    bool tab[n+1];

    for (int i=2; i<n+1; i++)
        tab[i]=true;

    for (int i=2; i*i<=n; i++)
        if(tab[i]==true)
            for (int j=i*i; j<=n; j+=i)
                tab[j]=false;

    for (int i=2; i<n+1; i++)
        if(tab[i]==true)
            cout <<i<<" ";

    return 0;
}
