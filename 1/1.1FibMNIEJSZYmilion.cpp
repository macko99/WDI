#include <iostream>
using namespace std;
int main()
{
    int a=0, b=1;
    while(1)
    {
        if(a>1000000) break;
        cout<<a<<" ";
        b=b+a;
        a=b-a;
    }
    return 0;
}
