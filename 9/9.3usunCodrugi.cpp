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
void usunCo2 (node *&head)
{
    if(head==nullptr)
        return;
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    node *tmp = head;
    head=head->next;
    delete tmp;
    node *p = head;
    while( p!=nullptr && p->next!= nullptr)
    {
        tmp = p->next;
        p->next=p->next->next;
        delete tmp;
        p=p->next;
    }
}
int main()
{
    node *first =nullptr;
    for(int i=1; i<=11; i++)
        addLast(first, i);
    usunCo2(first);
    wypisz(first);
    return 0;
}
