#include <iostream>
using namespace std;
const int N=6;
int mini;
void czyDobraSuma (int t[N], int sumaEl, int sumaInd, int n, int p)
{
    if(n==1)
    {
        for(int i=p; i<N; i++)
            if(sumaEl+t[i]==sumaInd+i)
               // if(sumaEl+t[i]<mini) //jezeli dodatkowo najmiejsza suma
                    mini=sumaEl+t[i];
    }
    else
    {
        for(int i=p; i<N; i++)
            czyDobraSuma(t, sumaEl+t[i], sumaInd+i, n-1, i+1);
    }
}
int main()
{
    int t[N]={1,7,3,5,11,2}, suma=0;

    for(int i=0; i<N; i++)
        suma+=t[i];
    mini=suma+1;

    for(int i=1; i<=N; i++)
    {
        czyDobraSuma(t, 0, 0, i, 0);
        if(mini!=suma+1)
        {
            cout<<mini;
            break;
        }
    }
    return 0;
}
