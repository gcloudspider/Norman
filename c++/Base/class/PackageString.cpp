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
#include<iostream>
#include<string.h>
using namespace std;

class String {
public:
    String(int num,char s) {
        str_ = new char[num+1];
        for(auto i=0; i<num; ++i) {
            str_[i] = s;
        }
        str_[num] = '\0';
    }

    String(const char* s) {
        len_ = strlen(s);
        str_ = new char[len_+1];
        strcpy(str_,s);
    }

    String(const String& s) : len_(s.len_) {
        str_ = new char[len_+1];
        strcpy(str_,s.str_);
    }

    void resize(int n) {
        if (n < 0) return ;
        char* p = new char[n+1];
        strncpy(p,str_,n);
        delete[] str_;
        str_ = p;
        len_ = n;
    }

    int size() {
        return len_;
    }

    void show() {
        cout << str_ << endl;
    }
    
    bool empty() {
        return len_ == 0;
    }

    void erase(int pos,int n) {
        //开始位置小于0 或 开始位置大于等于总长度直接返回
        if((pos < 0) || (pos >= len_-1)) return;
        //擦除小于1,直接返回
        if(n <= 1) return;
        
        //要擦除的长度小于总长度
        if (pos+n < len_) {
            //从要擦除部分开始遍历
            for(int i=pos;i<len_-n;++i) {
                //将要擦除后面部分与前面连接起来
                str_[i] = str_[n+i];
            }
            str_[len_-n] = '\0';
            len_ = len_-n;
        } else {
            //pos到最后都是要擦除的内容
            str_[pos]='\0';
            len_ = pos;
        }
    }

    void replace(int pos,int n,const char* s) {
        if(pos < 0 || pos > len_-1) {
            return;
        }

        if(n<1) {
            return;
        }
        
        //要替换位置
        if(pos+n < len_) {
            char* p = new char[len_-n+strlen(s)+1];
            //拷贝要替换前的到p
            strncpy(p,str_,pos);
            //连接要替换的s
            strcat(p,s);
            //将要替换到位置后的连接起来
            strcat(p,str_+pos+n);
            delete[] str_;
            str_ = p;
            len_ = len_-n+strlen(s);
        } else {
            char* p = new char[pos+strlen(s)+1];
            strncpy(p,str_,pos);
            strcat(p,s);
            delete[] str_;
            str_ = p;
            len_ = pos+strlen(s);
        }
    }

    String substr(int pos,int n) {
        if(pos ==0 || pos > len_) return nullptr;

        if(n<=1) return nullptr;
        char buf[n+1];
        strncpy(buf,str_+pos,n);
        buf[n] = '\0';
        return buf;
        //return 
        //1.产生一个临时变量 String tmp = const char *buf ;
        //2.隐式类型转换------调用String(const char* s) 拷贝构造函数
        //3.再调用拷贝构造函数 String s5 = tmp;
    }

    void insert(int pos,const char* str) {
        if(pos < 0 || pos > len_-1) return ;
        char* p = new char[len_+strlen(str)+1];
        strncpy(p,str_,pos);
        strcat(p,str);
        strcat(p,str_+pos);
        len_ = len_+strlen(str);
        delete[] str_;
        str_ = p;
    }

    void append(const char* str) {
        char* p = new char[len_+strlen(str)+1];
        strcpy(p,str_);
        strcat(p,str);
        delete[] str_;
        str_ = p;
        len_ = len_+strlen(str);
    }

    int find(const char* str) {
        for(auto i=0;i<len_;++i) {
            if(strncmp(str_+i,str,strlen(str))==0) {
                return i;
            }
        }
        return -1;
    }

    int find_last_of(const char* s) {
        for(auto i=len_;i>0;--i) {
            if(strncmp(str_+i,s,strlen(s))==0) {
                return i;
            }    
        }
        return -1;
    }

private:
    char* str_;
    int len_;
};


int main() {
    String s5("welcom");
    s5.insert(4,"friend");
    s5.show();
    
    String s("hello");
    s.erase(2,3);
    s.show();
    String s1(10,'a');
    cout << s.empty() << endl;
    s1.show();
    cout << s.size() << endl;

    String s3("Hello92iow212owiuz");
    cout << s3.find("iow") << endl;
    int pos = s3.find_last_of("o");
    cout << pos << endl;
    
    String s4("Hello");
    s4.append(" world");
    s4.show();
    s4.replace(2,4,"haha");
    s4.show();

    cout << "------------" << endl;
    String s6 = s4;
    String s7 = s6.substr(1,2);
    s7.show();
}
