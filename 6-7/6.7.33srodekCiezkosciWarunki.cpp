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
bool balance(int i, double x, double y, double z, double moc, double R, double ogr)
{
    if(odleglosc(x,y,z,moc)<R && moc==ogr)
        return true;
    if(i==N)
        return false;
    if(balance(i+1, x+t[i].x, y+t[i].y, z+t[i].z, moc+1, R, ogr) || balance(i+1, x, y, z, moc, R, ogr))
        return true;
    return false;
}
bool balanceMaster(double R, int k)
{
    for(int i=3; i<k; i+=3)
        if(balance(0, 0, 0, 0, 0, R, i))
            return true;
    return false;
}
int main()
{
    double R;
    int k;
    cin >>R>>k;
    cout<<balanceMaster(R, k);
    return 0;
}

