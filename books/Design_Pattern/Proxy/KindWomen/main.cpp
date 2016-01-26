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

#include "WangPo.h"
#include "PanJinLian.h"
#include "JiaShi.h"

void DoPanJinLian(){
    CWangPo *pWangPo;
    pWangPo = new CWangPo(new CPanJinLian());
    pWangPo->MakeEyesWithMan();
    pWangPo->HappyWithMan();
    delete pWangPo;
}

void DoJiaShi(){
    CWangPo *pWangPo;
    pWangPo = new CWangPo(new CJiaShi());
    pWangPo->MakeEyesWithMan();
    pWangPo->HappyWithMan();
    delete pWangPo;
}

int main(){
    DoPanJinLian();

    DoJiaShi();
}
