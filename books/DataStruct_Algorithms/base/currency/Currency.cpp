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
    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}

void CCurrency::setValue(double theAmount){
    if(theAmount < 0){
        sign = minuse;
        theAmount = -theAmount;
    }else {
        sign=pluse;
        dollars = (unsigned long) theAmount;
        cents = (unsigned int)((theAmount + 0.001 - dollars)*100);
    }
}

CCurrency CCurrency::add(const CCurrency& x) const{
    long a1,a2,a3;
    CCurrency result;

    a1 = dollars * 100 + cents;
    if(sign == minuse) a1 = -a1;

    a2 = x.dollars * 100 + x.cents;
    if(x.sign == minuse) a2 = -a2;

    a3 = a1+ a2;

    if(a3 < 0){
        result.sign = minuse; 
        a3 = -a3;
    }else{
        result.sign = pluse;
        result.dollars = a3/100;
        result.cents = a3 - result.dollars * 100;
    }
    return result;
}

CCurrency& CCurrency::increment(const CCurrency& x){
    *this = add(x);
    return *this;
}

void CCurrency::output() const{
    if(sign == minuse) 
        cout <<'-';
    cout<<'$'<<dollars<<'.';
    if(cents < 10) cout<<'0';
    cout << cents;
}
