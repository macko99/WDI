#include <iostream>
#include <string>
using namespace std;
const int N=8;
bool czyPierwsza(string liczba)
{
    int tmp=0;
    for(int i=0; i<liczba.length(); i++)
        tmp=(tmp*2)+liczba[i]-'0';

    if(tmp==0 || tmp==1) return false;
    for(int i=2; i*i<=tmp; i++)
        if(tmp%i==0)
            return false;
    return true;
}
bool czySieDa (int t[N], int p, string liczba)
{
    liczba+=t[p]+'0';

    if(p==N-1 && czyPierwsza(liczba)==true)
        return true;
    if(p==N-1 || liczba.length()>30)
        return false;
    else
        if((czyPierwsza(liczba)==true && czySieDa(t, p+1, "")==true) || czySieDa(t, p+1, liczba)==true)
            return true;

    return false;
}
int main()
{
    int t[N]={1,0,0,0,0,1,1,0};
    cout<<czySieDa(t, 0, "");
    return 0;
}
