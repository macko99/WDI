#include <iostream>
using namespace std;
const int N=2;

void read(int t[N])
{
    for(int i=0; i<N; i++)
        cin>>t[i];
}
bool balance(int i, int suma, int t[N])
{
    if(suma==0)
        return true;
    if(i==N)
        return false;
    if(balance(i+1, suma-t[i], t) || balance(i+1, suma, t) || balance(i+1, suma+t[i], t))
        return true;
    return false;
}
int main()
{
    int t[N], suma;

    read(t);
    cout<<"masa: "<<endl;
    cin>>suma;

    cout<<endl<<balance(0, suma, t);
    return 0;
}
