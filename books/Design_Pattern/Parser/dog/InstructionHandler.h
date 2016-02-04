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
#ifndef _INSTRUCTIONHANDLER_H_
#define _INSTRUCTIONHANDLER_H_
#include "AbstractNode.h"

class InstructionHandler{
public:
    InstructionHandler(char *instruction);

    void Handle();
    void Output();

private:
    void SplitInstruction(char **&instruction,int &size);

    char *m_pInstruction;
    AbstractNode *m_pTree;
};

#endif
