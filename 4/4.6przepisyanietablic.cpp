#include <iostream>
#include <algorithm>
#define M 5
using namespace std;
void sortowanie(int tab[])
{
    int licznik=0;

    for(int i=0; i<M*M; i++)
        for(int j=0; j<M*M-1; j++)
            if(tab[j]>tab[j+1])
                swap(tab[j+1],tab[j]);

    for(int i=0; i<M*M; i++)
    {
        if(tab[i]!=0)
        {
            cout<<tab[i]<<" ";
            licznik++;
        }

    }
    for(int i=0; i<M*M-licznik; i++)
        cout<<0<<" ";

}
bool czyRaz (int tab[M][M], int a)
{
    int ile=0;
    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
        {
            if(tab[i][j]==a)
                ile++;
            if(ile>1) return false;
        }
    if(ile==1) return true;
}
int main()
{
    int tab[M][M], tab2[M*M],licznik=0, licz2=1;

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            tab[i][j]=rand()%100+1;

    for(int i=0; i<M*M; i++)
         tab2[i]=0;

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            if (czyRaz(tab,tab[i][j])==true)
                tab2[licznik++]=tab[i][j];

                sortowanie(tab2);

    return 0;
}
