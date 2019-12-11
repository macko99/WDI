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
void del (node *&head, int k)
{
    node *p = head;
    while(p->next != nullptr)
    {
        if(p->val == k)
        {
            head=head->next;
            delete p;
            return;
        }
        if(p->next->val == k)
        {
            if(p->next->next == nullptr)
            {
                delete p->next;
                p->next=nullptr;
                return;
            }
            node *tmp=p->next;
            p->next=tmp->next;
            delete tmp;
            return;
        }
        p=p->next;
    }
    p= new node;
    p->val=k;
    p->next=head;
    head=p;
}
int main()
{
    node *first =nullptr;
    for(int i=1; i<=10; i++)
        addLast(first, i);
    wypisz(first);
    del(first, 3);
    del(first, 15);
    cout<<endl; wypisz(first);
    return 0;
}
