#include<iostream>
using namespace std;
bool licz2(int a)
{
    if(a-a%10!=0) return true;
    return false;
}
int dzialA(int a)
{
    int tmp=a%10;
    a/=10;
    int tmp2=a%10;
    a/=10;
    return (a*10+tmp)*10+tmp2;
}
int dzialC (int a)
{
    int level=1, tmp=a;
    while(tmp>0)
    {
        tmp/=10;
        level*=10;
    }
    return a%(level/10);
}
bool operacje(int x, int y, string kod, int p)
{
    if(x==y)
    {
        cout<<kod;
        return true;
    }
    if(p>2)
        p=0;
    for(int i=p; i<3; i++)
    {
        switch(i)
        {
            case 1:
                if(operacje(x*3, y, kod+"B",  i+1))
                    return true;
            case 2:
                if(licz2(x))
                    if(operacje(dzialC(x), y, kod+"C",i+1))
                        return true;
            case 3:
                if(licz2(x))
                    if(operacje(dzialA(x), y, kod+"A",i+1))
                        return true;
        }
    }
    return false;
}
int main()
{
    int x, y;
    cin >>x>>y;
    operacje(x,y,"",0);
    return 0;
}
