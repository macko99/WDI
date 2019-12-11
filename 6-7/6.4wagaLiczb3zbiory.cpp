#include <iostream>
const int N=10;
using namespace std;
bool podzial(int tab[], int suma1gr, int suma2gr, int suma3gr, int ktoraLiczba, int suma)
{
    if(suma1gr>=suma || suma2gr>=suma || suma3gr>=suma)
        return false;

    if(suma1gr==(suma/3) && suma1gr==suma2gr && suma2gr==suma3gr)
        return true;

    for(int i=ktoraLiczba; i<N; i++)
    {
            if(podzial(tab,suma1gr+tab[i],suma2gr,suma3gr,ktoraLiczba+1,suma)==true || podzial(tab,suma1gr,suma2gr+tab[i],suma3gr,ktoraLiczba+1,suma)==true || podzial(tab,suma1gr,suma2gr,suma3gr+tab[i],ktoraLiczba+1,suma)==true)
                return true;
            //return false;
    }
    return false;
}
bool czynnikiPierwsze(int tab[])
{
    int suma=0;
    for(int i=0; i<N; i++)
    {
        int licznik=0;
        for(int j=2; j<=tab[i]; j++)
            if(tab[i]%j==0)
            {
                licznik++;
                while(tab[i]%j==0)
                    tab[i]/=j;
            }
        tab[i]=licznik;
        suma+=tab[i];
    }
    if(podzial(tab, 0, 0, 0, 0, suma)==true)
        return true;
    return false;
}
int main()
{
    int tab[N]={10,10,10,10,13,11,10,10,10,10};
    cout<<czynnikiPierwsze(tab);
    return 0;
}
