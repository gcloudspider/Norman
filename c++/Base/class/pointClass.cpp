/**
* Create Date:2016年03月 7日星期一 13:51:46
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

class Point {
    friend ostream& operator<<(ostream& out,const Point& p);
    friend istream& operator>>(istream& in,Point& p);
public:
    Point(int x,int y):x_(x),y_(y) {}
    Point(const Point & p):
        x_(p.x_),
        y_(p.y_){
        
        }

    ~Point(){}

    void offset(int x,int y) {
        x_ += x;
        y_ += y;
    }

    void offset(const Point& p) {
        x_ += p.x_;
        y_ += p.y_;
    }
    
    bool operator==(const Point& p) {
        
        if(x_ == p.x_ && y_ == p.y_) {
            return true;
        }
        return false;
    }
    
    bool operator!=(const Point& p) {
        if(x_ != p.x_ || y_ == p.y_) {
            return true;
        }
        return false;
    }
    
    void operator+=(const Point& p) {
        x_ += p.x_;
        y_ += p.y_;
    }
    
    void operator-=(const Point& p) {
        x_ -= p.x_;
        y_ -= p.y_;
    }
    
    
    Point& operator+(const Point& p) {
        static Point t(0,0);
        t.x_ = x_ + p.x_;
        t.y_ = y_ + p.y_;
        return t;
    }
    
    
    Point& operator-(Point& p) {
        static Point t(0,0);
        t.x_ = x_ + p.x_;
        t.y_ = y_ + p.y_;
        return t;
    }

    int getx() {return x_;}
    int gety() {return y_;}

    void show() {
        cout << "("<<x_<<","<<y_<<")"<<endl;
    }

private:
    int x_;
    int y_;
};

ostream& operator<<(ostream& out,const Point& p) {
    out << "(" << p.x_ << "," << p.y_ << ")";
    return out;
}

istream& operator>>(istream& in,Point& p) {
  in >> p.x_;
  in >> p.y_;
}

int main() {
    Point t(10,2);
    Point s(10,2);

    s.show();
    t.show();
    
    if(t==s) {
        cout << "t = s" << endl;
    } else {
        cout << " t != s" << endl; 
    }

    cout << t ;    //operator<<(out,t);
    
    cout << t <<endl;   

    Point z(0,0);
    cin >> z;
    cout << z << endl;
}
