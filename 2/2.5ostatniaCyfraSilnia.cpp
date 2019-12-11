#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    unsigned long long n, x=1;
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        x*=i;
        while(x%10==0)
            x/=10;
        x%=1000000;
    }
        cout<<"ostatnia cyfra "<<x%10;
    return 0;
}
