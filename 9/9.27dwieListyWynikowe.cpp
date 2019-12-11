#include<iostream>
using namespace std;
struct node
{
    int val;
    node* next;
};
void wypisz (node *p){
    while(p!=nullptr)
    {
        cout<<p->val <<" ";
        p=p->next;
    }
}
void addLast(node *&head, int val)
{
    node *tmp = new node;
    tmp->val=val;
    tmp->next=nullptr;
    if(head ==  nullptr)
        head=tmp;
    else
    {
        node *p = head;
        while(p->next!= nullptr)
            p=p->next;
        p->next=tmp;
    }
}
void delFirst (node *&head)
{
    if(head!= nullptr)
    {
        node *p = head;
        head = head->next;
        delete p;
    }
}
void addFirst(node *&head, int val)
{
    node *p = new node;
    p->val = val;
    p->next = head;
    head = p;
}
int rozdziel (node *&first, node *&wynik1, node *&wynik2)
{
    int licznik = 0;
    while(first != nullptr)
    {
        if((first->val)>0 && (first->val)%2==0)
        {
            addFirst(wynik1, first->val);
            delFirst(first);
        }
        else if((first->val)<0 && (first->val)%2==-1)
        {
            addFirst(wynik2, first->val);
            delFirst(first);
        }
        else
        {
            delFirst(first);
            licznik++;
        }
    }
    return licznik;
}
int main()
{
    node *first = nullptr;
    node *wynik1 = nullptr;
    node *wynik2 = nullptr;
    addLast(first, 8);addLast(first, 4);addLast(first, 3);addLast(first, -3);addLast(first, -1);addLast(first, -5);
    wypisz(first);
    cout<<endl<<rozdziel(first, wynik1, wynik2);
    cout<<endl; wypisz(wynik2); cout<<endl; wypisz(wynik1);
    return 0;
}
