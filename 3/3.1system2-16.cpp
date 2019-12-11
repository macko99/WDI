#include <iostream>
using namespace std;
void zmiana (int n, int system)
{
    string liczba="";
    while (n>0)
    {
        if(n%system==10)
            liczba="A"+liczba;
        if(n%system==11)
            liczba="B"+liczba;
        if(n%system==12)
            liczba="C"+liczba;
        if(n%system==13)
            liczba="D"+liczba;
        if(n%system==14)
            liczba="E"+liczba;
        if(n%system==15)
            liczba="F"+liczba;
        if(n%system<10)
        {
            char temp=n%system+'0';
            liczba=temp+liczba;
        }
        n=n/system;
    }
    cout<<liczba;
}
int main()
{
    int n, system;
    cin >>n >>system;

    zmiana(n, system);

    return 0;
}
