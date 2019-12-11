#include <iostream>
using namespace std;
int ilecyfr(int n)
{
    int i=0;
    while(n>0)
    {
        i++;
        n/=10;
    }
    return i;
}
bool czyJest(int n, int a )
{
    while(n>0)
    {
        if(n%10==a) return true;
        n/=10;
    }
    return false;
}
int main()
{
    int n;
    cin >>n;

    cout<<czyJest(n,ilecyfr(n));
    return 0;
}
