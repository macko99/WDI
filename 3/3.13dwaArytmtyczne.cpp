#include<iostream>
#include <cstdlib>
using namespace std;
int arytmetycznyDodatni (int tab[], int MAX)
{
    int roznica=tab[1]-tab[0], ile=1, maks=1, i;

    for(i=0; i<MAX-1; i++)
    {
        if(tab[i+1]-tab[i]>0)
        {
            roznica=tab[i+1]-tab[i];
            break;
        }
    }

    for(i; i<MAX-1; i++)
    {
        if(tab[i+1]-tab[i]==roznica)
            ile++;
        else
        {
            for(int j=i; j<MAX-1; j++)
            {
                if(tab[j+1]-tab[j]>0)
                {
                    roznica=tab[i+1]-tab[i];
                    i=j;
                    break;
                }
            }
            ile=2;
        }
        if(ile>maks)
            maks=ile;
    }
    return maks;
}
int arytmetycznyUjemny (int tab[], int MAX)
{
    int roznica=tab[1]-tab[0], ile=1, maks=1, i;

    for(i=0; i<MAX-1; i++)
    {
        if(tab[i+1]-tab[i]<0)
        {
            roznica=tab[i+1]-tab[i];
            break;
        }
    }

    for(i; i<MAX-1; i++)
    {
        if(tab[i+1]-tab[i]==roznica)
            ile++;
        else
        {
            for(int j=i; j<MAX-1; j++)
            {
                if(tab[j+1]-tab[j]<0)
                {
                    roznica=tab[i+1]-tab[i];
                    i=j;
                    break;
                }
            }
            ile=2;
        }
        if(ile>maks)
            maks=ile;
    }
    return maks;
}
int main()
{
    const int MAX=50;
    int tab[MAX];

    for(int i=0; i<MAX; i++)
    {
        int temp=rand()%99+1;
        if(temp%2!=0)
            tab[i]=temp;
        else
            tab[i]=temp+1;
    }

    cout<<arytmetycznyDodatni(tab, MAX)-arytmetycznyUjemny(tab, MAX);
    return 0;
}
