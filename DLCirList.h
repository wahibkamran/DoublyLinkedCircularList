#ifndef DLCIRLIST_H_INCLUDED
#define DLCIRLIST_H_INCLUDED
#include <stdio.h>
#include <string>

#include <iostream>

using namespace std;

class CDLinkedList
{

    public:
        CDLinkedList()
        {
            header=new DNode;
            trailer=new DNode;
            header->next=trailer;
            trailer->prev=header;
            header->prev=trailer;
            trailer->next=header;
        }
        class DNode
        {
            public:
                DNode* next;
                DNode* prev;
                int data;

                friend class DLinkedList;

                DNode(int val = NULL) {data=val;}
        };

        class Iterator
        {
            public :
                Iterator(DNode* u);
                int operator*();
                bool operator==(const Iterator& p) const;
                bool operator!=(const Iterator& p) const;
                Iterator& operator++();
                Iterator& operator--();

                friend class NodeList;

                DNode* v;
        };
        //~DLinkedList();
        bool CDempty();
        Iterator Begin() const;
        Iterator End() const;
        void add(const Iterator& p, int val);
        void rmv(Iterator& p);
        void addFront(int val);
        void addBack(int val);
        void removeFront();
        void removeBack();
        void display();
        void CDrotate(int p);
        void CDcopy(const CDLinkedList& cd1);

    private:
        int n=0;
        int cnt=0;
        DNode* header;
        DNode* trailer;
};
#endif
