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
#ifndef _ILLEGALPARAMETERVALUE_H_
#define _ILLEGALPARAMETERVALUE_H_
#include <iostream>
using namespace std;
#include <string>
class illegalParameterValue{
public:
    illegalParameterValue():message("illegal Parameter Value"){}
    illegalParameterValue(const char* theMessage){
        message = theMessage;
    }

    void outputMessage(){cout<<message<<endl;}
private:
    string message;

};

#endif
