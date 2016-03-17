/**
* Create Date:2016年03月16日星期三 18:45:47
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class CLoopLink {
public:
    CLoopLink(){}
    CLoopLink(int total,int n):
        head(nullptr),
        preNode(nullptr),
        FifthNode(nullptr),
        RingLen_(0),
        LenA_(0){
        for (auto i=0; i<total; ++i) {
            auto p = new Node{i,nullptr};
            if (preNode == nullptr) {
                head = p;
                preNode = head;
            } else {
                preNode->next = p;
                preNode = p;
            }

            if ( i == n) {
                FifthNode = p;   
            }
        }
        preNode->next = FifthNode;
    }

    ~CLoopLink() {
        delete[] head;
        delete[] preNode;
        delete[] FifthNode;
        cout << "Destructor" << endl;
    }

    Node* haveRing() {
        Node* fast = head;
        Node* slow = head;

        if (head != nullptr) {
            while (1) {
                if(slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
                    slow = slow->next;
                    fast = fast->next->next;
                } else {
                    return NULL;
                }
                if(fast == slow) {
                    return fast;
                }
            }
        }
        return nullptr;
    }

    int getRingLen(Node* p) {
        Node* fast = p;
        Node* slow = p;
        for (;;) {
            fast = fast->next->next;
            slow = slow->next;
            RingLen_++;
            if (fast == slow)
                break;
        }
        return RingLen_;
    }

    int getLenA(Node* p) {
        Node* fast = head;
        Node* slow = p;

        for(;;) {
            fast = fast->next;
            slow = slow->next;
            LenA_++;
            if(fast == slow)
                break;
        }
        return LenA_;
    }

private:
    Node* head;
    Node* preNode;
    Node* FifthNode;

    int RingLen_;
    int LenA_;
};

int main() {
    Node* pn = nullptr;
    CLoopLink lo(18,3);
    pn = lo.haveRing();
    int RingLen = 0;
    int LenA = 0;
    
    if(pn != nullptr) {
        cout << "有环" << endl;
        RingLen = lo.getRingLen(pn);
        LenA = lo.getLenA(pn);
        cout << "环长度:" << RingLen << endl;
        cout << "开始到连结点长度:" << LenA << endl;
        cout << "链表总长度:" << RingLen+LenA << endl;
    }
}

