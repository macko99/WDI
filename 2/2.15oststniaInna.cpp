#include <iostream>
using namespace std;
int ostatnia(int n)
{
    return n%10;
}
bool czyJest(int n, int a )
{
    n/=10;
    while(n>0)
    {
        if(n%10==a) return false;
        n/=10;
    }
    return true;
}
int main()
{
    int n;
    cin >>n;

    cout<<czyJest(n,ostatnia(n));
    return 0;
}
