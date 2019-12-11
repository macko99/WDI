#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, b, check[10];
    bool flaga=1;
    cin >>a >>b;
    int lenA=log10(a)+1;

    for (int i=0; i<10; i++)
        check[i]=0;

    for (int i=0; i<lenA; i++)
    {
        check[a%10]+=1;
        check[b%10]-=1;
        a/=10;
        b/=10;
    }


    for (int i=0; i<10; i++)
        if(check[i]!=0)
            flaga=0;

    if(flaga) cout <<"TAK";
    else cout <<"NIE";

    return 0;
}
