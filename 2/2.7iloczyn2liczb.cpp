#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,liczba=1;
    cin>>n;
    int roznica=n-1;

    for (int i=1; i*i<=n; i++)
        if(n%i==0)
            if(abs(i-(n/i))<roznica)
                liczba=i;

    cout <<liczba <<" "<<n/liczba;
    return 0;
}
