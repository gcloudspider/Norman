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
#include "ModenPostOffice.h"

CModenPostOffice::CModenPostOffice(void){
    this->m_pLetterProcess = new CLetterProcesslmpl();
    this->m_pLetterPolice = new CLetterPolice();
}

CModenPostOffice::~CModenPostOffice(void){
    delete m_pLetterProcess;
    delete m_pLetterPolice;
}

void CModenPostOffice::SendLetter(string context,string address){
    m_pLetterProcess->WriteContext(context);

    m_pLetterProcess->FillEnvelope(address);

    m_pLetterPolice->CheckLetter(m_pLetterProcess);

    m_pLetterProcess->LetterIntoEnvelope();

    m_pLetterProcess->SendLetter();
}


