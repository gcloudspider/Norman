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
#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

#include "BenzModel.h"
#include "BMWModel.h"
#include "BenzBuilder.h"
#include "BMWBuilder.h"

class CDirector{
public:
    CDirector(void);
    ~CDirector(void);
    CBenzModel* GetABenzModel();
    CBenzModel* GetBBenzModel();
    CBMWModel* GetCBMWModel();
    CBMWModel* GetDBMWModel();
private:
    vector<string> *m_pSeqence;
    CBenzBuilder* m_pBenzBuilder;
    CBMWBuilder* m_pBMWBuilder;
};
#endif
