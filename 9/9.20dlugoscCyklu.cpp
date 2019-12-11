#include<iostream>
using namespace std;
struct node
{
    int val;
    node* next;
};
void wypisz (node *p)
{
    node *tmp = p;
    do
    {
        cout<<p->val <<" ";
        p=p->next;
    }while(p!=tmp);
}
void addLast(node *&head, int val)
{
    node *tmp = new node;
    tmp->val=val;
    if(head == nullptr)
    {
        tmp->next=tmp;
        head=tmp;
    }
    else
    {
        node* p = head;
        while(p->next != head)
            p=p->next;
        p->next=tmp;
        tmp->next=head;
    }
}
int LenCyklu (node *head)
{
    int licz=0;
    node *tmp = head;
    do
    {
        licz++;
        tmp=tmp->next;
    }while(tmp != head);
    cout<<endl<<licz;
}
int main()
{
    node *first = nullptr;
    for(int i=1; i<9; i++)
        addLast(first, i);

    wypisz(first); LenCyklu(first);
    return 0;
}
