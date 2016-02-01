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

#ifndef _LISIOBSERVER_H_
#define _LISIOBSERVER_H_
#pragma once
#include "IObserver.h"
class CLiSiObserver: public IObserver{
public:
    CLiSiObserver(void);
    ~CLiSiObserver(void);
    void Update(string context);
    string GetName();

private:
    void ReportToQinShiHuang(string report);
};
#endif
