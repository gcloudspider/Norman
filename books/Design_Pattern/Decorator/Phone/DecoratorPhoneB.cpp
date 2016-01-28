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
#include "DecoratorPhoneB.h"

DecoratorPhoneB::DecoratorPhoneB(Phone *phone)
:DecoratorPhone(phone){
    
}

void DecoratorPhoneB::ShowDecorate(){
    DecoratorPhone::ShowDecorate();
    AddDecorate();
}

void DecoratorPhoneB::AddDecorate(){
    cout<<"屏幕贴膜"<<endl;
}
