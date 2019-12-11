#include <iostream>>
using namespace std;
const int N=10;
int czyJestCykl(int t[N][N])
{
    int licz=0;
    for(int dlug=3; dlug<=N/2; dlug++)
    {
        for(int i=0; i<N; i++)
        {
            int licz=0;
            for(int k=0; k<N; k++)
                if(t[i][k]==t[i][k%dlug])
                    licz++;
            if(licz==N)
                return i;
        }
    }
    return -1;
}
int main()
{
    int t[N][N], a=1;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            t[i][j]=a++;
    for(int j=0; j<N; j++)
            t[3][j]=1;
    cout<<czyJestCykl(t);
    return 0;
}
