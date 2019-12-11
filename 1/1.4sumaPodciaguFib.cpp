#include<iostream>
#include<math.h>
using namespace std;
bool czyMozeByc(int liczba)
{
    int suma=0, a=0, b=1, tempa, tempb;

    while (b<liczba)
    {
        tempa=a;
        tempb=b;
        while (tempb<liczba)
        {
            suma+=tempb;
            if (suma==liczba)
                return true;
            tempb+=tempa;
            tempa=tempb-tempa;
        }
        suma=0;
        b+=a;
        a=b-a;
    }
    return false;
}
int main()
{
    int liczba;
    cin >>liczba;

    cout<<czyMozeByc(liczba);
    return 0;
}
