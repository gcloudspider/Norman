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
        if(next != nullptr)
            delete next;            //delete方法会调用析构函数-----递归调用
        cout << "num" << num_ << endl;
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

    static Person* getNodeById(int num) {
        for (auto p = head;p!=nullptr;p=p->next) {
            if(p->num_ == num) {
                return p;
            }
        }
        return nullptr;
    }
    
    static bool removeNodeById(int num) {
        Person* findNode = nullptr;
        for (auto p = head;p!=nullptr;p=p->next) {
            if(p->num_ == num) {
                findNode = p;
                break;
            }
        }

        if(findNode == head) {
            head = findNode->next;
            //delete findNode;
            return true;
        } else if (findNode != nullptr) {
            findNode->pre->next = findNode->next;
            //findNode->next->pre = findNode->pre;
            //delete findNode;
            return true;
        }
        return false;
    }

    static void free(){
        delete head;
        head = nullptr;
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
    for(int i=0;i<10;++i) {
        auto p = new Person(i,"xx",1000+i);
    }
    Person::removeNodeById(0);
    Person::showlinklist();
    Person::free();
    return 0;
}
