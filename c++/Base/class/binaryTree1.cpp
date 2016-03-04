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
    ~Tree() {
        Destory(root);
        root = nullptr;
    }

    Tree& Add(int data) {
        root = Push(root,data);
        return *this;
    }

    void Show() {
        Print(root);
        cout << endl;
    }

    int Max() {
        if (root == nullptr) return 0;
        return GetMax(root);
    }

    int Min() {
        if (root == nullptr) return 0;
        return GetMin(root);
    }

    void Remove(int data) {
        if(root == nullptr) return;
        Node* preNode = nullptr;
        Node* pn = FindNode(root,data,preNode);
        if(pn != nullptr) {
            Destory(pn);
        }
        if(pn == root) {
            root = nullptr;
        }
    }

    void RemoveOne(int data) {
        //找到节点
        Node* pn = FindParentNode(root,data);
        if (pn->left != nullptr && pn->right == nullptr)
    }

    void Destory (Node* p) {
        if (p != nullptr) {
            Destory(p->left);
            Destory(p->right);
            delete p;
        }
    }


private:
    Node* Push(Node* p,int data) {
        if (p == nullptr) {
            p = new Node{data,nullptr,nullptr};
        } else {
            if (p->data > data) {
                p->left = Push(p->left,data);
            } else if (p->data < data) {
                p->right = Push(p->right,data);
            }
        }
        return p;
    }

    int GetMax(Node* p) {
        if (p->right == nullptr) {
            return p->data;
        } else {
            return GetMax(p->right);
        }
    }

    int GetMin(Node* p) {
        if (p->left == nullptr) {
            return p->data;
        } else {
            return GetMin(p->left);
        }
    }

    Node* FindParentNode(Node* p, int data) {
        if (p == nullptr) return nullptr;
        
        static Node* parentNode = nullptr;
        
        if (p->data < data) {
            parentNode = p;
            return FindParentNode(p->right,data);
        } else if (p->data > data) {
            parent = p;
            return FindParentNode(p->left,data);
        } else {
            return parentNode;
        }
    }
    
    Node* FindNode(Node* p, int data,Node*& parentNode) {
        if(p->data == data) {
            if(parentNode != nullptr) {
                if (parentNode->right == p) {
                    parentNode->right = nullptr;
                } else if (parentNode->left == p) {
                    parentNode->left = nullptr;
                }
            }
            return p;
        }

        parentNode = p;
        if (p->data < data) {
            if(p->right == nullptr) return nullptr;
            FindNode(p->right,data,parentNode);
        } else if (p->data > data) {
            if(p->left == nullptr) return nullptr;
            FindNode(p->left,data,parentNode);
        }

    }

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
    t.Add(6).Add(8).Add(9).Add(1).Add(2).Add(4);
    t.Show();
    cout << "GetMin= " << t.Max() << endl;
    cout << "GetMin= " << t.Min() << endl;
    t.Remove(6);
    t.Show();
    return 0;
}
