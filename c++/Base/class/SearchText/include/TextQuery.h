/**
* Create Date:2016年03月18日星期五 13:16:52
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H
class CTextQuery {
public:
    CTextQuery(string fileName);
    ~CTextQuery();

private:
    string m_fileName;
};
#endif
