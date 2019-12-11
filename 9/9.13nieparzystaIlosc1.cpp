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
bool usunac(int a)
{
    int jedynki=0;
    while(a!=0)
    {
        if(a%2==1) jedynki++;
        a/=2;
    }
    if(jedynki%2==1) return true;
    return false;
}
void usun (node *&head)
{
    if(head==nullptr)
        return;
    node *tmp = head, *tmp2 = head;
    while(tmp2->next != nullptr)
    {
        if(usunac(tmp->val))
        {
            if(tmp == tmp2)
            {
                head=tmp->next;
                delete tmp;
                tmp=head;
                tmp2=head;
            }
            else
            {
                tmp2->next=tmp->next;
                delete tmp;
                tmp=tmp2->next;
            }
        }
        else
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
    }
    if(head->next == nullptr)
    {
        if(usunac(head->val))
        {
            node*tmp = head;
            head=nullptr;
            delete tmp;
        }
    }
}
int main()
{
    node *first =nullptr;
    addLast(first, 2);addLast(first, 4);addLast(first, 6);addLast(first, 5);addLast(first, 7);addLast(first, 6);addLast(first, 12);
    usun(first);
    wypisz(first);
    return 0;
}
