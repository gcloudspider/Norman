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
#include "ActionNode.h"

ActionNode::ActionNode(char *action)
    :m_pAction(action){
    
}

char * ActionNode::Interpret(){
    char *pResult = new char[MAX_SIZE];
    memset(pResult,0,MAX_SIZE * sizeof(char));

    if(strcmp(m_pAction,MOVE)==0){
        strcat(pResult,"移动");
    } else if(strcmp(m_pAction,WALK)==0){
        strcat(pResult,"走动");
    } else{
        strcat(pResult,"无效指令");
    }

    SAFE_DELETE(m_pAction);
    return pResult;
}
