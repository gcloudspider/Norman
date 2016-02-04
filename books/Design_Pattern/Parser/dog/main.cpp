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
#include "InstructionHandler.h"

int main(){
    char *pInstructionStr = "up move 5 and down walk 10";
    InstructionHandler *pInstructionHandler = new InstructionHandler(pInstructionStr);
    pInstructionHandler->Handle();
    pInstructionHandler->Output();

    SAFE_DELETE(pInstructionHandler);
}
