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
    public:
        Iterator(T*& ptr):p(ptr){ }
        Iterator(const Iterator& it):p(it.p) { }

        T& operator*() {
            return *p;
        }

        void operator++(int) {
            p = p+1;
        }

        Iterator& operator++() {
            p++;
            return *this;
        }

        bool operator != (const Iterator& it) {
            return p != it.p;
        }

    private:
        T* p;
    };
public:
    Cvector():
        i(0),
        m_size(2),
        oldptr(nullptr),
        ptr(nullptr){ 
            ptr = new T[2*m_size];
            m_size = 2*m_size;
    } 

    ~Cvector(){ 
        delete[] ptr;
    }

    void push_back(T data){
        if(i >= m_size - 1){
            oldptr = ptr;
            ptr[i] = data;
            T* p = new T[2*m_size];
            m_size = 2*m_size;
            for(auto j=0;j<m_size;j++) {
                p[j] = ptr[j];
            }
            ptr = p;
            i++;
            delete oldptr;
            oldptr = nullptr;
        } else {
            ptr[i++]  = data;
        }
    }

    Iterator begin() {
        Iterator it(ptr);
        return it;
    }

    Iterator end() {
        T* tmp = ptr+i;
        Iterator it(tmp);
        return it;
    }

    bool erase(Iterator& it) {
        
    }

    bool insert(Iterator& it,int n) {
    
    }
    
    int size() {return i;}

    T& operator[](int i) {
        T* tmp = ptr +i;
        Iterator it(tmp);
        return *it;
    }

private:
    T* oldptr;
    T* ptr;
    int m_size;
    int i;
};


int main() {
    Cvector<int> v;
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(30);
    v.push_back(90);
    v.push_back(80);
    v.push_back(60);
    v.push_back(50);

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
//           v.erase(it);
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
