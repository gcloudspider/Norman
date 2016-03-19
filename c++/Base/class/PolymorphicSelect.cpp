/**
* Create Date:2016年03月10日星期四 08:09:32
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

class Base {
public:
    Base(int id,string name):
        id_(id),
        name_(name){
        cout << "Structor Base" << endl;   
    }

    ~Base(){
        cout << "Destory Base" << endl;
    }

    virtual bool isGood(int num) = 0;
    virtual void show() {}
    
    int getId(){
        return id_;
    }

    string getName() {
        return name_;
    }

private:
    int id_;
    string name_;
};

class Student :public Base {
public:
    Student(int id,string name,int score):
        Base(id,name),
        score_(score),
        pre(nullptr){

        next = shead;
        if (shead != nullptr) {
            shead->pre = this;
        }
        shead = this;

        cout << "Structor Student: " << name << endl;
    }

    ~Student(){
        cout << "Destructor Student" << endl;
    }
    
    void show() {
        auto pn = shead;
        while(pn != nullptr) {
            if(isGood(pn->score_)) {
                cout << "学号:" << pn->getId();
                cout << " 姓名:" << pn->getName();
                cout << " 成绩:" << pn->score_;
                cout << endl;
            }
            pn = pn->next;
        }
    }

    bool isGood(int score){
        if(score >= 90) {
            return true;
        }
        return false;
    }

private:
    int score_;
    static Student* shead;
    Student* next;
    Student* pre;
};

class Teacher : public Base {
public:
    Teacher(int id,string name,int classid,string titles,int papers):
        Base(id,name),
        classid_(classid),
        titles_(titles),
        papers_(papers),
        pre(nullptr){
        
        next = thead;
        if (thead != nullptr) {
            thead->pre = this;
        }
        thead = this;

        cout << "Structor name: " << name << endl; 
    }

    ~Teacher() {
        cout << "Destructor Teacher" << endl;
    }

    void show() {
        auto pn = thead;
        while(pn != nullptr) {
            if(isGood(pn->papers_)) {
                cout << "工号:" << pn->getId();
                cout << " 姓名:" << pn->getName();
                cout << " 班号:" << pn->classid_;
                cout << " 职称:" << pn->titles_;
                cout << " 发表论文数:" << pn->papers_;
                cout << endl;
            }
            pn = pn->next;
        }   
    }

    bool isGood(int papers) {
        if(papers >= 3) {
            return true;
        }
        return false;
    }

private:
    int classid_;
    string titles_;
    int papers_;
    static Teacher* thead;
    Teacher* next;
    Teacher* pre;
};

Student* Student::shead = nullptr;
Teacher* Teacher::thead = nullptr;

int main() {
    Student s1(1001,"李安",80);
    Student s2(1002,"刘明",90);
    Student s3(1003,"杨立",98);
    Student s4(1004,"陈晓",89);
    s1.show();

    Teacher t1(2001,"王老师",201,"初级教师",2);
    Teacher t2(2002,"李老师",205,"中级教师",5);
    Teacher t3(2003,"陈老师",202,"高级教师",8);
    Teacher t4(2004,"杨老师",203,"中级教师",3);
    Teacher t5(2005,"黄老师",204,"高级教师",7);
    t1.show();

    return 0;
}
