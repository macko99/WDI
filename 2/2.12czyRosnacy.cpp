#include <iostream>
using namespace std;
bool czyRosnie (int n)
{
    while(n>0)
    {
        int temp=n%10;
        n/=10;
        if(temp<=n%10) return false;
        if(n%10==0) return false;
    }
    return true;
}
int main()
{
    int n;
    cin >>n;
cout<<czyRosnie(n);
    return 0;
}
