#include <iostream>
using namespace std;
int suma(int n)
{
    int sum=0;

   for(int i=1; i<n; i++)
   {
       if(n%i==0)
        sum+=i;
   }
   return sum;
}
int main()
{
   for(int i=1; i<=1000000; i++)
   {
       if(suma(i)==i)
        cout<<i<<" ";
   }
    return 0;
}


