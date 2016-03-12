/**
* Create Date:2016年03月10日星期四 15:46:28
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
class CEmployee {
public:
    CEmployee();
    CEmployee(string name,int age, string sex,int type,string post,int status);
    virtual ~CEmployee();

    static int getId();
    int getLevel();
    void setId(int n);

    //virtual float getBasePay();
    //virtual float getPercent();
    friend class DBManage;
private:
    static int m_id;
    string m_name;
    int m_age;
    string m_sex;
    int m_type;
    string m_post;
    int m_level;
    int m_status;
};
#endif
