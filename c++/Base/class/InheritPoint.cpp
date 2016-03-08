/**
* Create Date:2016年03月 8日星期二 16:49:05
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.1415

class Point {
public:
    Point(int x,int y):
        x_(x),
        y_(y){
        
    }

    ~Point(){}

    int getX() {
        return x_;
    }

    int getY() {
        return y_;
    }

protected:
    int x_;
    int y_;
};

class Circle:public Point {
public:
    Circle(int x,int y,int r):
        Point(x,y),
        r_(r){
        
    }

    ~Circle(){}
    
    double getArea(){
        double s = PI * r_;
        s *= r_;
        return s;
    }

    double getLength() {
        double c = 2*PI;
        c *= r_;
        return c;
    }

    void printAllPoint() {
        int startX = x_ - r_;
        int endX = x_ + r_;

        int startY = y_ - r_;
        int endY = y_ + r_;

        for (int x=startX; x<=endX; x++) {
            for (int y=startY; y<=endY; y++) {
                if(pow(x-x_,2)+pow(y-y_,2) == pow(r_,2)){
                    cout <<"(" << x << "," << y << ")" << endl;
                }
            }
        }
    }

private:
    int r_;
};

int main() {
    Circle c(0,0,1);
    cout << "周长= " <<c.getLength() << endl;
    cout << "面积= " <<c.getArea() << endl;
    c.printAllPoint();
    return 0;
}
