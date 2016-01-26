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
#ifndef _BIGIMAGEPROXY_H_
#define _BIGIMAGEPROXY_H_
#include "Image.h"
#include "BigImage.h"

class CBigImageProxy:public CImage{
private:
    CBigImage *m_bigImage;
public:
    CBigImageProxy(string name);
    ~CBigImageProxy();
    void Show();
};

#endif
