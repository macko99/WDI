#include<iostream>
using namespace std;
const int N=4;
bool dziel(int t[N], int i, int suma, int moc1, int moc2)
{
    if(moc1==moc2 && moc1!=0 && suma==0)
        return true;
    if(i<N)
    {
        if(dziel(t, i+1, suma+t[i], moc1+1, moc2) || dziel(t, i+1, suma-t[i], moc1, moc2+1) || dziel(t, i+1, suma, moc1, moc2))
            return true;
    }
    return false;
}
int main()
{
    int t[N]={0,2,3,4};
    cout<<dziel(t, 0, 0, 0, 0);
    return 0;
}
