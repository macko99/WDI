#include<iostream>
#include<math.h>
using namespace std;
bool czyTak (int c)
{
    int a=0, temp=0;
    for (int i=1; a<=c; i++)
    {
        a=i*i+i+1;
        for(int j=1; a*j<=c; j++)
            if (c==a*j)
                return true;
    }
    return false;
}
int main()
{
start:
    int n;
    cin >>n;
    if(czyTak(n))
        cout <<"jest";
    else
        cout <<"nie";
    goto start;
    return 0;
}
