#include <iostream>
using namespace std;
bool wzgledniePierwsze(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    if(a==1) return true;
    return false;
}
int maxPodciag(int tab[], int MAX)
{
    int licznik=1, maxLicznik=0;

    for(int i=0; i<MAX; i++)
    {
        for(int j=i; j<MAX-1; j++)
        {
            if(wzgledniePierwsze(tab[j], tab[j+1]))
                licznik++;
            else
                break;
        }
        if(licznik>maxLicznik)
            maxLicznik=licznik;

        licznik=1;
    }
    return maxLicznik;
}
int main()
{
    const int MAX=10;
    int tab[MAX], a=1;

    for(int i=0; i<MAX; i++)
    {
         tab[i]=a;
        a++;
    }
    tab[4]=8;

    cout<<maxPodciag(tab, MAX);
    return 0;
}
