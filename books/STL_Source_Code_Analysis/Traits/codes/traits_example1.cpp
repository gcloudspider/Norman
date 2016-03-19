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

#include<iostream>
using namespace std;

class CComplexObject {
public:
    void clone() {
        cout << "in clone" << endl;
    }
};

template<typename T,bool isClonable>
class XContainer {
public:
    enum {Clonable = isClonable};

    void clone(T* pObj) {
        Traits<isClonable>().clone(pObj);
    }

    template <bool flag>
    class Traits {

    };

    template <>
    class Traits<true> {
    public:
        void clone(T* pObj) {
            cout << "before cloning Clonable type" << endl;
            pObj->clone();
            cout << "after cloning Clonable type" << endl;
        }
    };
    
    template<>
    class Traits<false> {
    public:
        void clone(T* pObj) {
            cout << "cloning non Clonable type" << endl;
        }
    };

    /*
    void clone(T* pObj) {
        if (isClonable) {
            //没有实现clone方法的非Clonable类或基本类型
            //需要针对不同类型提供不同的实现
            //解决方法:
            //1.模板类中用enum定义一个trait 标示类是否为Clonable类
            //2.在模板类内部引入一个traits提取Traits 
            //3.通过对该类进行specilizing,根据不同trait提供不同实现
            pObj->clone();
        } else {
            //>>>non_clonable algorithmn....
        }
    }
    */
};

int main() {
    int* p1 = 0;
    CComplexObject* p2 = 0;

    XContainer<int,false> n1;
    XContainer<CComplexObject,true> n2;

    n1.clone(p1);
    n2.clone(p2);
    return 0;
}
