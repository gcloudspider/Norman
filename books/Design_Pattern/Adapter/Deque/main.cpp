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
#include "Stack.h"
#include "Queue.h"
#include "Sequence.h"

int main(){
    Sequence *s1 = new Stack();
    Sequence *s2 = new Queue();
    s1->push(1);
    s1->pop();
    s2->push(1);
    s2->pop();
    delete s1;
    delete s2;
    return 0;
}
