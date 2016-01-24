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
#ifndef _CARMODEL_H_
#define _CARMODEL_H_
#pragma once
#include <iostream>
using namespace std;
#include <vector>
class CCarModel{
public:
    CCarModel(void);
    virtual ~CCarModel(void);
    void Run();
    void SetSequence(vector<string> *pSeq);
protected:
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Alarm() = 0;
    virtual void EngineBoom() = 0;
private:
    vector<string> *m_pSequence;
};
#endif
