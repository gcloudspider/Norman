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
#include <iostream>
using namespace std;

int main(){
    CCurrency g,h(pluse,3,50),i,j;

    g.setValue(minuse,2,25);
    i.setValue(-6.45);
    
    j= h+g;
    cout<<h << "+"<<g<<"="<<j<<endl;

    j=i+g+h;
    cout<<i<<"+"<<g<<"+"<<h<<"="<<j<<endl;

    cout<<"Increment "<<i <<" by "<<g << " and then add "<<h <<endl;

    j=(i+=g)+h;
    cout<<"Result is "<<j <<endl;
    cout<<"Incremented object is "<<i <<endl;


    cout<<"Attempting to initialize with cents = 152" <<endl;
    try{i.setValue(pluse,3,152);}
    catch(illegalParameterValue e){
        cout<<"Caught thrown exception"<<endl;
        e.outputMessage();
    }
    return 0;
}
