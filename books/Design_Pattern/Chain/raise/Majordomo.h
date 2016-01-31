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

#ifndef _MAJORDOMO_H_
#define _MAJORDOMO_H_
#include "Manager.h"
class Majordomo:public Manager{
public:
    Majordomo(Manager *manager,string name);
    void DealWithRequest(string name,int num);
};
#endif
