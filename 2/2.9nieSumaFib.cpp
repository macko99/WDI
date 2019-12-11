#include<iostream>
#include<math.h>
using namespace std;
bool czyMozeByc(int liczba)
{
    int suma=0, a=0, b=1, tempa=0, tempb=0;
    for (int i=1; b<liczba; i++)
    {
        tempa=a;
        tempb=b;
        for (int j=1; b<liczba; j++)
        {
            suma+=b;
            if (suma==liczba)
                return false;
            b+=a;
            a=b-a;
        }
        suma=0;
        a=tempa;
        b=tempb;
        b+=a;
        a=b-a;
    }
    return true;
}
int main()
{
    int n=0;
    cout <<"enter"<<endl;
    cin >>n;
    while(1)
    {
        n++;
        if(czyMozeByc(n))
        {
            cout <<n;
            break;
        }
    }
    return 0;
}
