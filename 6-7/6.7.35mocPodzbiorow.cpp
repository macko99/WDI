#include <iostream>
using namespace std;
const int N=5;
bool balance(int i, int suma, int moc, int t[N])
{
    if(suma==0 && moc==0)
        return true;
    if(i==N)
        return false;
    if(balance(i+1, suma+t[i], moc-1, t) || balance(i+1, suma, moc, t) || balance(i+1, suma-t[i], moc-1, t))
        return true;
    return false;
}
int main()
{
    int t[N]={1,2,3,4,5}, moc;
    cin >>moc;
    cout<<balance(0, 0, moc, t);
    return 0;
}
