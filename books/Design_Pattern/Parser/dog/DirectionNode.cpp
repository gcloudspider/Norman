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
#include "DirectionNode.h"

DirectionNode::DirectionNode(char *direction)
:m_pDirection(direction){

}

char * DirectionNode::Interpret(){
    char *pResult = new char[MAX_SIZE];
    memset(pResult,0,MAX_SIZE * sizeof(char));

    if(strcmp(m_pDirection,DOWN)==0){
        strcat(pResult,"向下");
    } else if(strcmp(m_pDirection,UP)==0){
        strcat(pResult,"向上");
    } else if(strcmp(m_pDirection,LEFT)==0){
        strcat(pResult,"向左");
    } else if(strcmp(m_pDirection,RIGH)==0){
        strcat(pResult,"向右");
    } else {
        strcat(pResult,"无效指令");
    }

    SAFE_DELETE(m_pDirection);
    return pResult;
}
