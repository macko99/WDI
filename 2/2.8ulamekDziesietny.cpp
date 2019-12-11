#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
    int a, b, tab[100];
    bool okres=false;
    cin >>a >>b;
    for (int i=0; i<100; i++)
       tab[i]=0;

    cout <<a/b<<",";

    for (int i=0; i<100; i++)
    {
        a=(a-(a/b)*b)*10;
        if(a==0) break;
        tab[i]=a/b;
    }
    for (int i=0; i<100; i++)
    {
        for(int j=i; j<99; j++)
        {
            if(tab[j]!=tab[j+1])
            {
                cout<<tab[j];
                okres=false;
            }
             else
                okres=true;
        }
     }
     if(okres==true && tab[99]!=0)
            cout<<"("<<tab[99]<<")";

        return 0;
}

