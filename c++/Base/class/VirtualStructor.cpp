/**
* Create Date:2016年03月 9日星期三 20:02:04
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

class Shape {
public:
    Shape();
    virtual ~Shape();
    virtual void draw();
};

class Circle:public Shape {
public:
    Circle();
    ~Circle();
    void draw();
};

class Rectangle:public Shape{
public:
    Rectangle();
    ~Rectangle();
    void draw();
};

class Shapewrap{
protected:
    Shape* object;
public:
    Shapewrap(const string &type) {
        if(type == "circle") {
            object = new Circle;
        } else if (type == "rectangle") {
            object = new Rectangle;
        } else {
        
        }
    }

    ~Shapewrap(){
        delete object;
    }

    void draw() {
        object->draw();
    }
};

int main() {

    return 0;
}
