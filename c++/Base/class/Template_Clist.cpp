/**
* Create Date:2016年03月13日星期日 11:22:50
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

template <typename T> 
struct Node {
    T data;
    Node* pre;
    Node* next;
};

template <typename T>
class CList {
public:
    class Iterator {
    public:
        Iterator(Node<T>* p):ptr(p){}
        Iterator(const Iterator& it):ptr(it.ptr){}
        
        void operator++(int) {
            ptr = ptr->next;
        }

        Iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }

        T& operator*() {
            return ptr->data;
        }

        bool operator!=(const Iterator& it) {
            return ptr != it.ptr;
        }
    private:
        Node<T>* ptr;
    };

public:
    CList():
    head(nullptr),
    tail(nullptr),
    m_size(0){
        
    }

    ~CList() {
    
    }

    void push_front(const T& data) {
        Node<T>* pn = new Node<T>{data,nullptr,nullptr};
        
        if(head != nullptr) {
            head->pre = pn;
            pn->next = head;
            head = pn;
        } else {
            tail = pn;
            head = pn;
        }
        m_size++;
    }

    void push_back(const T& data) {
        Node<T>* pn = new Node<T>{data,nullptr,nullptr};

        if(tail != nullptr) {
            tail->next = pn;
            pn->pre = tail;
            tail = pn;
        } else {
            head = pn;
            tail = pn;
        }
        m_size++;
    }
    
    T& front() {
        return head->data;
    }

    T& back() {
        return tail->data;
    }

    bool remove(const T& data) {
        auto pn = head;
        while (pn) {
            if (pn->data == data) {
                if (pn == head) {
                    pn->next->pre = nullptr;
                    head = pn->next;
                    pn->next = nullptr;
                } else if (pn == tail) {
                    pn->pre->next = nullptr;
                    tail = pn->pre;
                    pn->pre = nullptr;
                } else {
                    pn->next->pre = pn->pre;
                    pn->pre->next = pn->next;
                }
                delete[] pn;
                m_size--;
                return true;
            }
            pn = pn->next;
        }
        return false;
    }

    bool empty() {
        return m_size == 0 ? true : false;
    }

    int  size() {
        return m_size;
    }

    Iterator begin() {
        Iterator it(head);
        return it;
    }

    Iterator end() {
        Iterator it(nullptr);
        return it;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int m_size;
};

int main() {
    CList<int> li;
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_back(4);
    


    cout << "front : " << li.front() << endl;
    cout << "back : " << li.back() << endl;
    cout << "size : " << li.size() << endl;
    cout << "empty : " << li.empty() << endl;
    //for it使用后++
    //重载后++
    //CList<int>::Iterator it
    for(auto it = li.begin(); it != li.end();it++) {
        cout << *it << endl;
    }

    //使用范围for语句是使用前缀++
    //重载前++
    for(auto it : li) {
        cout << it << endl;
    }

    li.remove(4);
    cout << "front : " << li.front() << endl;
    cout << "back : " << li.back() << endl;
    cout << "size : " << li.size() << endl;
}
