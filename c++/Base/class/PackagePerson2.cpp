/**
* Create Date:2016年03月 8日星期二 11:04:22
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
#include <string.h>
using namespace std;

class Person {
public:
    Person(int num,const char* name,int pay):
        num_(num),
        name_(name),
        pay_(pay){
        
        next = head;
        pre = nullptr;
        
        //头插法
        if(head != nullptr) {
            head->pre = this;
        }
        head = this;
    }

    ~Person() {
        if(this == head) {
            cout << "Destruct header!" << endl;
            head = this->next;
        } else {
            cout << "Destruct one" << endl;
            this->pre->next = this->next;
            this->next->pre = this->pre;
        }
    }

    static void showlinklist() {
        auto pn = head;
        while(pn != nullptr) {
            cout << "num=" << pn->num_;
            cout << " name=" << pn->name_;
            cout << " pay=" << pn->pay_ << endl;
            pn = pn->next;
        }       
    }



private:
    static Person* head;

private:
    int num_;
    string name_;
    int pay_;
    Person* next;
    Person* pre;
};

Person* Person::head = nullptr;

int main() {
    Person a(1,"zhangsan1",5000);
    Person b(2,"zhangsan2",7000);
    Person c(3,"zhangsan3",6000);
    Person d(4,"zhangsan4",10000);
    Person::showlinklist();
    return 0;
}
