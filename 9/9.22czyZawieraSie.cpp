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
bool usun (node *&head, int k)
{
    if(head==nullptr)
        return false;
    node *p = head;
    if(head->val == k)
        {
            head=head->next;
            delete p;
            return true;
        }
    while(p->next != nullptr)
    {
        if(p->next->val == k)
        {
            if(p->next->next == nullptr)
            {
                delete p->next;
                p->next=nullptr;
                return true;
            }
            node *tmp=p->next;
            p->next=tmp->next;
            delete tmp;
            return true;
        }
        p=p->next;
    }
    return false;
}
bool zawiera (node *head1, node *head2)
{
    while(head1 != nullptr)
    {
        if(usun(head2, (head1->val))==false)
            return false;
        head1=head1->next;
    }
    return true;
}
int main()
{
    node *first =nullptr;
    node *first2 = nullptr;
    addLast(first, 8);addLast(first, 7);addLast(first, 4);addLast(first, 5);addLast(first, 5);
    addLast(first2, 2);addLast(first2, 7);addLast(first2, 5);addLast(first2, 4);addLast(first2, 8);addLast(first2, 1);addLast(first2, 5);

    wypisz(first);cout<<endl; wypisz(first2); cout<<endl<<zawiera(first, first2);
    return 0;
}
