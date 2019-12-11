#include<iostream>
#define MAX 460000
using namespace std;
void silnia (int n)
{
    int cyfry[MAX], k;
    for (int i=0; i<MAX; i++)
        cyfry[i]=0;

    cyfry[MAX-1]=1;

    for (int i=2; i<=n; i++)
    {
        for (int j=MAX-1; j>=0; j--)
            cyfry[j]*=i;

        for (int j=MAX-1; j>0; j--)
        {
            cyfry[j-1]+=cyfry[j]/10;
            cyfry[j]%=10;
        }
    }

    for ( k=0; k<MAX; k++)
        if(cyfry[k]!=0)
            break;
    for ( k; k<MAX; k++)
          cout <<cyfry[k];
}
int main()
{
    int n;
    cin >>n;
    silnia(n);
    return 0;
}
