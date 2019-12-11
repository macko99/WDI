#include<iostream>
#include<math.h>
using namespace std;
bool czyPierwsza(int a)
{
    if(a==1) return false;
    for(int i=2; i*i<=a; i++)
        if(a%i==0) return false;
    return true;
}
bool czySmitha (int c)
{
    int a=c+1, tab[a], suma1=0, suma2=0;
    for(int i=0; i<a; i++)
        tab[i]=0;

    for(int i=2; i<=a; i++)
    {
        while(c%i==0)
        {
            c/=i;
            tab[i]+=1;
        }
    }

    for(int i=0; i<a; i++)
    {
        int j=i;
        for(int k=0; k<tab[i]; k++)
        {
          while(j>0)
            {
            suma1+=j%10;
            j/=10;
            }
            j=i;
        }
    }

    c=a-1;
    while(c>0)
    {
        suma2+=c%10;
        c/=10;
    }
    if(suma1==suma2) return true;
    return false;
}
int main()
{
    for(int i=1 ;i<1000000; i++)
    {
        if(czySmitha(i) && !czyPierwsza(i))
            cout<<i<<endl;
    }
    return 0;
}
