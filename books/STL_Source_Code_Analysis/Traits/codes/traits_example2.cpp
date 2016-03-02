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

struct _xtrue_type {};
struct _xfalse_type {};

class CComplexObject {
public:
    virtual void clone() {
        cout << "in clone" << endl;
    }
};

class CDerivedComplexObject:public CComplexObject {
public:
    virtual void clone() {
        cout << "in derived clone" << endl;
    }
};

template<typename T>
struct Traits {
    typedef _xfalse_type has_clone_method;
};

template<>
struct Traits<CComplexObject> {
    typedef _xtrue_type has_clone_method;  
};

template<typename T>
class XContainer {
    template<typename flag>
    class Impl {
    };

    template <>
    class Impl<_xtrue_type> {
        public:
            void clone(T* pObj) {
                pObj->clone();
            }
    };

    template<>
    class Impl<_xfalse_type> {
        public:
            void clone(T* pObj) {
            }
    };

public:
    void clone(T* pObj) {
        Impl<Traits<T>::has_clone_method>().clone(pObj);
    }
};

int main() {
    int* p1 = 0;
    CComplexObject c2;
    CComplexObject* p2 = &c2;
    CDerivedComplexObject c3;
    CComplexObject* p3 = &c3;

    XContainer<int> n1;
    XContainer<CComplexObject> n2;
    XContainer<CComplexObject> n3;

    n1.clone(p1);
    n2.clone(p2);
    n3.clone(p3);
    return 0;
}
