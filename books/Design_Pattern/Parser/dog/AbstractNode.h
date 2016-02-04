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

#ifndef _ABSTRACTNODE_H_
#define _ABSTRACTNODE_H_
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX_SIZE 256
#define SAFE_DELETE(p) if(p){ delete p; p = NULL;}

const char *const DOWN = "down";
const char *const UP = "up";
const char *const LEFT = "left";
const char *const RIGH = "right";

const char *const MOVE = "move";
const char *const WALK = "walk";

class AbstractNode{
public:
    virtual char *Interpret() = 0;
};

#endif
