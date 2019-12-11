#include <iostream>
#include<math.h>
using namespace std;
const int N=2;
struct punkt { double x,y,z; };
punkt t[N];
double mini=100.0;
double odleglosc (double x, double y, double z, double moc, double a, double b, double c, double moc2)
{
    return sqrt(pow(x/moc-a/moc2,2)+pow(y/moc-b/moc2,2)+pow(z/moc-c/moc2,2));
}
bool balance(int i, double x, double y, double z, double a, double b, double c, double moc, double moc2)
{
    if(moc>0 && moc2>0 && odleglosc(x,y,z,moc,a,b,c,moc2)<mini)
        mini=odleglosc(x,y,z,moc,a,b,c,moc2);
    if(i==N)
        return false;
    if(balance(i+1,x+t[i].x,y+t[i].y,z+t[i].z,a,b,c,moc+1,moc2) || balance(i+1,x,y,z,a,b,c,moc,moc2) || balance(i+1,x,y,z,a+t[i].x,b+t[i].y,c+t[i].z,moc,moc2+1))
        return true;
}
int main()
{
    t[0].x=2;
    t[0].y=2;
    t[0].z=2;
    t[1].x=1;
    t[1].y=1;
    t[1].z=1;
    balance(0, 0, 0, 0, 0, 0, 0, 0, 0);
    cout<<mini;
    return 0;
}
