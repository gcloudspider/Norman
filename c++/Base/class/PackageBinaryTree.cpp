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
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};

class Tree {
public:
    Tree() : root(nullptr) {}
    void Add(int data) {
        Node* p = new Node{data,nullptr,nullptr};
        Node* pn = root;
        if (root == nullptr) {
            root = p;
        } else {
            while(pn){
                if (pn->data < data) {
                    if (pn->right == nullptr) {
                        pn->right = p;
                        break;
                    }
                    pn = pn->right;
                } else if (pn->data > data) {
                    if (pn->left == nullptr) {
                        pn->left = p;
                    }
                    pn = pn->left;
                } else {
                    break;
                }
            }
        }
    }

    void Show() {
        Print(root);
        cout << endl;
    }

private:
    void Print(Node* p) {
        if(p != nullptr) {
            cout << p->data << " " ;
            Print(p->left);
            Print(p->right);
        }   
    }
    Node* root;
};

int main() {
    Tree t;
    t.Add(6);
    t.Add(8);
    t.Add(9);
    t.Add(1);
    t.Add(2);
    t.Add(4);
    t.Show();
    return 0;
}
