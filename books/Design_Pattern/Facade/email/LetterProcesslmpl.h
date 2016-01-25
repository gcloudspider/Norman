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
#ifndef _LETTERPROCESSLMPL_H_
#define _LETTERPROCESSLMPL_H_
#pragma once
#include <iostream>
using namespace std;
#include "ILetterProcess.h"
class CLetterProcesslmpl:public ILetterProcess{
public:
    CLetterProcesslmpl(void);
    ~CLetterProcesslmpl(void);

    void WriteContext(string context);
    void FillEnvelope(string address);
    void LetterIntoEnvelope();
    void SendLetter();
};
#endif
