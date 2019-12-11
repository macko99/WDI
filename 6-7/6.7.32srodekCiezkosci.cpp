#include <iostream>
#include<math.h>
using namespace std;

const int N=5;
struct punkt { double x,y,z; };
punkt t[N];

double odleglosc (double x, double y, double z, double moc)
{
    return sqrt(pow(x/moc,2)+pow(y/moc,2)+pow(z/moc,2));
}
bool balance(int i, double x, double y, double z, double moc, double R)
{
    if(odleglosc(x,y,z,moc)<R && moc>2)
        return true;
    if(i==N)
        return false;
    if(balance(i+1, x+t[i].x, y+t[i].y, z+t[i].z, moc+1, R) || balance(i+1, x, y, z, moc, R))
        return true;
    return false;
}
int main()
{
    double R;
    cin >>R;
    cout<<balance(0, 0, 0, 0, 0, R);
    return 0;
}

