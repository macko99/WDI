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
    int piatki=0;
    while(a!=0)
    {
        if(a%8==5) piatki++;
        a/=8;
    }
    if(piatki>0 && piatki%2==0) return true;
    return false;
}
void usun (node *&head)
{
    if(head==nullptr || head->next == nullptr)
        return;
    node *tmp = head, *tmp2 = head;
    while(tmp2->next != nullptr)
    {
        if(usunac(tmp->val))
        {
            if(tmp != tmp2)
            {
                tmp2->next=tmp->next;
                tmp->next=head;
                head=tmp;
                tmp=tmp2->next;
            }
        }
        else
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
    }
}
int main()
{
    node *first =nullptr;
    addLast(first, 2);addLast(first, 45);addLast(first, 365);addLast(first, 12);addLast(first, 173);
    usun(first);
    wypisz(first);
    return 0;
}
