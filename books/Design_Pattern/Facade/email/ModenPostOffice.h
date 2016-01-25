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
#ifndef _MODENPOSTOFFICE_H_
#define _MODENPOSTOFFICE_H_
#pragma once
#include "ILetterProcess.h"
#include "LetterProcesslmpl.h"
#include "LetterPolice.h"

class CModenPostOffice{
public:
    CModenPostOffice(void);
    ~CModenPostOffice(void);
    void SendLetter(string context,string address);
private:
    ILetterProcess* m_pLetterProcess;
    CLetterPolice* m_pLetterPolice;
};

#endif
