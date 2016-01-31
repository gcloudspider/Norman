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
#include "HouseMediator.h"
#include "Renter.h"
#include "Landlord.h"
int main(){
    Mediator *mediator = new HouseMediator();
    Person *person1 = new Renter();
    Person *person2 = new Landlord();

    mediator->SetA(person1);
    mediator->SetB(person2);

    person1->SetMediator(mediator);
    person2->SetMediator(mediator);

    person1->SendMessage("我想在南京跳附近过租套房子，价格800元一个月\n");
    person2->SendMessage("出租房子:南京路100号 70平米,1000元一个月\n");
    delete person1;
    delete person2;
    delete mediator;
    return 0;
}
