/**
* Create Date:2016年03月20日  8:18:50
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _SEARCHVIEW_H
#define _SEARCHVIEW_H
#include "TextSearch.h"

class CSearchView {
public: 
    CSearchView();
    ~CSearchView();
    
    void iSearchWord();
private:
    std::shared_ptr<CTextSearch> m_searchText;

};

#endif
