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
#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_
#pragma once
#include "RequirementGroup.h"
#include "PageGroup.h"
#include "CodeGroup.h"

class ICommand{
public:
    ICommand(void);
    virtual ~ICommand(void);
    virtual void Execute() = 0;
protected:
    CRequirementGroup *m_prg;
    CPageGroup *m_ppg;
    CCodeGroup *m_pcg;
};

#endif
