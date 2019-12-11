#include <iostream>
using namespace std;
int najwiekszy(int a, int b, int c)
{
    if(a>b && a>c)
        return a;
    if(b>c && b>a)
        return b;

     return c;
}
int nww3 (int a, int b, int c)
{
    for(int i=najwiekszy(a,b,c);; i++)
    {
        if(i%a==0 && i%b==0 && i%c==0)
            return i;
    }
}
int main()
{
   int a,b,c;
   cin >>a>>b>>c;

   cout<<nww3(a,b,c);
    return 0;
}

