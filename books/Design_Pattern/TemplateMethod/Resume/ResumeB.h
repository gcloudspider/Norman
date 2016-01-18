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
#ifndef _RESUMEB_H_
#define _RESUMEB_H_
#include "Resume.h"

class ResumeB:public Resume{
protected:
    void SetPersonalInfo(){cout<<"B's PersonalInfo"<<endl;}
    void SetEducation(){cout<<"B's Education"<<endl;}
    void SetWorkExp(){cout<<"B's Work Experience"<<endl;}
};

#endif
