#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a, tab[11];

    for (int i=0; i<=10; i++)
        tab[i]=0;

    while(1)
    {
        cin >>a;
        if(a==0)
            break;

        tab[10]=a;
        for (int i=9; i>=0; i--)
            if(tab[i+1]>tab[i])
                swap(tab[i+1], tab[i]);
    }
    cout <<tab[9];
    return 0;
}
