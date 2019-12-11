#include <iostream>
using namespace std;
bool roznoCyfrowe(string n, string n2)
{
    for(int i=0; i<n.size(); i++)
    {
        for(int j=0; j<n2.size(); j++)
            if(n[i]==n2[j]) return false;
        }
        return true;
}
string zmiana (int n, int system)
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
    return liczba;
}
int main()
{
    int n, n2;
    cin >>n >>n2;
    bool koniec=false;
    for(int i=2; i<=16 ; i++)
    {
        if(roznoCyfrowe(zmiana(n, i),zmiana(n2, i)))
        {
            cout<<i<<endl;
            koniec=true;
            break;
        }

    }
        if(!koniec)
            cout<<"nie ma";

    return 0;
}
