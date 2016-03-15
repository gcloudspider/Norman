/**
* Create Date:2016年03月 7日星期一 10:01:25
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

class Date {
public:
    Date(int year,int month,int day):
        year_(year),
        month_(month),
        day_(day){
        
    }
    
    Date(const Date& d):
        year_(d.year_),
        month_(d.month_),
        day_(d.day_){
    
    }

    Date operator+(const Date& d) {
        Date t(0,0,0);
        t.year_ = year_ + d.year_;
        t.month_ = month_ + d.month_;
        t.day_ = day_ + d.day_;
        return t;
    }

    Date operator-(const Date& d) {
        Date t(0,0,0);
        t.year_ = year_ - d.year_;
        t.month_ = month_ - d.month_;
        t.day_ = day_ - d.day_;
        return t;
    }

    Date operator=(const Date& d) {
        year_ = d.year_;
        month_ = d.month_;
        day_ = d.day_;
    }

    Date& operator++() {
        ++year_;
        ++month_;
        ++day_;
        return *this;
    }

    const Date operator++(int) {
        Date t(0,0,0);
        t = *this;
        year_++;
        month_++;
        day_++;
        return t;
    }

    void show() {
        cout << year_ << "-";
        cout << month_ << "-";
        cout << day_ << endl;
    }

private:
    int year_;
    int month_;
    int day_;
};

int main() {
    Date a(2011,2,3);
    Date b(1000,1,2);
    Date c = a + b;  //a.operator+(b)简写模式
    c.show();
    Date d = a - b;
    d.show();

    Date e = b;
    e.show();

    Date f = ++a;
    Date ff = ++(++a);
    f.show();
    ff.show();

    cout << "------------------" << endl;

    Date g = a++;
    g.show();

    return 0;
}
