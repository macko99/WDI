#include<iostream>
#include<math.h>
using namespace std;
bool czyTak (int c)
{
    int a=2, temp=0;
    while(a<=c)
    {
        for(int i=1; a*i<=c; i++){
            if (c==a*i){
                return true;
            }
        }
        a=3*a+1;
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
