#include<iostream>
#define MAX 1000
using namespace std;
void euler (int n)
{
    int cyfry[MAX], wynik[MAX];
    for (int i=0; i<MAX; i++)
    {
        cyfry[i]=0;
        wynik[i]=0;
    }

    cyfry[0]=1;
    wynik[0]=1;

    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<MAX; j++)
        {
            cyfry[j+1]+=(cyfry[j]%i)*10;
            cyfry[j]/=i;
            wynik[j]+=cyfry[j];
        }

        for (int j=MAX-1; j>0; j--)
        {
            wynik[j-1]+=wynik[j]/10;
            wynik[j]%=10;
        }
    }

    cout <<wynik[0]<<",";
    for (int k=1; k<MAX; k++)
         cout <<wynik[k];
}
int main()
{
    int n;
    cin >>n;
    euler(n);
    return 0;
}
