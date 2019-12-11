#include<iostream>
#include<algorithm>
using namespace std;
int mini;
int najmniejszy3(int a, int b, int c)
{
    if(a<b && a<c)
        return a;
    if(b<a && b<c)
        return b;
    return c;
}
int najmniejszy2(int a, int b)
{
    if(a<b)
        return a;
    return b;
}
void minimalnyKoszt (int t[8][8], int wiersz, int kolumna, int suma)
{
    if(wiersz==7)
    {
        if(kolumna>0 && kolumna <7)
            suma+=najmniejszy3(t[wiersz][kolumna-1],t[wiersz][kolumna],t[wiersz][kolumna+1]);
        if(kolumna==0)
            suma+=najmniejszy2(t[wiersz][kolumna],t[wiersz][kolumna+1]);
        if(kolumna==7)
            suma+=najmniejszy2(t[wiersz][kolumna-1],t[wiersz][kolumna]);
        if(suma<mini)
            mini=suma;
    }
    else
    {
        if(kolumna>0 && kolumna <7)
        {
            minimalnyKoszt(t, wiersz+1, kolumna-1, suma+t[wiersz][kolumna]);
            minimalnyKoszt(t, wiersz+1, kolumna, suma+t[wiersz][kolumna]);
            minimalnyKoszt(t, wiersz+1, kolumna+1, suma+t[wiersz][kolumna]);
        }
        if(kolumna==0)
        {
            minimalnyKoszt(t, wiersz+1, kolumna, suma+t[wiersz][kolumna]);
            minimalnyKoszt(t, wiersz+1, kolumna+1, suma+t[wiersz][kolumna]);
        }
        if(kolumna==7)
        {
            minimalnyKoszt(t, wiersz+1, kolumna-1, suma+t[wiersz][kolumna]);
            minimalnyKoszt(t, wiersz+1, kolumna, suma+t[wiersz][kolumna]);
        }
    }
}
int main()
{
    int t[8][8], kolumna;
    cin >>kolumna;

    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            t[i][j]=rand()%100+1;
            mini+=t[i][j];
        }

    minimalnyKoszt(t, 0, kolumna, 0);
    cout<<mini;

    return 0;
}
