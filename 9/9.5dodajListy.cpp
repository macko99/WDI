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
        cout<<p->val <<"";
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
void addFirst(node *&head, int val)
{
    node *p = new node;
    p->val = val;
    p->next = head;
    head = p;
}
int LastToAdd (node *&head)
{
    if(head == nullptr)
        return 0;
    if(head->next == nullptr)
    {
        int ost = head->val;
        delete head;
        head = nullptr;
        return ost;
    }
    node *tmp = head;
    while(tmp->next->next != nullptr)
        tmp = tmp->next;
    int ost = tmp->next->val;
    delete tmp->next;
    tmp->next = nullptr;
    return ost;
}
void add (node *head1, node *head2)
{
    node *firstSUM = nullptr;
    int s1=0, s2=0;
    while(head1!=nullptr || head2!=nullptr)
    {
        s1+=LastToAdd(head1)+LastToAdd(head2);
        s2=s1/10;
        s1%=10;
        addFirst(firstSUM, s1);
        s1=s2;
        s2=0;
    }
    wypisz(firstSUM);
}
int main()
{
    node *first =nullptr;
    node *first2 = nullptr;
    for(int i=1; i<=10; i++){
        addLast(first, i%10);
        addLast(first2, i%10);
    }
    wypisz(first); cout<<endl; wypisz(first2);
    cout<<endl; add(first, first2);
    return 0;
    }

