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
#include "DistanceNode.h"

DistanceNode::DistanceNode(char *distance)
    :m_pDistance(distance){
    
}

char * DistanceNode::Interpret(){
    char *pResult = new char[MAX_SIZE];
    memset(pResult,0,MAX_SIZE *sizeof(char));

    strcat(pResult,m_pDistance);

    SAFE_DELETE(m_pDistance);

    return pResult;
}
