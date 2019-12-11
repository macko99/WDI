#include <iostream>
using namespace std;
bool czyMAparzysta(int n)
{
    while(n>0)
    {
        if(n%2==0) return true;
        n/=10;
    }
    return false;
}
int main()
{
    const int MAX=100;
    int tab[MAX][MAX], licznik=0;
    bool flaga=false;

    for (int i=0; i<MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            if (czyMAparzysta(tab[i][j]))
                licznik++;

        if(licznik==MAX)
        {
            flaga=true;
            break;
        }
        else licznik=0;
    }

    if(flaga) cout <<"TAK";
    else cout <<"NIE";
    return 0;
}
