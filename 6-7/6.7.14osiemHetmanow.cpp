#include <iostream>
using namespace std;
int dia_r[17];
int dia_l[17];
int col[8];
int chart[8][8];
int a=1;
void wypisz(int chart[8][8])
{
    cout<<"numer: "<<a++<<endl;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(chart[i][j])
                cout<<"| H |";
            else
                cout<<"|   |";
        }
        cout<<endl<<"________________________________________"<<endl;
    }
    cout<<endl<<endl;
}
void hetmanki (int row)
{
    for (int i=0; i<8; i++)
    {
        if (col[i]==0 && dia_r[i-row+8]==0  && dia_l[row+i+8]==0)
        {
            dia_r[i-row+8] = 1;
            dia_l[row+i+8] = 1;
            col[i] = 1;
            chart[i][row] = 1;
            if(row<7)
                hetmanki(row+1);
            else
                wypisz(chart);
            dia_r[i-row+8] = 0;
            dia_l[row+i+8] = 0;
            col[i] = 0;
            chart[i][row] = 0;
        }
    }
}

int main()
{
    for (int i=0; i<17; i++)
    {
        dia_r[i] = 0;
        dia_l[i] = 0;
    }
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            chart[i][j] = 0;
            col[i] = 0;
        }
    }
    hetmanki(0);
    return 0;
}
