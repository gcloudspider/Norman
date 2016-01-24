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
#ifndef _BENZBUILDER_H_
#define _BENZBUILDER_H_
#pragma once
#include "ICarBuilder.h"
#include "CarModel.h"

class CBenzBuilder:public ICarBuilder{
public:
    CBenzBuilder(void);
    ~CBenzBuilder(void);
    void SetSequence(vector<string> *pSeq);
    CCarModel *GetCarModel();
private:
    CCarModel *m_pBenz;
};

#endif
