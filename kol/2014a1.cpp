#include<iostream>
#include<algorithm>
using namespace std;
const int N=200;
int miniOdl(int x, int y)
{
    int licznik=0;

    while(x!=100 || y!=100)
    {
    if(x==100 && y>100){
        licznik+=y-100;
        return licznik;}
    if(x==100 && y<100){
        licznik+=100-y;
        return licznik;}
    if(x>100 && y==100){
        licznik+=x-100;
        return licznik;}
    if(x<100 && y==100){
        licznik+=100-x;
        return licznik;}
    if(x>100 && y>100)
    {
        licznik++;
        x-=1;
        y-=1;
    }
    if(x<100 && y<100)
    {
        licznik++;
        x+=1;
        y+=1;
    }
    if(x>100 && y<100)
    {
        licznik++;
        x-=1;
        y+=1;
    }
    if(x<100 && y>100)
    {
        licznik++;
        x+=1;
        y-=1;
    }
    }
    return licznik;
}
void odleglosc(int tab[N])
{
    int kopia[100], a=0;
    for(int i=0; i<N; i+=2)
        kopia[a++]=miniOdl(tab[i], tab[i+1]);

    for(int i=0; i<100; i++){
        for(int j=i+1; j<99; j++){
            if(kopia[i]==kopia[j]){
                cout<<tab[i*2]<<", "<<tab[(i*2)+1]<<" i "<<tab[j*2]<<", "<<tab[(j*2)+1]<<endl;}}}
}
int main ()
{
    int krole[N];
    for(int i=0; i<N; i++)
            krole[i]=rand()%200+1;
    odleglosc(krole);
    return 0;
}
