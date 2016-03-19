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
#include "Currency.h"

CCurrency::CCurrency(signType theSign,unsigned long theDollars,unsigned int theCents){
    //创建一个currency对象
    setValue(theSign,theDollars,theCents);
}

void CCurrency::setValue(signType theSign,unsigned long theDollars,unsigned int theCents){
    if(theCents > 99){
        throw illegalParameterValue("Cents should be < 100");
    }
    amount = theDollars * 100 + theCents;
    if(theSign == minuse) amount = -amount;
}

void CCurrency::setValue(double theAmount){
    if(theAmount < 0){
        amount = (long) ((theAmount - 0.001) * 100);
    }else {
        amount = (long) ((theAmount + 0.001) * 100);
    }
}

CCurrency CCurrency::operator+(const CCurrency& x) const{
    CCurrency result;
    result.amount = amount + x.amount;
    return result;
}

void CCurrency::output() const{
    long theAmount = amount;
    if(theAmount < 0){ cout << '-';
                     theAmount = -theAmount;}
    long dollars = theAmount /100;
    cout<<'$'<<dollars<<".";
    int cents = theAmount - dollars * 100;
    if(cents < 10) cout<<'0';
    cout<<cents;
}

ostream& operator<<(ostream& out,const CCurrency& x){
    long theAmount = x.amount;
    if(theAmount < 0) {out<<'-';
                      theAmount = -theAmount;}

    long dollars = theAmount /100;
    out<<'$'<<dollars<<'.';
    int cents = theAmount - dollars * 100;
    if(cents < 10) out<<'0';
    out<<cents;
    return out;
}
