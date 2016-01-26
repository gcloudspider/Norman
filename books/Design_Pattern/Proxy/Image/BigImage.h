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
#ifndef _BIGIMAGE_H_
#define _BIGIMAGE_H_
#include "Image.h"

class CBigImage:public CImage{
public:
    CBigImage(string name);
    virtual ~CBigImage();
    void Show();
};
#endif
