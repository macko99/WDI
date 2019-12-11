#include<iostream>
using namespace std;
const int N=5;

bool odwazniki(int tab[], int wziete[], int ktoryBiore, int obecnaMasa, int masa, int ktoraSzalka)
{
    if(obecnaMasa==masa)
    {
        wziete[ktoryBiore]=ktoraSzalka;
        return true;
    }
    if(ktoryBiore==N)
        return false;
    else
    {
        wziete[ktoryBiore]=ktoraSzalka;
        for(int i=ktoryBiore; i<N; i++)
            if(wziete[i]==0)
                if(odwazniki(tab, wziete, i, obecnaMasa+tab[i], masa, 1)==true || odwazniki(tab, wziete, i, obecnaMasa-tab[i], masa, 2)==true)
                    return true;
    }
    wziete[ktoryBiore]=0;
    return false;
}

int main()
{
    int tab[N]={20,3,6,36,4}, wziete[N]={0,0,0,0,0}, masa;
    bool czyIstenija=false;
    cin >>masa;

    for(int i=0; i<N; i++)
        if(odwazniki(tab, wziete, i, 0+tab[i], masa, 1)==true || odwazniki(tab, wziete, i, 0-tab[i], masa, 2)==true)
            break;

    cout<<"pierwsza szalka : ";
    for(int i=0; i<N; i++)
        if(wziete[i]==1)
        {
            cout<<tab[i]<<" ";
            czyIstenija=true;
        }

    cout<<endl<<"druga szalka : ";
    for(int i=0; i<N; i++)
        if(wziete[i]==2)
            cout<<tab[i]<<" ";
    cout<<"plus masa: "<<masa;

    if(czyIstenija==false)
        cout<<endl<<"brak odwaznikow";

    return 0;
}
