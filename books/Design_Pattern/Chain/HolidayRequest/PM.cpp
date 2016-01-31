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

#include "PM.h"

PM::PM(Manager *handler)
:m_pHandler(handler){

}

bool PM::HandleRequest(HolidayRequest *pRequest){
    if(pRequest->GetHour() <= 2 || m_pHandler == NULL){
        cout<<"PM said:OK."<<endl;
        return true;
    }
    return m_pHandler->HandleRequest(pRequest);
}
