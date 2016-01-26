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
#ifndef _SMARTPTR_H_
#define _SMARTPTR_H_
#include "RefCount.h"

template <typename T>
class SmartPtr{
public:
    SmartPtr(void);
    SmartPtr(T *pValue);
    SmartPtr(const SmartPtr<T> &sp);
    ~SmartPtr(void);

    inline T& operator*();
    inline T* operator->();

    SmartPtr<T>& operator=(const SmartPtr<T>& sp);
    SmartPtr<T>& operator=(T* pValue);
    T* Get();
    void Attach(T* pObject);
    T* Detach();
private:
    KRefCount *m_pReference;
    T* m_pData;
};
#endif
