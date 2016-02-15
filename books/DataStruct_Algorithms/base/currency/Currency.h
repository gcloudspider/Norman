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
    CCurrency(signType theSign = pluse,unsigned long theDollars = 0,unsigned int theCents = 0);
    //析构函数
    ~CCurrency(){}

    void setValue(signType,unsigned long,unsigned int);
    void setValue(double);
    
    //常量函数---const指明这些函数不会改变调用对象的值
    signType getSign() const{return sign;}
    unsigned long getDollars() const{return dollars;}
    unsigned int getCents() const{return cents;}

    CCurrency add(const CCurrency&) const;
    CCurrency& increment(const CCurrency&);
    void output() const;

private:
    signType sign;
    unsigned long dollars;
    unsigned int cents;

};
#endif
