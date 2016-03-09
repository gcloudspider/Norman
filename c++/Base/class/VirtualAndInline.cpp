/**
* Create Date:2016年03月 9日星期三 19:27:07
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
    inline virtual void draw() = 0;
};

inline void Shape::draw() {
    cout << "Shape::draw()" << endl;
}

class Rectangle : public Shape {
public:
    void draw() {
        Shape::draw();
        cout << "Rectangle::draw()" << endl;
    }
};

int main() {
    Shape* p = new Rectangle;
    p->draw();                  
    //draw调用被转换为(*p->vptr[1](p))
    //1 代表draw虚函数列表中的位置,因为draw调用通过函数指针_vptr[1]来实现编译器不能在编译时刻确定调用函数的地址.所以不可能为内联
    //内联虚函数至少需要一个定义来在虚函数列表中放置它的地址。
    //编译器如何确定什么时候生成定义
    //  1.在虚函数列表生成的时候就生成定义(每个类的实例生成一个虚函数列表,每一个内联函数的实例也同时产生)
    //  标准中没有控制虚函数列表或者生成多少实例
    
}
