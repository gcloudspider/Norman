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
#include "DM.h"
#include "PS.h"
#include "PM.h"
#include "HolidayRequest.h"

int main(){
    DM *pDM = new DM(NULL);
    PS *pPS = new PS(pDM);
    PM *pPM = new PM(pPS);

    HolidayRequest *pHolidayRequest = new HolidayRequest(100);
    pPM->HandleRequest(pHolidayRequest);
    SAFE_DELETE(pHolidayRequest);

    pHolidayRequest = new HolidayRequest(2);
    pPM->HandleRequest(pHolidayRequest);

    SAFE_DELETE(pDM);
    SAFE_DELETE(pPS);
    SAFE_DELETE(pPM);
    SAFE_DELETE(pHolidayRequest);
}
