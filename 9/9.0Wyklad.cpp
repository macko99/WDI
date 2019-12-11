#include<iostream>
using namespace std;
struct node{
    int w;
    node *next;
};
void wypisz( node *p){  //rekurencyjnie
    if(p!=nullptr)
    {
        cout<<p->w <<" ";
        wypisz(p->next);
    }
}
void wypisz2 (node *p){     //interacyjnie
    while(p!=nullptr)
    {
        cout<<p->w <<" ";
        p=p->next;
    }
}
void insertLast(node *&first, int n){
    node *p = new node, *v = new node;
    p->w=n;
    p->next =nullptr;
    if(first==nullptr) first=p;
    else
    {
        v=first;
        while(v->next!=nullptr)
            v=v->next;
        v->next=p;
    }
}
int len(node *f){
    int il=0;
    while(f!=nullptr){
        il++;
        f=f->next;
    }
    return il;
}
int lenRek (node *f){
    if(f==nullptr) return 0;
    return lenRek(f->next)+1;
}
void delFirst(node *&f){
    node *tmp = f;
    f=f->next;
    delete tmp;
}
void delLast(node *f){
    while(f->next->next != nullptr)
        f=f->next;
    delete f->next;
    f->next=nullptr;
}
void last(node *f){
    node *r, *p;
    r=f;
    p=nullptr;
    while(r!=nullptr){
        p=r;
        r=r->next;
    }
    cout<<p->w;
}
int main(){
    node *first, *p, *v;
    int s;

    first = nullptr;
    for(int i=0; i<3; i++)  //dodaje na poczatek
    {
        cin >>s;
        p= new node;
        p->next = first;
        p->w = s;
        first = p;
    }

    v=first;    //dodaje na koniec
    while(v->next!=nullptr)
        v=v->next;
    p=new node;
    p->w=7;
    p->next=nullptr;
    v->next=p;

    wypisz(first); cout<<endl; wypisz2(first);
    return 0;
}
