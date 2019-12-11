#include<iostream>
#include<math.h>
using namespace std;
bool czyLiczbaFib(int c)
{
    int a=1, b=2;
    for(int i=0; i<=sqrt(c); i++)
    {
        if(c==b) return true;
        b+=a;
        a=b-a;
    }
    return false;
}
int main()
{
    int n, a=1, b=2;
    bool c=0;
    cin >>n;
    for(int i=0; i<=sqrt(n); i++)
    {
        if(n%b==0 && czyLiczbaFib((n/b)))
        {
            cout <<"jest " <<b<<" * "<<n/b;
            c=1;
            break;
        }
        b+=a;
        a=b-a;
    }
    if(c==false)
        cout <<"nie jest";
    return 0;
}
