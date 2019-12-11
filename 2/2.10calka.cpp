#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float koniec, n, calka, x, dx;
    cout <<"enter"<<endl;
    cin >>koniec;
    n=koniec*1000;
    dx=(koniec-1)/n;

    for (int i=1; i<=n; i++)
    {
        x=1+i/n*(koniec-1);
        calka+=(1/x);
    }
    cout <<calka*dx;
    return 0;
}
