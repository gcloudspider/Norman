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
#include<iostream>
using namespace std;

class Date {
public:
    void init() {
        year_ = 1970;
        month_ = 01;
        date_ = 01;
    }

    void show() {
        cout << year_ << "/" << month_ << "/" << date_ << endl;
    }
    
    void setDate(int year,int month,int date) {
        if (month == 2 && isleap(year)) {
            if(date > 29)
                return ;
        } else if (month = 2) {
            if(date > 28) 
                return ;
        }
        
        if (month30or31(month) == 1 && month > 31) {
            return ;
        }
        if (month30or31(month) == 0 && month > 30) {
            return ;
        }

        year_ = year;
        month_ = month;
        date_ = date;
    }

    
    void autoUpdate() {
        if (month_ == 2 && isleap(year_)) {
            if (date_ == 29) {
                date_ = 1;
                month_++;
            } else {
                date_++;   
            }
            return;
        } else if (month_ = 2) {
            if (date_ == 28) {
                date_ = 1;
                month_++;
            } else {
                date_++;   
            }
        }
        
        
        if (month30or31(month_) == 0) {
            if(date_ == 30) {
                date_ = 1;
                month_++;
            } else {
                date_++;
            }
            return;
        }
        
        if (month30or31(month_) == 1) {
            if(month_ == 12 && date_ == 31) {
                date_ = 1;
                month_ = 1;
                year_++;
            } else if (date_ == 31) {
                date_ = 1;
                month_++;
            } else {
                date_++;
            }
            return;
        }
    }

private:
    
    bool isleap(int year) {
        return ((year_%4 == 0)&&(year_%100 !=0)||(year_%400 ==0));
    }
    
    int month30or31(int month) {
        if(month == 4 || month == 6 || month == 9 || month == 11) {
            return 0;
        } else if (month == 1 || month == 3 
                   || month == 5 || month == 7 || month == 8 
                   || month == 10 || month == 12 ) {
            return 1;
        } else {
            return -1;   
        } 
    }

    int year_;
    int month_;
    int date_;
};

int main() {
    Date date;
    date.init();
    date.show();
    date.setDate(2016,03,02);
    date.show();
    date.autoUpdate();
    date.autoUpdate();
    date.autoUpdate();
    date.show();
}
