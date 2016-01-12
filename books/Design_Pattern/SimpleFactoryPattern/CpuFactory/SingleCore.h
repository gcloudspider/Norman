/*########################################################
##File Name: SingleCore.h
##Created Time:2016年01月12日 星期二 09时05分22秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#ifndef _SINGLECORE_H
#define _SINGLECORE_H
enum CTYPE{
    COREA,
    COREB
};

class CSingleCore{
public:
    CSingleCore();
public:
    virtual ~CSingleCore();
public:
    virtual void Show() = 0;
};
#endif
