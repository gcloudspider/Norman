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
#include "HouseMediator.h"

HouseMediator::HouseMediator()
:m_A(0)
,m_B(0){

}

void HouseMediator::SetA(Person *A){
    m_A  = A;
}
void HouseMediator::SetB(Person *B){
    m_B = B;
}

void HouseMediator::Send(string message,Person *person){
    if(person == m_A){
        m_B->GetMessage(message);
    }else {
        m_A->GetMessage(message);
    }
}
