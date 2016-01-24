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
#include "CarModel.h"

CCarModel::CCarModel(void){
    
}

CCarModel::~CCarModel(void){
    
}

void CCarModel::SetSequence(vector<string> *pSeq){
    m_pSequence = pSeq;
}

void CCarModel::Run(){
    vector<string>::const_iterator it = m_pSequence->begin();
    for(;it<m_pSequence->end();++it){
        string actionName = *it;
        if(actionName.compare("start")==0){
            Start();
        } else if(actionName.compare("stop")==0){
            Stop();
        } else if(actionName.compare("alarm")==0){
            Alarm();
        } else if(actionName.compare("engine boom")==0){
            EngineBoom();
        }
    }
}
