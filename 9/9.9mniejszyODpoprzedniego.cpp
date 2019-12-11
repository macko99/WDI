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
void usun (node *&head)
{
    if(head==nullptr || head->next == nullptr)
        return;
    node *tmp = head;
    while(tmp->next != nullptr)
    {
        if(tmp->next->val < tmp->val)
        {
            node*pomoc = tmp->next;
            tmp->next=pomoc->next;
            delete pomoc;
        }
        else if(tmp->next != nullptr)
            tmp=tmp->next;
    }
}
int main()
{
    node *first =nullptr;
    addLast(first, 8);addLast(first, 7);addLast(first, 6);addLast(first, 7);addLast(first, 8);addLast(first, 10);addLast(first, 2);
    usun(first);
    wypisz(first);
    return 0;
}
