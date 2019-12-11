#include <iostream>
using namespace std;
bool czyNIEparzysta(int n)
{
    while(n>0)
    {
        if(n%2==0) return false;
        n/=10;
    }
    return true;
}
int main()
{
    const int MAX=100;
    int tab[MAX][MAX], licznik=0;

    for (int i=0; i<MAX; i++)
        for (int j = 0; j < MAX; j++)
            if (czyNIEparzysta(tab[i][j]))
            {
                licznik++;
                break;
            }

    if(licznik==MAX) cout <<"TAK";
    else cout <<"NIE";
    return 0;
}
