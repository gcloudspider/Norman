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

struct Node {
    unsigned long id;
    string name;
    char gender[4];
    int age;
    Node* next;
    Node* pre;
};

class StuList {
public:
    StuList():
    head(nullptr),
    tail(nullptr),
    size(0) {
    
    }

    ~StuList() { 
    }

    bool load(const string& filename) {
        FILE* fp;
        Node* stu = nullptr;
        fp = fopen(filename.c_str(),"r+");

        if(fp == nullptr) {
            perror("fopen");
            return false;
        }
        
        while(feof(fp)==0) {
            stu = new Node;
            if(stu == nullptr) {
                printf("new failed!\n");
                return false;
            }
            
            char name[20];

            int i = fscanf(fp,"%lu%s%s%d",
                   &stu->id,
                   name,
                   stu->gender,
                   &stu->age);
            stu->name = name;
            if(i == EOF) {
                delete stu;
                break;
            }
            if(head) {
                stu->next = nullptr;
                stu->pre = tail;
                tail->next = stu;
                
            } else {
                stu->next = head;
                stu->pre = head;
                head = stu;
            }
            tail = stu;
            size++;
        }
        fclose(fp);
        return true;
    }
    


    bool front_insert(unsigned long id,const string& name,const char gender[4],int age) {
        
        if(user_Exist(id)) return false;

        auto pn = new Node;
        pn->id = id;
        pn->name = name;
        strcpy(pn->gender,gender);
        pn->age = age;

        pn->pre = nullptr;
        pn->next = head;
        head->pre = pn;
        head = pn;
        size ++;
        return true;
    }

    bool front_del() {
        auto pn = head;
        head = pn->next;
        head->pre = nullptr;
        pn->next = nullptr;
        delete pn;
        return true;
    }

    bool tail_insert(unsigned long id,const string& name,const char gender[4],int age) {
        if(user_Exist(id)) return false;

        auto pn = new Node;
        pn->id = id;
        pn->name = name;
        strcpy(pn->gender,gender);
        pn->age = age;

        pn->pre = tail;
        tail->next = pn;
        pn->next = nullptr;
        tail = pn;
        size++;

        return true;
    }

    bool tail_del() {
        auto pn = tail;
        tail = pn->pre;
        tail->next = nullptr;
        pn->pre = nullptr;
        delete pn;
        return true;
    }

    bool insert(int n,unsigned long id, const string& name,const char gender[4],int age) {
        if (n > size) return false;
        if (user_Exist(id)) return false;
        
        if (n == 0) {
            front_insert(id,name,gender,age);
            return true;
        }

        auto pb = new Node;
        pb->id = id;
        pb->name = name;
        strcpy(pb->gender,gender);
        pb->age = age;

        auto pn = head;
        int i = 1;
        while(pn) {
            if(i == n) {
                pn->pre->next = pb;
                pb->pre = pn->pre;
                pb->next = pn;
                pn->pre = pb;
                size++;
                return true;
            }
            i++;
            pn = pn->next;
        }

        return false;
    }

    bool sort_id() {
        Node* pn = nullptr;
        Node* newhead = nullptr;
        while (head) {
            getNode(pn);
            if (newhead == nullptr) {
                newhead = pn;
            } else {
                Node* t = newhead;
                while (t) {
                    if ((pn->id > t->id) && (t->next == nullptr)) {
                        t->next = pn;
                        pn->pre = t;
                    } else if ((pn->id > t->id) && (pn->id < t->next->id )) {
                        pn->next = t->next;
                        pn->pre = t;
                        t->next->pre = pn;
                        t->next = pn;
                        break;
                    } else if (pn->id < t->id) {
                        t->pre = pn;
                        pn->next = t;
                        newhead = pn;
                        break;
                    }
                    t = t->next;
                }
            }
        }
        head = newhead;
    }

    bool save(const string& filename) {
        FILE* fp;
        Node* pn;

        fp = fopen(filename.c_str(),"w+");
        if(fp == NULL) {
            perror("fopen()");
            return false;
        }

        pn = head;
        while(pn) {
            fprintf(fp,
                   "%lu\t%s\t%s\t%d\n",
                   pn->id,
                   pn->name.c_str(),
                   pn->gender,
                   pn->age
                   );
            pn = pn->next;
        }
        fclose(fp);
        return true;
    }

    bool remove(int n) {
        if (n<=0 || n > size) return false;

        int i = 1;
        auto pn = head;
        while(pn) {
            if(i == n) {
                pn->next->pre = pn->pre;
                pn->pre->next = pn->next;
                pn->next = pn->pre;
                pn->pre = pn->next;
                delete pn;
                return true;
            }
            i++;
            pn = pn->next;
        }
        return false;
    }

    bool isEmpty() {
        return size ==0;
    }
    
    int getSize() {
        return size;    
    }

    void print() {
        if(head != nullptr) {
            auto pn = head;
            while(pn) {
                cout << "id=" << pn->id 
                << " name=" << pn->name 
                << " gender=" << pn->gender 
                << " age=" << pn->age << endl;
                pn = pn->next;
            }
        }
    }

private:
    bool user_Exist(unsigned long id) {
        auto pn = head;
        while(pn) {
            if(pn->id == id) {
                return true;
            }
            pn = pn->next;
        }
        return false;
    }
    
    void getNode(Node*& pn) {
        Node* t = head;
        if (t->pre == nullptr && t->next == nullptr) {
            pn = t;
            head = nullptr;
        } else {
            head = t->next;
            head->pre = NULL;
            t->next = NULL;
            pn = t;
    }
}
private:
    Node* head;
    Node* tail;
    int size;
};


int main() {
    bool ret;
    StuList student;

    if(student.isEmpty())
        cout << "Empty" << endl;
    
    student.load("./stu.txt");
    student.print();
    cout << "---------------------------------" << endl;
    ret = student.front_insert(1009,"肖雯","女",24);
    if(!ret) {
        cout << "头插失败:用户已存在!" << endl;
    }

    ret = student.tail_insert(1010,"莫山","男",27);
    if(!ret) {
        cout << "尾插失败:用户已存在!" << endl;
    }
    
    student.print();

    cout << student.getSize() << endl;
    cout << "---------------------------------" << endl;
    student.insert(5,1011,"杨哲","男",29);
    student.print();

    cout << "---------------------------------" << endl;
    student.sort_id();
    student.print();

    student.save("./stu.txt");

    student.front_del();
    cout << "---------------------------------" << endl;
    student.print();
    student.tail_del();
    cout << "---------------------------------" << endl;
    student.print();

    student.remove(3);
    cout << "---------------------------------" << endl;
    student.print();

    /*
    int index = student.find_id(1002);
    if (-1 != index) {
        Node* ptr = getNode(index);
        cout << ptr->id << " " << ptr->name << " " << ptr->gender << " " << ptr->age << endl;
    } 

    index = student.find_name("李明");
    if (-1 != index) {
        Node* ptr = getNode(index);
        cout << ptr->id << " " << ptr->name << " " << ptr->gender << " " << ptr->age << endl;
    }
    */
    return 0;
}
