#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
    int x, suma=0, n=0;
    cin >>x;

    for(int i=1; suma<=x; i+=2)
    {
        suma+=i;
        n++;
    }

    cout <<n-1;
    return 0;
}

