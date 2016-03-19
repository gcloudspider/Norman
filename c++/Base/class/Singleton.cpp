/**
* Create Date:2016年03月 8日星期二 15:25:25
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

class Singleton {

public:
    static Singleton* GetInstance();
    int getVar();
    void setVar(int var);

private:
    //构造函数放在私有成员部分
    Singleton() {
        var_ = 20;
        cout << "Singleton Constructor" << endl;
    }
    
    virtual ~Singleton() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }
    
    //静态成员变量
    static Singleton* instance;
    int var_;

};

//类外初始化成员变量
Singleton* Singleton::instance = new Singleton();

Singleton* Singleton::GetInstance() {
    return instance;
}

int Singleton::getVar(){
    return var_;
}

void Singleton::setVar(int var) {
    var_ = var;
}

int main() {
    Singleton* ton1 = Singleton::GetInstance();
    Singleton* ton2 = Singleton::GetInstance();

    cout << "ton1 var=" << ton1->getVar() << endl;
    ton1->setVar(150);
    cout << "ton2 var=" << ton2->getVar() << endl;
    return 0;
}
