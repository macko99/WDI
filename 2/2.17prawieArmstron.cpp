#include <iostream>
#include <math.h>
using namespace std;
int ileliczb (int n)
{
    int i=0;
    while (n != 0)
    {
        n=n/10;
        i++;
    }
    return i;
}
int suma (int n, int i)
{
    int suma=0;
    while (n != 0)
    {
        suma+=pow((n%10),i);
        n=n/10;
    }
    return suma;
}
int main ()
{
    int n;
    cin >>n;
    for(int i=pow(10,n-1); i<pow(10,n); i++)
    {
        if(suma(i, ileliczb(i))==i)
            cout<<i<<endl;
    }
    return 0;
}

