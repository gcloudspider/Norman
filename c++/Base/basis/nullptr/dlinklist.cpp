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

auto findMaxNode(Node*& head,Node*& max) {
    auto pn = head;
    max = pn;
    while (pn) {
        if (pn->data > max->data) {
            max = pn;
        }
        pn = pn->next;
    }
}

auto getNode(Node*& head,Node*& pn) {
    Node* t = head;
    if (t->pre == nullptr && t->next == nullptr) {
        pn = t;
    } else {
        head = t->next;
        head->pre = NULL;
        t->next = NULL;
        pn = t;
    }
}

auto insertSort(Node*& head,Node*& newhead) {
    Node* pn = nullptr;
    while(head){
        getNode(head,pn);
        if (newhead == nullptr) {
            newhead = pn;
        } else {
            Node* max = nullptr;
            findMaxNode(newhead,max);
            if (pn->data > max->data) {
                max->next = pn;
                pn->pre = max;
            } else if(pn->data < max->data){
                pn->pre = max->pre;
                pn->next = max;
                max->pre->next = pn;
                max->pre = pn;
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
    insertNode(head,0);
    insertNode(head,9);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,5);
    insertNode(head,4);
    insertNode(head,6);
    insertNode(head,7);
    showDLinkList(head);
    insertSort(head,newhead);
    showDLinkList(newhead);
    freeDLinkList(newhead);
}
