#include<iostream>
#include <cstdlib>
using namespace std;
void podciag(int tab[], int MAX)
{
    int roznica=tab[1]-tab[0], ile=2, maks=2;

    for(int i=1; i<MAX-1; i++)
    {
        if(tab[i+1]-tab[i]==roznica)
            ile++;
        else
        {
            roznica=tab[i+1]-tab[i];
            ile=2;
        }
        if(ile>maks)
            maks=ile;
    }
    cout <<maks;
}
int main()
{
    const int MAX=100;
    int tab[MAX];

    for(int i=0; i<MAX; i++)
        tab[i]=MAX-0;

    podciag(tab, MAX);
}
