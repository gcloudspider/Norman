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
#include "BigImageProxy.h"

CBigImageProxy::CBigImageProxy(string name)
:CImage(name),m_bigImage(0){
    
}

CBigImageProxy::~CBigImageProxy(){
    delete m_bigImage;
}

void CBigImageProxy::Show(){
    if(m_bigImage == NULL){
        m_bigImage = new CBigImage(m_imageName);
        m_bigImage->Show();
    }
}
