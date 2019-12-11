#include <iostream>
using namespace std;
const int N=8;
bool warunki(int i, int k){
    if(k==0)
        if (i != k && i != k + 1)
            return true;
    if(k==N-1)
        if (1 != k && i != k - 1)
            return true;
    if(i!=k && i!=k+1 && i!=k-1)
        return true;
    return false;
}
bool wieze(int t[N][N], int suma, int p, int k){
    if(p==N) {
        if (suma == 0)
            return true;
        return false;
    }
    for(int i=0; i<N; i++){
        if(warunki(i, k))
            if(wieze(t, suma+t[p][i], p+1, i))
                return true;
    }
    return false;
}
bool czy(int t[N][N]){
    for(int i=0; i<N; i++)
        if(wieze(t, 0, 0, i))
            return true;
    return false;
}
int main(){
    int t[N][N], a=-32;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            t[i][j]=a++;
    cout<<czy(t);
    return 0;
}
