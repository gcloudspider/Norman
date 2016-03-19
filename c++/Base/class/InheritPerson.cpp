/**
* Create Date:2016年03月 8日星期二 16:14:50
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

class Person{
public:
    Person(){}
    ~Person(){}

    void setName(string name){
        name_ = name;
    }

    void setNum(int num) {
        num_ = num;
    }

    void show(){
        cout << "num=" << num_ << " name=" << name_ ;
    }

private:
    int num_;
    string name_;
};

class Student:public Person {
public:
    Student(int num,string name,int classid, int score):
        classid_(classid),
        score_(score){

            setNum(num);
            setName(name);
        }

    ~Student() {}

    void setClassId(int classid) {
        classid_ = classid;
    }
    
    void setScore(int score) {
        score_ = score;
    }

    void showS(){
        show();
        cout << " classid=" << classid_;
        cout << " score=" << score_;
        cout << endl;
    }

private:
    int classid_;
    int score_;
};

class Teacher:public Person { 
public:
    Teacher(int num,string name,string jobtitle,string depart):
    JobTitle_(jobtitle),
    Depart_(depart){
        setNum(num);
        setName(name);
    }
    
    void showT() {
        show();
        cout << " JobTitle=" << JobTitle_;
        cout << " Depart=" << Depart_;
        cout << endl;
    }

    ~Teacher() {}
private:
    string JobTitle_;
    string Depart_;
};

int main() {
    Student stu(1001,"evely211",201,100);
    stu.showS();

    Teacher tea(2001,"Mr.huang","中级教师","语文部");
    tea.showT();
    
    return 0;
}
