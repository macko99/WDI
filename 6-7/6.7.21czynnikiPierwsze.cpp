#include<iostream>
using namespace std;
bool pierwsza(int a)
{
    if(a>2 && a%2==0) return false;
    for(int i=3; i<a; i+=2)
        if(a%i==0) return false;
    return true;
}
int czyJestDroga(int N, int tab[], int i, int licz)
{
    if(i==N-1)
        return licz;
    else
    {
        for(int j=2; j<tab[i]; j++)
            if(tab[i]%j==0 && i+j<N && pierwsza(j))
                return czyJestDroga(N, tab, i+j, licz+=1);
    }
    return -1;
}
int main()
{
    const int N=5;
    int tab[5]={4,7,6,4,1};
    cout<<czyJestDroga(N, tab, 0, 0);
    return 0;
}
