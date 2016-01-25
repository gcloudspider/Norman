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
#include "LetterProcesslmpl.h"
CLetterProcesslmpl::CLetterProcesslmpl(void){
    
}

CLetterProcesslmpl::~CLetterProcesslmpl(void){
    
}

void CLetterProcesslmpl::WriteContext(string context){
    cout<<"填写信的内容...."<<endl;
}

void CLetterProcesslmpl::FillEnvelope(string address){
    cout<<"填写收件人地址及姓名...."<<endl;
}

void CLetterProcesslmpl::LetterIntoEnvelope(){
    cout<<"把信放到信封中...."<<endl;
}

void CLetterProcesslmpl::SendLetter(){
    cout<<"邮递信件..."<<endl;
}
