#include<iostream>
using namespace std;
struct ulamek
{
    int l;
    int m;
};
void wczytaj (ulamek &liczba)
{
    cin>>liczba.l >>liczba.m;
}
void wypisz (ulamek liczba)
{
    if(liczba.m == 0) cout<<"sprzecznosc"<<endl;
    if(liczba.l == liczba.m) cout<<1<<endl;
    if(liczba.m == 1 && liczba.l!=1) cout<<liczba.l<<endl;
    if(liczba.l == 0) cout<<0<<endl;
    if(liczba.l>liczba.m)
    {
        int calosci=liczba.l/liczba.m;
        cout<<calosci<<" " ;
        liczba.l=liczba.l-liczba.m*calosci;
    }
    if(liczba.l<liczba.m && liczba.l!=0)
        cout<<liczba.l<<"/"<<liczba.m<<endl;
}
ulamek suma (ulamek liczba1, ulamek liczba2)
{
    ulamek wynik;
    wynik.l=liczba1.l*liczba2.m+liczba2.l*liczba1.m;
    wynik.m=liczba1.m*liczba2.m;
    return wynik;
}
ulamek roznica (ulamek liczba1, ulamek liczba2)
{
    ulamek wynik;
    wynik.l=liczba1.l*liczba2.m-liczba2.l*liczba1.m;
    wynik.m=liczba1.m*liczba2.m;
    return wynik;
}
ulamek iloczyn (ulamek liczba1, ulamek liczba2)
{
    ulamek wynik;
    wynik.l=liczba1.l*liczba2.l;
    wynik.m=liczba1.m*liczba2.m;
    return wynik;
}
ulamek iloraz (ulamek liczba1, ulamek liczba2)
{
    ulamek wynik;
    wynik.l=liczba1.l*liczba2.m;
    wynik.m=liczba1.m*liczba2.l;
    return wynik;
}
ulamek skracanie (ulamek liczba)
{
    for(int i=2; i<=liczba.l; i++)
    {
        while(liczba.l%i==0 && liczba.m%i==0)
        {
            liczba.l/=i;
            liczba.m/=i;
        }
    }
    return liczba;
}
void uklad2rownan()
{
    ulamek x, y, wyznacznik;
    ulamek a,b,c,d,e,f;
    wczytaj(a); wczytaj(b); wczytaj(c);
    wczytaj(d); wczytaj(e); wczytaj(f);
    wyznacznik=roznica(iloczyn(a,e), iloczyn(d,b));
    x=iloraz(roznica(iloczyn(c,e),iloczyn(f,b)),wyznacznik);
    y=iloraz(roznica(iloczyn(a,f),iloczyn(d,c)),wyznacznik);
    wypisz(x); wypisz(y);
}
int main()
{
    uklad2rownan();

    return 0;
}
