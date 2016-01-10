/*########################################################
##File Name: Factory.h
##Created Time:2016年01月10日 星期日 17时43分52秒
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

#ifndef _FACTORY_H
#define _FACTORY_H
class Product;

class Factory{
public:
    virtual ~Factory() =0;

    virtual Product* CreateProduct() = 0;
protected:
    Factory();

private:

};

class ConcreteFactory:public Factory{
public:
    ~ConcreteFactory();
    ConcreteFactory();

    Product* CreateProduct();

protected:

private:
};

#endif
