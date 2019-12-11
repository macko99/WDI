#include<iostream>
using namespace std;
const int N=7;
bool opor(int score[3], int suma)
{
    if(score[0]+score[1]+score[2]==suma)
        return true;
    if((score[0]*score[1]*score[2])/(score[1]*score[2]+score[1]*score[0]+score[0]*score[2])==suma)
        return true;
    if((score[0]*score[1])/(score[0]+score[1])+score[2]==suma)
        return true;
    if((score[0]*score[2])/(score[0]+score[2])+score[1]==suma)
        return true;
    if((score[2]*score[1])/(score[2]+score[1])+score[0]==suma)
        return true;
    return false;
}
bool trojKi (int suma, int t[N], int wziete[N], int moc, int p, int m, int n)
{
    wziete[m]=n;
    if(moc==3)
        {
            cout<<".";
            int score[3], j=0;
            for(int i=0; i<N; i++)
                if(wziete[i]==1)
                    score[j++]=t[i];
            if(opor(score, suma))
                return true;
            return false;
        }
        for(int i=p; i<N; i++)
            if(trojKi(suma, t, wziete, moc+1,  i+1, i, 1) || trojKi(suma, t, wziete, moc, i+1, i, 0))
                return true;
    return false;
}
int main()
{
    int t[N], wziete[N], suma, a=1;
    for(int i=0; i<N; i++)
    {
       t[i]=a++;
       wziete[i]=0;
    }
    cin>>suma;
    cout<<trojKi(suma, t, wziete, 0, 0, 0, 0);
    return 0;
}

