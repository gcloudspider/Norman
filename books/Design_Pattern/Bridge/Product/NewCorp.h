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
#ifndef _NEWCORP_H_
#define _NEWCORP_H_
#pragma once
#include "IProduct.h"
class CNewCorp{
public:
    CNewCorp(IProduct *pproduct);
    virtual ~CNewCorp(void);
    void MakeMoney();

private:
    IProduct *m_pProduct;
};

#endif
