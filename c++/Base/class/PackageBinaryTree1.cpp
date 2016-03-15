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

    bool RemoveNodeAndChilder(int data) {
        //找到节点
        if (root == nullptr) return false;
        //要删除的节点为根节点
        if (root->data == data) {
            Destory(root);
            root = nullptr;
            return true;
        }

        //查找父节点
        Node* p = FindParentNode(root,data);
        if (p != nullptr) {
            //二叉树左边不为空
            if (p->left != nullptr && p->left->data == data) {
                Destory(p->left);
                p->left = nullptr;
            } else {
                Destory(p->right);
                p->right = nullptr;
            }
            return true;
        } else {
            return false;       //要删除的节点不存在二叉树中
        }
    }

    bool RemoveNode(int data) {
        int flag = 0;

        if (root == nullptr) return false;

        //判断是否根节点就是要删除的节点
        if(root->data == data ) {
            if (root->right == nullptr && root->left == nullptr) {
                //若没有子树
                delete root;
                root = nullptr;
            } else if ( root->left == nullptr) {  //判断是否有左子树
                Node* p = root->right;
                delete root;
                root = p;
            } else if (root->right == nullptr) {  //判断是否有右子树
                Node* p = root->left;
                delete root;
                root = p;
            } else {        //既有左子树,右有右子树
                Node* p = root->right;
                Node* t = root->right;
                while (p->left != nullptr) {
                    p = p->left;
                }
                p->left = root->left;
                delete root;
                root = t;
            }
            return true;
        }
        
        //要删除的不是根节点
        Node* p = FindParentNode(root,data);

        if (p == nullptr) {
            return false;
        } else {
            Node* t = nullptr;
            if (p->data < data) {
                t = p->right;
                if (t->left == nullptr && t->right == nullptr ) {
                    delete t;
                    p->right = nullptr;
                } else if (t->left == nullptr) {
                    p->right = t->right;
                    delete t;
                } else if (t->right == nullptr) {
                    p->right = t->left;
                    delete t;
                } else {
                    Node* r = t->right;
                    while(r->left != nullptr) {
                        r = r->left;
                    }
                    r->left = t->left;
                    p->right = t->right;
                    delete t;
                }
            } else if (p->data > data) {
                t = p->left;
                if (t->left == nullptr && t->right == nullptr) {
                    delete t;
                    p->left = nullptr;
                } else if (t->left == nullptr) {
                    p->left = t->right;
                    delete t;
                } else if (t->right == nullptr) {
                    p->left = t->left;
                    delete t;
                } else {
                    Node* r = t->right;
                    while(r->left != nullptr) {
                        r = r->left;
                    }
                    r->left = t->left;
                    p->left = t->right;
                    delete t;
                }
            }
        }
        return true;
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
            parentNode = p;
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
            cout << p->data << " " ;  //前序遍历
            Print(p->left);             //中序遍历:先遍右输出左子树，从小到大排序
            Print(p->right);        //后序遍历:
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
    t.RemoveNodeAndChilder(10);
    t.Show();
    return 0;
}
