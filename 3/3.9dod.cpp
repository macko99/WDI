#include<iostream>
#include <cstdlib>
#define MAX 100
using namespace std;
bool czyPierwsza(int n)
{
    if (n%2==0 && n>2)
        return false;
    for (int i=3; i*i<=n; i++)
        if (n%i==0)
            return false;
    return true;
}

int main()
{
    int tabela[MAX];
    bool check[MAX];

    for (int i=0; i<MAX; i++)
    {
        check[i]=0;
        tabela[i]=rand()%10+1;
    }

    for (int i=0; i<MAX-1; i++)
        for (int j=2; j<=tabela[i]; j++)
            if(tabela[i]%j==0 && czyPierwsza(j)==true && i+j<MAX)
                check[i+j]=true;

    if(check[MAX-1]==true)
        cout <<"TAK";
    else
        cout <<"NIE";

    return 0;
}
