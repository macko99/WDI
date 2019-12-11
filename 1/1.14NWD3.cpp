#include <iostream>
using namespace std;
int najmniejszy(int a, int b, int c)
{
    if(a<b && a<c)
        return a;
    if(b<c && b<a)
        return b;

     return c;
}
int NWD3 (int a, int b, int c)
{
    for(int i=najmniejszy(a,b,c); i>=1; i--)
    {
        if(a%i==0 && b%i==0 && c%i==0)
            return i;
    }
}
int main()
{
   int a,b,c;
   cin >>a>>b>>c;

   cout<<NWD3(a,b,c);
    return 0;
}

