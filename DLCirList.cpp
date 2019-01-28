#include "DLCirList.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool CDLinkedList::CDempty()
{
    if(header->next = trailer){
        return true;
    }
    else{return false;}
}

CDLinkedList::Iterator CDLinkedList::Begin() const
{
    Iterator p=Iterator(header->next);
    return p;
}

CDLinkedList::Iterator CDLinkedList::End() const
{
    return Iterator(trailer);
}

void CDLinkedList::add(const Iterator& p, int val)
{
    DNode*w=p.v;
    DNode*temp=new DNode(val);
    temp->data=val;

    temp->next=w;
    temp->prev=w->prev;
    w->prev->next=temp;
    w->prev=temp;
    p.v==temp;
    n++;
}

void CDLinkedList::addFront(int val)
{
    CDLinkedList::add(Begin(),val);
}

void CDLinkedList::addBack(int val) // add to back of list
{
    add(End(), val);
}

void CDLinkedList::rmv(Iterator& p)
{
    int cnt=n;
    DNode*w=p.v;
    w->prev->next=w->next;
    w->next->prev=w->prev;
    if(cnt%2==0){p.v=w->next;}
    else{p.v=w;}

    delete w;
}

void CDLinkedList::removeFront() // remove from font
{
    CDLinkedList::Iterator p = Begin();
    rmv(p);
}

void CDLinkedList::removeBack() // remove from back
{
    rmv(--End());
}

CDLinkedList::Iterator::Iterator(DNode* u) // constructor from Node*
{
    v = u;
}

int CDLinkedList::Iterator::operator*() // reference to the element
{
    return v->data;
}

bool CDLinkedList::Iterator::operator==(const Iterator& p) const
{
    return v == p.v;
}

bool CDLinkedList::Iterator::operator!=(const Iterator& p) const
{
    return v != p.v;
}

CDLinkedList::Iterator& CDLinkedList::Iterator::operator++()
{
    v = v->next;
    return *this;
}

CDLinkedList::Iterator& CDLinkedList::Iterator::operator--()
{
    v = v->prev;
    return *this;
}

void CDLinkedList::display()
{
    for (CDLinkedList::Iterator p=Begin(); p!=End(); ++p)
    {
        cout<<*p<<endl;
    }
}

void CDLinkedList::CDrotate(int r)
{
    CDLinkedList cd2;
    int cnt=n;
    int nmb=n;

    CDLinkedList::Iterator p = Begin();
    CDLinkedList::Iterator q = cd2.Begin();

    cout<<"Random number: "<<r<<endl;

    while (nmb!=1)
    {
        if(cnt%2==0){
            for(int i=0; i<r; i++){
                while(p.v->next==header || p.v->next==trailer || p==End()){
                    ++p;
                }
                ++p;
            }
        }

        else{
            for(int i=0; i<r; i++){
                while(p.v->prev==header || p.v->prev==trailer){
                    --p;
                }
                --p;
            }
        }
        cd2.add(q,*p);
        cout<<"Safe: "<<*p<<endl;
        rmv(p);
        nmb--;
    }
    cout<<"Kill: ";
    display();
    rmv(p);
    CDcopy(cd2);
    n--;
}


void CDLinkedList::CDcopy(const CDLinkedList& cd1)
{
    CDLinkedList::Iterator q= Begin();
    for (CDLinkedList::Iterator p=cd1.Begin(); p!=cd1.End(); ++p){
        add(q,p.v->data);
        n--;
    }
}
