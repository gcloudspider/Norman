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
#ifndef _ICARBUILDER_H_
#define _ICARBUILDER_H_
#pragma once
#include "CarModel.h"
class ICarBuilder{
public:
    ICarBuilder(void);
    virtual ~ICarBuilder(void);
    virtual void SetSequence(vector<string> *pseq) =0;
    virtual CCarModel *GetCarModel() = 0;
};
#endif
