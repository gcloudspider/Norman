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

#ifndef _ILETTERPROCESS_H_
#define _ILETTERPROCESS_H_

#include <iostream>
using namespace std;
#pragma once
class ILetterProcess{
public:
    ILetterProcess(void);
    virtual ~ILetterProcess(void);
    virtual void WriteContext(string context) =0;
    virtual void FillEnvelope(string address) = 0;
    virtual void LetterIntoEnvelope() = 0;
    virtual void SendLetter() = 0;
};

#endif
