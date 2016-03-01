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
#include <math.h>
using namespace std;

struct Triangle {
    //判断是否是三角形
    bool isTriangle(int a,int b,int c) {
        return (((a+b) >c) && ((a+c) >b) &&((b+c) >a))?true:false;
    }

    void init(int a,int b,int c) {
        this->a_ = a;
        this->b_ = b;
        this->c_ = c;
        if (isTriangle(a,b,c)) {
            this->area_ = 0.0;
            this->isOK_ = true;
        }
    }

    double getArea() {
        double r;
        double s;
        if(this->isOK_) {
            //r = (a+b+c)/2
            r = this->a_ + this->b_ + this->c_;
            r /= 2;
            
            //s = r*(r-a)(r-b)(r-c)
            //开根
            s = r;
            s *= r - this->a_;
            s *= r - this->b_;
            s *= r - this->c_;
            this->area_ = sqrt(s);
        }
        return this->area_;
    }

    int a_;
    int b_;
    int c_;
    bool isOK_;
    double area_;
};


int main() {
    Triangle tri;
    tri.init(3,4,5);
    cout << tri.getArea() << endl;
}
