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
int delFirst (node *&head)
{
    node *p = head;
    int tmp=p->val;
    delete p;
    head = head->next;
    return tmp;
}
void addFirst(node *&head, int val)
{
    node *p = new node;
    p->val = val;
    p->next = head;
    head = p;
}
void revers(node *&head)
{
    node *nowy = nullptr;
    while(head!=nullptr)
        addFirst(nowy, delFirst(head));
    head=nowy;
}
int main()
{
    node *first =nullptr;
    for(int i=1; i<=10; i++)
        addLast(first, i);

    wypisz(first);
    revers(first);
    cout<<endl; wypisz(first);
    return 0;
}
