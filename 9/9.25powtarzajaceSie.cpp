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
bool jest(node *&head, int k)
{
    node *p=head;
    while(p!= nullptr)
    {
        if(p->val == k)
            return true;
        p=p->next;
    }
    return false;
}
void usun (node *&head, int k)
{
    node *p = head;
    if(head->val == k)
        {
            head=head->next;
            delete p;
            return;
        }
    while(p->next != nullptr && p->val <= k)
    {
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
}
int OnlySame (node *&head1, node *&head2)
{
    int licznik =0;
    node *tmp= head1, *tmp2 = head1;
    while (tmp != nullptr)
    {
        if(jest(head2, tmp->val)== false)
        {
            usun(head2, tmp->val);
            licznik++;
            if(tmp==tmp2)
            {
               head2=tmp->next;
               delete tmp;
               tmp=head2;
               tmp2=head2;
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
    return licznik;
}
int main()
{
    node *first =nullptr;
    node *first2 = nullptr;
    addLast(first, 1);addLast(first, 2);addLast(first, 3);addLast(first, 4);addLast(first, 5);addLast(first, 6);addLast(first, 7);addLast(first, 8);
    addLast(first2, 1);addLast(first2, 3);addLast(first2, 4);addLast(first2, 6);addLast(first2, 8);addLast(first2, 13);
    wypisz(first);cout<<endl; wypisz(first2);cout<<endl;
    cout<<OnlySame(first, first2)+OnlySame(first2, first);
    return 0;
}
