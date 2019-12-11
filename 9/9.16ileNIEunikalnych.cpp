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
int usun (node *&head)
{
    int licznik=0;
    if(head==nullptr || head->next == nullptr)
        return 0;
    node *tmp = head;
    while(tmp != nullptr && tmp->next != nullptr)
    {
        node *pom = tmp->next, *pom2 = tmp;
        while(pom2->next != nullptr && pom->val == tmp->val)
        {
            pom2->next=pom->next;
            delete pom;
            pom = pom2->next;
            licznik++;
        }
        tmp=tmp->next;
    }
    cout<<licznik<<endl;
}
int main()
{
    node *first =nullptr;
    addLast(first, 8);addLast(first, 8);addLast(first, 4);addLast(first, 7);addLast(first, 7);addLast(first, 7);addLast(first, 2);
    usun(first);
    wypisz(first);
    return 0;
}
