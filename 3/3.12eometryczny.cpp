#include<iostream>
#include <cstdlib>
using namespace std;
void geometryczny (double tab[], int MAX)
{
    double iloraz=tab[1]/tab[0], ile=2, maks=2;

    for(int i=1; i<MAX-1; i++)
    {
        if(tab[i+1]/tab[i]==iloraz)
            ile++;
        else
        {
            iloraz=tab[i+1]/tab[i];
            ile=2;
        }
        if(ile>maks)
            maks=ile;
    }
    cout <<maks;
}
int main()
{
    const int MAX=10;
    double tab[MAX];

    for(int i=0; i<MAX; i++)
        tab[i]=rand()%100+1;

    geometryczny(tab, MAX);
}
