#include<iostream>
#include<math.h>
using namespace std;
bool czyRosnie(string ciag)
{
    for (int i=0; i<ciag.size()-1; i++)
    {
        if((ciag[i]-'0')>=(ciag[i+1]-'0'))
            return false;
    }
    return true;
}
string naString (int c)
{
    string liczba="";
    while(c>0)
    {
        char temp=c%10+'0';
        liczba=temp+liczba;
        c/=10;
    }
    return liczba;
}
bool czyDigOk (string liczba, string xsiedem)
{
    int count=0;
    string ciag="";

    for (int i=0; i<xsiedem.size(); i++)
        for(int j=0; j<liczba.size(); j++)
            if (xsiedem[i] == liczba[j])
            {
                count++;
                ciag+=j;
            }

    if(count==xsiedem.size() && czyRosnie(ciag)) return true;
    else return false;
}
int main()
{
    int a=0, ile=0;
    cout <<"enter"<<endl;
    cin >>a;

    for(int i=7; i<=a; i+=7)
    {
        if(czyDigOk(naString(a), naString(i)))
            ile++;
    }
    cout <<ile;
    return 0;
}
