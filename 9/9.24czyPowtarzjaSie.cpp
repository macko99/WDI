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
    while(p->next != nullptr && p->val <= k)
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
int teSame (node *&head1, node *&head2)
{
    int licznik=0;
    node *tmp = head2, *tmp2 = head2;
    while(tmp != nullptr)
    {
        if(usun(head1, (tmp->val))==true)
        {
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
    addLast(first2, 2);addLast(first2, 6);addLast(first2, 3);addLast(first2, 1);addLast(first2, 13);addLast(first2, 8);

    wypisz(first);cout<<endl; wypisz(first2); cout<<endl<<teSame(first, first2);
    return 0;
}
