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

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct Person{
    char username[256];
    int age;
    struct Person *next;
}PN;

PN *head;

auto createLinkList(PN *pn) {
    if (head == nullptr) {
        head = pn;
    } else {
        pn->next = head;
        head = pn;
    }
}

auto showLinkList(PN *head) {
    if (head != nullptr) {
        auto pn = head;
        while(pn){
            printf("用户名:%s\n",pn->username);
            printf("年龄:%d\n",pn->age);
            pn = pn->next;
        }
    }
}

auto delLinkList(PN *head) {
    if (head != nullptr) {
        auto pn = head;
        PN *pn1 = nullptr;
        while(pn){
            if(pn->next == nullptr){
                head = pn;
            } else {
                pn1 = pn;
                pn = pn->next;
                delete pn1;
                pn1 = nullptr;
            }
        }
        delete head;
        head = nullptr;
    }else {
        printf("链表不存在\n");
    } 
}

void print_user(){
    auto pn = new Person;
    char* username;
    printf("输入用户名:\n");
    scanf("%s",pn->username);
    printf("输入年龄:\n");
    scanf("%d",&pn->age);
    createLinkList(pn);
}


int main(){
    head = nullptr;
    createLinkList()
}
