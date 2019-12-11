#include<iostream>
using namespace std;
struct node{
int w;
node *next;
};
void Insert (node *&f, int k){
    node*r = f;
    node*p = nullptr;

    node *tmp = new node;
    tmp->w=k;
    tmp->next = nullptr;

    while(r!=nullptr && r->w<k){
        p=r;
        r=r->next;
    }
    if(p==nullptr && r==nullptr)
        f=temp;
    else if(p==nullptr && r==f){
        tmp->next=f;
        f=temp;
    }
    else if(p!=nullptr){
        p->next=tmp;
        tmp->next =r;
    }
}
