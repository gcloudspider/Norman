/**
* Create Date:2016年03月 9日星期三 11:22:04
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//有纯虚函数的类叫抽象类 不能定义对象。
//


#include<iostream>
using namespace std;

class Vehicle {
public:
    Vehicle(int wheels,int weight,const char* name):
    wheels_(wheels),
    weight_(weight){
        name_ = new char[strlen(name)+1];
        strcpy(name_,name);
    }

    virtual ~Vehicle(){
        delete[] name_;
    }
    
    //修饰该函数可重新编写
    virtual void show() = 0;

protected:
    int wheels_;
    int weight_;
    char* name_;
};


class Car : public Vehicle {
public:
    Car(int wheels,int weight,int num,const char* name):
        Vehicle(wheels,weight,name),
        passengerLoad_(num){
        
    }

    ~Car(){}

    void show() override {
        cout << "wheels=" << wheels_;
        cout << " weight=" << weight_;
        cout << " passengerLoad=" << passengerLoad_ << endl;
    }

private:
    int passengerLoad_;
};

class Truck:protected Vehicle {
public:
    Truck(int wheels,int weight,const char* name,int num,int pay):
        Vehicle(wheels,weight,name),
        passengerLoad_(num),
        payLoad_(pay){
        
    }

    ~Truck() {}

private:
    int passengerLoad_;
    int payLoad_;
};

int main() {
    Vehicle* p = new Car(4,500,6);
    p->show();
}

