#include <iostream>
#define M 20
using namespace std;

void uzupelnij (int a1, int a2, int b1, int b2, int &licz, int (&tab)[M][M] )
{
    licz-=1;
    for (int i = a1; i <= b1; i++)
        for (int j = a2; j <= b2; j++)
            tab[i][j] = licz++;
}
void uzup2 (int a1, int a2, int b1, int b2, int &licz, int (&tab)[M][M] )
{
    licz-=1;
    for (int i = a1; i >= b1; i--)
        for (int j = a2; j >= b2; j--)
            tab[i][j] = licz++;
}

int main()
{
    int tab[M][M], licz=2;
    int a1=1, a2=0, b1=0, b2=M-1, c1=M-1, c2=M-1, d1=M-1, d2=0;

    uzupelnij(0,0,b1,b2,licz,tab);
    while(licz<=M*M)
    {
        uzupelnij(b1,b2,c1,c2,licz,tab);
        b1+=1; b2-=1;
        uzup2(c1,c2,d1,d2,licz,tab);
        c1-=1; c2-=1;
        uzup2(d1,d2,a1,a2,licz,tab);
        d1-=1; d2+=1;
        uzupelnij(a1,a2,b1,b2,licz,tab);
        a1+=1; a2+=1;
    }

    return 0;
}
