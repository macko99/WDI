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
    node *tmp = head, *tmp2 = head;
    while(tmp->next != nullptr)
    {
        if((tmp->next->val)%(tmp->val) == 0)
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
        else if(tmp->next != nullptr)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
    }
}
int main()
{
    node *first =nullptr;
    addLast(first, 2);addLast(first, 4);addLast(first, 8);addLast(first, 5);addLast(first, 7);addLast(first, 6);addLast(first, 12);addLast(first, 7);
    usun(first);
    wypisz(first);
    return 0;
}
