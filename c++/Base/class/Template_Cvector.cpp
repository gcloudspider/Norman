/**
* Create Date:2016年03月13日星期日 16:41:13
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
class Cvector {
public:
    class Iterator {
        friend void Cvector<T>::erase(const Iterator& it);
        friend void Cvector<T>::insert(const Iterator& it,const T& data);
    public:
        Iterator(T*& ptr_):p_(ptr_){ }
        Iterator(const Iterator& it):p_(it.p_) { }

        T& operator*() {
            return *p_;
        }

        void operator++(int) {
            p_ = p_+1;
        }

        Iterator& operator++() {
            p_++;
            return *this;
        }

        bool operator != (const Iterator& it) {
            return p_ != it.p_;
        }

    private:
        T* p_;
    };
public:
    Cvector(int n=4):
        size_(0),
        cap_(n),
        ptr_(ptr_ = new T[n]){ 
    } 

    ~Cvector(){ 
        delete[] ptr_;
    }

    void push_back(const T& data){
        if(size_ == cap_){
            ptr_[size_] = data;
        }
        ptr_[size_]  = data;
        size_++;
    }

    void resize(int n) {
        T* p = new T[n];
        unsigned min = n < cap_ ? n : cap_;
        for(auto j=0;j<min;j++) {
            p[j] = ptr_[j];
        }
        delete ptr_;
        ptr_ = p;
        size_ = n < cap_ ? n : size_;
        cap_ = n;
    }

    Iterator begin() {
        Iterator it(ptr_);
        return it;
    }

    Iterator end() {
        T* tmp = ptr_+size_;
        Iterator it(tmp);
        return it;
    }

    void erase(const Iterator& it) {
        for(T* p = it.p_;p<ptr_+size_;p++) {
            *p = *(p+1);
        }
        size_ --;
    }

    void insert(const Iterator& it,const T& data) {
        if(size_ == cap_) {
            resize(cap_ * 2);
        }
        for (T* p = ptr_ + size_; p!= it.p_;p--) {
            *p = *(p-1);
        }
        *it.p_ = data;
        size_ ++;
    }
    
    int size() {return size_;}

    T& operator[](const int& i) {
        return ptr_[i];
    }

private:
    T* ptr_;
    int cap_;
    int size_;
};


int main() {
    Cvector<int> v;
    v.push_back(10);
    v.push_back(15);
    v.push_back(50);
    v.push_back(70);

    cout << "-----for 循环遍历-----" << endl;
    for(Cvector<int>::Iterator it = v.begin();it != v.end();++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "-----for 范围遍历------"<< endl;
    for(auto& m : v) {
        cout << m << " "; 
    }
    cout << endl;


    for(auto it = v.begin();it != v.end();++it) {
        if(*it == 50) {
            v.insert(it,35);
            break;
        }
    }
    cout << "-----下标方式遍历-----" << endl;
    for(int i=0;i<v.size();++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    Cvector<int> w = v;

    cout << "------拷贝构造函数------" << endl;
    for(auto & zm : w) {
        cout << zm << " ";
    }
    cout << endl;
    cout << "------赋值运算符------" << endl;
    Cvector<int> z;
    z = v;
    for(auto& zz : z) {
        cout << zz << " ";
    }
    cout << endl;
}
