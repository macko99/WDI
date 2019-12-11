#include<iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
void wypisz (node *p)
{
    node *tmp = p;
    do
    {
        cout<<p->val <<" ";
        p=p->next;
    }while(p!=tmp);
}
void addLast(node *&head, int val)
{
    node *tmp = new node;
    tmp->val=val;
    if(head == nullptr)
    {
        tmp->next=tmp;
        head=tmp;
    }
    else
    {
        node* p = head;
        while(p->next != head)
            p=p->next;
        p->next=tmp;
        tmp->next=head;
    }
}
bool jest (node *&head, int k)
{
    node *first = head;
    if(head==nullptr)
        return false;
    node *p = head;
    if(head->val == k)
        {
            head=head->next;
            delete p;
            return true;
        }
    while(p->next != first)
    {
        if(p->next->val == k)
        {
            if(p->next->next == first)
            {
                delete p->next;
                p->next=first;
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
int usun (node *&head1, node *&head2)
{
    node *first = head2;
    int licznik=0;
    node *tmp = head2, *tmp2 = head2;
    while(tmp2->next != first)
    {
        if(jest(head1, (tmp->val))==true)
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
    node *head1 = nullptr, *head2 = nullptr;
        addLast(head1, 5);addLast(head1, 22);addLast(head1, 1);addLast(head1, 4);addLast(head1, 91);
        addLast(head2, 5);addLast(head2, 6);addLast(head2, 1);addLast(head2, 91);

    wypisz(head1);cout<<endl; wypisz(head2);cout<<endl<<usun(head1, head2);
    cout<<endl; wypisz(head1);cout<<endl; wypisz(head2);
    return 0;
}
