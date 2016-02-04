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
#include "SentenceNode.h"

SentenceNode::SentenceNode(AbstractNode *direction,AbstractNode *action,AbstractNode *distance)
    :m_pDirection(direction)
     ,m_pAction(action)
     ,m_pDistance(distance){
     
}

char *SentenceNode::Interpret(){
    char *pResult = new char[MAX_SIZE];
    memset(pResult,0,MAX_SIZE * sizeof(char));

    char *pDirection = m_pDirection->Interpret();
    char *pAction = m_pAction->Interpret();
    char *pDistance = m_pDistance->Interpret();

    strcat(pResult,pDirection);
    strcat(pResult,pAction);
    strcat(pResult,pDistance);

    SAFE_DELETE(pDirection);
    SAFE_DELETE(pAction);
    SAFE_DELETE(pDistance);

    return pResult;
}
