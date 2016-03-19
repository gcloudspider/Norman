/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* pre;
    Node* next;
};

auto insertNode(Node*& head,int data) {
    auto pn = new Node{data,NULL,NULL};
    if (head == nullptr) {
        head = pn;
    } else {
        Node* p1 = head;
        while(p1->next != nullptr) {
            p1 = p1->next;
        }
        p1->next=pn;
        pn->pre=p1;
    }
}

auto freeDLinkList(Node*& head) {
    auto pn = head;
    Node* pn1 = nullptr;
    while(pn){
        if (pn->next == nullptr) {
            head = pn;
            pn = pn->next;
        } else {
            pn1=pn;
            pn = pn->next;
            delete pn1;
        }
    }
    delete head;
    head = nullptr;
}

auto getNode(Node*& head,Node*& pn) {
    Node* t = head;
    if (t->pre == nullptr && t->next == nullptr) {
        pn = t;
        head = nullptr;
    } else {
        head = t->next;
        head->pre = NULL;
        t->next = NULL;
        pn = t;
    }
}

auto insertSort(Node*& head,Node*& newhead) {
    Node* pn = nullptr;
    while (head) {
        getNode(head,pn);
        if (newhead == nullptr) {
            newhead = pn;
        } else {
            Node* t = newhead;
            while (t) {
                if ((pn->data > t->data) && (t->next == nullptr)) {
                    t->next = pn;
                    pn->pre = t;
                } else if ((pn->data > t->data) && (pn->data < t->next->data )) {
                    pn->next = t->next;
                    pn->pre = t;
                    t->next->pre = pn;
                    t->next = pn;
                    break;
                } else if (pn->data < t->data) {
                    t->pre = pn;
                    pn->next = t;
                    newhead = pn;
                    break;
                }
                t = t->next;
            }
        }
    }
}

auto showDLinkList(Node*& head) {
    auto pn = head;
    while (pn) {
        printf("%d\n",pn->data);
        pn=pn->next;
    }
}

int main() {
    Node* head = nullptr;
    Node* newhead = nullptr;
    insertNode(head,4);
    insertNode(head,3);
    insertNode(head,9);
    insertNode(head,2);
    insertNode(head,1);
    showDLinkList(head);
    insertSort(head,newhead);
    cout<<"----插入排序后----"<<endl;
    showDLinkList(newhead);
    freeDLinkList(newhead);
}
