/**
* Create Date:2016年03月13日星期日 10:00:25
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
class CStack {
public:
    CStack(int n=10):m_size(n),i(-1){
        ptr = new T[m_size];
    }
    
    ~CStack() {
        delete ptr;
        ptr = nullptr;
    }

    bool push(const T& value) {
        if(isFull()) {
            return false;
        } else {
            if(i==-1){
                i = m_size-1;
            } else {
                i--;
            }
            ptr[i] = value;
            return true;
        }
    }

    bool isFull() {return i==0;}
    bool isEmpty() { return i==-1;}

    bool pop() {
        if(isEmpty()) {
            return false;
        } else {
            if(m_size == i){
                i = -1;
            }else {
                i++;
            }
        }
    }

    int size() { return i == -1 ? 0 : m_size - i; }

    T top() { return ptr[i]; }

private:
    T* ptr;
    int i;
    int m_size;
};


int main() {
    CStack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << s.top() << endl;
}


