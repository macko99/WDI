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
    while(tmp != nullptr && tmp->next != nullptr)
    {
        node *pom = tmp->next, *pom2 = tmp;
        while(pom2->next != nullptr)
        {
            if(tmp->val == pom->val)
            {
               pom2->next=pom->next;
               delete pom;
               pom = pom2->next;
            }
            else
            {
                pom=pom->next;
                pom2=pom2->next;
            }
        }
        tmp=tmp->next;
    }
}
int main()
{
    node *first =nullptr;
    addLast(first, 2);addLast(first, 4);addLast(first, 6);addLast(first, 4);addLast(first, 4);
    usun(first);
    wypisz(first);
    return 0;
}
