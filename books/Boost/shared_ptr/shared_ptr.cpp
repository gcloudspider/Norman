/**
* Create Date:Wed 20 Apr 2016 06:29:13 AM CST
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
using namespace std;
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
using namespace std;
using namespace boost;

class Person {
    public:
        Person(string name,int age):m_name(name),m_age(age) {
            cout << "construct" <<endl;
        }
        ~Person() { cout << "destruct" << endl;}

        void print(void) {cout << "name:" << m_name << ", age:" << m_age << endl;}
    private:
        string m_name;
        int m_age;
};

int main() {
    cout << "Hello,This is a test of shared_ptr" << endl;
    if (1) {
        shared_ptr<Person> pMan = make_shared<Person>("Peter Lee",24);
        pMan->print();
    }
    cout << "End test" << endl;
    return 0;
}
