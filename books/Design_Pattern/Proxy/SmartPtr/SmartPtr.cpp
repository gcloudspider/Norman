/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based om
*/
#include "SmartPtr.h"

template <typename T>
SmartPtr<T>::SmartPtr(void)
    :m_pData(NULL){
    m_pReference = new KRefCount();
    m_pReference->AddRef();
}

template <typename T>
SmartPtr<T>::SmartPtr(T* pValue)
    :m_pData(pValue){
    m_pReference = new KRefCount();
    m_pReference->AddRef();
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& sp)
    :m_pData(sp.m_pData)
    ,m_pReference(sp.m_pReference){
    m_pReference->AddRef();
}

template <typename T>
SmartPtr<T>::~SmartPtr(void){
    if(m_pReference && m_pReference->Release() == 0){
        SAFE_DELETE(m_pData);
        SAFE_DELETE(m_pReference);
    }
}

template <typename T>
inline T& SmartPtr<T>::operator*(){
    return *m_pData;
}

template <typename T>
inline T* SmartPtr<T>::operator->(){
    return m_pData;
}

template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& sp){
    if(this != &sp){
        if(m_pReference && m_pReference->Release() ==0){
            SAFE_DELETE(m_pData);
            SAFE_DELETE(m_pReference);
        }

        m_pData = sp.m_pData;
        m_pReference = sp.m_pReference;
        m_pReference->AddRef();
    }
    return *this;
}

template <class T>
SmartPtr<T>& SmartPtr<T>::operator=(T* pValue){
    if(m_pReference && m_pReference->Release() == 0){
        SAFE_DELETE(m_pData);
        SAFE_DELETE(m_pReference);
    }
    m_pData = pValue;
    m_pReference = new KRefCount;
    m_pReference->AddRef();
    return *this;
}

template <class T>
T* SmartPtr<T>::Get(){
    T* ptr = NULL;
    ptr = m_pData;
    return ptr;
}

template <class T>
void SmartPtr<T>::Attach(T* pObject){
    if(m_pReference->Release() ==0){
        SAFE_DELETE(m_pData);
        SAFE_DELETE(m_pReference);
    }
    m_pData = pObject;
    m_pReference = new KRefCount;
    m_pReference->AddRef();
}

template <class T>
T* SmartPtr<T>::Detach(){
    T* ptr = NULL;
    if(m_pData){
        ptr = m_pData;
        m_pData = NULL;
        m_pReference->Reset();
    }
    return ptr;
}


