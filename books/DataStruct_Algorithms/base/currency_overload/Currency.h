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

#ifndef _CURRENCY_H_
#define _CURRENCY_H_
#include <iostream>
#include <exception>
using namespace std;
enum signType{pluse,minuse};

class illegalParameterValue{
    public:
    illegalParameterValue(string theMessage = "Illegal parameter value")
    {message = theMessage;}
    void outputMessage() {cout << message << endl;}
    private:
    string message;

};

class CCurrency{
public:
    //构造函数
    CCurrency(signType theSign = pluse,
              unsigned long theDollars = 0,
              unsigned int theCents = 0);
    //析构函数
    ~CCurrency(){}

    void setValue(signType,unsigned long,unsigned int);
    void setValue(double);
    
    //常量函数---const指明这些函数不会改变调用对象的值
    signType getSign() const{if(amount < 0) return minuse;
                            else return pluse;}
    unsigned long getDollars() const{if(amount < 0) return (-amount)/100;
                                    else return amount /100;}
    unsigned int getCents() const{if(amount < 0) return -amount - getDollars()* 100;
                                 else return amount- getDollars() *100;}

    CCurrency operator+(const CCurrency&) const;
    CCurrency& operator+=(const CCurrency& x){
        amount += x.amount;
        return *this;
    }
    friend ostream& operator<<(ostream& out,const CCurrency& x);

    void output() const;

private:
    long amount;
};
#endif
