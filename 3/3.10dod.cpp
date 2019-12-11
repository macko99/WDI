#include<iostream>
#include <cstdlib>
#define MAX 100
using namespace std;

int main()
{
    int tabela[MAX], licznik=0, maksik=0;

    for(int i=0; i<MAX; i++)
        tabela[i]=rand()%100+1;

    for (int i=0; i<MAX; i++)
    {
        for (int j=i; j<MAX-1; j++)
            if(tabela[j]<tabela[j+1])
                licznik++;

        if(licznik>maksik)
            maksik=licznik;
        licznik=0;
    }

    cout <<maksik;
    return 0;
}
