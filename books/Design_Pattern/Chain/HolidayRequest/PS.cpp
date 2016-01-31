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

#include "PS.h"
#include "DM.h"
PS::PS(Manager *handler)
:m_pHandler(handler){

}

bool PS::HandleRequest(HolidayRequest *pRequest){
    DM *pDM = dynamic_cast<DM *>(m_pHandler);
    if(pDM != NULL){
        if(pDM->IsIn()){
            return pDM->HandleRequest(pRequest);
        }
    }
    cout<<"PS said:OK."<<endl;
    return true;
}
