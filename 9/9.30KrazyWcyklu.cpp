#include <iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
void wypisz (node *head)
{
    node *p= head;
    do
    {
      cout<<p->val<<" ";
      p=p->next;
    } while(p != head);
}
void addLast (node *&head, int k)
{
    node *tmp = new node;
    tmp->val = k;
    if(head == nullptr)
    {
        head=tmp;
        tmp->next=tmp;
    }
    else
    {
        node *p = head;
        while (p->next != head)
            p=p->next;
        p->next=tmp;
        tmp->next=head;
    }
}
void del (node *&head, int k)
{
    if(head->val == k)
    {
        node *tmp = head;
        head=head->next;
        delete tmp;
    }
    node *p = head, *p2 = head;
    do{
        if(p->val == k)
        {
            p2->next=p->next;
            delete p;
            p=p2->next;
        }
        else
        {
            p2=p;
            p=p->next;
        }
    } while(p != head);
}
bool usun (node *&head, int ile)
{
    int licz=0;
    bool flag = false;
    node *tmp = head, *tmp2 = head;
    do{
        int current = tmp->val;
        do{
            if(tmp2->val == current) licz++;
            tmp2=tmp2->next;
        } while(tmp2 != head);
        if(licz == ile)
        {
            del(head, current);
            licz=0;
            flag = true;
        }
        else
        {
            licz=0;
            tmp=tmp->next;
        }
    } while(tmp != head);
    if(flag) return true;
    return false;
}
int main()
{
    int k; cin >>k;
    node *first = nullptr;
    for(int i=1; i<10; i++)
        {addLast(first, i);}addLast(first, 1);addLast(first, 1);addLast(first, 2);addLast(first, 3);
    wypisz(first);
    cout<<endl<<usun(first, k)<<endl;
    wypisz(first);
    return 0;
}
