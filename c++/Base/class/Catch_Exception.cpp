/**
* Create Date:2016年03月17日星期四 14:13:26
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

struct Node{
    int a[100];
    int b[100];
    int c[100];
};

int main() {
    try{
        Node* p = new Node[100];
        int a = 0;
        int b = 0;
        cin >> a >> b;
        if(b == 0) {
            throw string("除数为0");
        }
        if(a == 1) {
            throw 1;
        }
        if(a == 2) {
            throw 2;
        }
        int ret = a/b;
        cout << ret << endl;
    }catch(exception& e) {
        cout << "what : " << e.what() << endl;
    }catch(string& s) {
        cout << "what: " << s << endl;
    } catch(int& i) {
        switch(i) {
            case 1:
                cout << "throw 1" << endl;
                break;
            case 2:
                cout << "throw 2" << endl;
                break;
        }
        cout << "what: " << i << endl;
    }
    return 0;
}
