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

    j=h.add(g);
    h.output();
    cout<<"+";
    g.output();
    cout<<" = ";
    j.output(); cout<<endl;

    j = i.add(g).add(h);
    h.output();
    cout<<"+";
    g.output();
    cout<<" = ";
    j.output(); cout<<endl;

    j= i.increment(g).add(h);
    h.output();
    cout<<"+";
    g.output();
    cout<<" = ";
    j.output(); cout<<endl;

    cout<<"Attempting to initialize with cents = 152" <<endl;
    try{i.setValue(pluse,3,152);}
    catch(illegalParameterValue e){
        cout<<"Caught thrown exception"<<endl;
        e.outputMessage();
    }
    return 0;
}
