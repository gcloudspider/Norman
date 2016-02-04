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
#ifndef _JTLISTITERATOR_H_
#define _JTLISTITERATOR_H_
#include "Iterator.h"
class JTListIterator: public Iterator{
public:
    JTListIterator(JTList *pList);
    virtual void First();
    virtual void Next();
    virtual bool IsDone() const;
    virtual Node *CurrentItem() const;
private:
    JTList *m_pJTList;
    Node *m_pCurrent;
};

#endif
