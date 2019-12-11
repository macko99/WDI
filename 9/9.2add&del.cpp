#include<iostream>
using namespace std;
struct node
{
    int val;
    node* next;
};
void addFirst(node *&head, int val)
{
    node *p = new node;
    p->val = val;
    p->next = head;
    head = p;
}
void addLast(node *head, int val)
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
void delFirst (node *&head)
{
    if(head!= nullptr)
    {
        node *p = head;
        head = head->next;
        delete p;
    }
}
void delLast (node *head)
{
    if(head == nullptr)
        return;
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    node *tmp = head;
    while(tmp->next->next != nullptr)
        tmp = tmp->next;
    delete temp->next;
    temp->next = nullptr;
}
