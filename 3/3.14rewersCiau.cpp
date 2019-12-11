#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
    const int MAX=15;
    int tab[MAX]={2,2,4,3,3,1,5,7,9,1,3,3,4,9,0}, temp, licz=0, maks=1;

    for (int i=0; i<MAX; i++)
    {
        temp=i;
      for (int j=MAX-1; j>=i; j--)
        {
            if(tab[j]==tab[temp])
            {
                licz++;
                temp++;
                if(licz>maks)
                    maks=licz;
            }
            else
            {
                licz=0;
            }
         }
      }

    cout <<maks;
    return 0;
}
