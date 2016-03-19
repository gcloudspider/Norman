/**
* Create Date:2016年03月14日星期一 13:46:51
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

template<typename T>

class CQueue {
public:
    CQueue(int num = 4):cap_(num),size_(0),ptr_(ptr_ = new T[num]) {}

    ~CQueue() {
        delete[] ptr_;
    }

    void push(const T& data) {
        if (size_ == 0) {
            ptr_[size_] = data;
        } else if(size_ == cap_ - 1) {
            resize(cap_ * 2);       
        }
        for (auto i=size_; i != 0;i--) {
            ptr_[i] = ptr_[i-1];
        }
        ptr_[0] = data;
        size_++;
    }

    T& front() {
        return ptr_[size_- 1];
    }

    T& back() {
        return ptr_[0];
    }

    int size() {
        return size_;
    }

    bool empty() {
        return size_ == 0 ? true : false;
    }
    
    void pop() {
        size_--;
    }
    
    void resize(int num) {
        T* p = new T[num];
        for(auto i = 0;i<size_;i++) {
            p[i] = ptr_[i];
        }
        delete ptr_;
        ptr_ = p;
    }

private:
    T* ptr_;
    int cap_;
    int size_;
};

int main() {
    CQueue<int> q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "front : " << q.front() << endl;
    q.pop();
    cout << "front : " << q.front() << endl;
    cout << "back : " << q.back() << endl;
    cout << "size : " << q.size() << endl;
    cout << "empty : " << q.empty() << endl;
    return 0;
}

