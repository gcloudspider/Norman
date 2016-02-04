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
#include "AndNode.h"

AndNode::AndNode(AbstractNode *left,AbstractNode *right)
    :m_pLeft(left)
     ,m_pRight(right){
         
}

char *AndNode::Interpret(){
    char *pResult = new char[MAX_SIZE];
    memset(pResult,0,MAX_SIZE *sizeof(char));
    char *pLeft = m_pLeft->Interpret();
    char *pRight = m_pRight->Interpret();
    strcat(pResult,pLeft);
    strcat(pResult,pRight);

    SAFE_DELETE(pLeft);
    SAFE_DELETE(m_pRight);
    return pResult;
}
