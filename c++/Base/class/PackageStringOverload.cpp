/**
* Create Date:2016年03月 7日星期一 16:11:01
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

class String {

    friend ostream& operator<<(ostream& out,const String& s);
public:
    explicit String(const char* s):len_(0) {
        len_ = Strlen(s);
        str_ = new char[len_+1];
        Strcpy(str_,s);
    }

    String(const String& s):len_(s.len_) {
        str_ = new char[len_+1];
        Strcpy(str_,s.str_);
    }
    
    ~String(){
        cout << "DeStructor" << endl;
        delete str_;
    }

    void erase(int pos,int n) {
        if (pos < 0 || pos >= len_) return;

        if (n<=0) return;
        
        if (pos+n,len_) {
            for(auto i=pos; i<len_-n; ++i) {
                str_[i] = str_[i+n];
            }
            str_[len_ - n] = '\0';
            len_ = len_ - n;
        } else {
            str_[pos] = '\0';
            len_ = pos;
        }
    
    }

    void replace(int pos,int n,const char* s) {
        if (pos < 0 || pos > len_-1) {
            return;
        }

        if(n < 1) {
            return ;
        }

        if(pos+n < len_) {
            char* p = new char[len_-n + Strlen(s)+1];
            Strncpy(p,str_,pos);
            Strcat(p,s);
            Strcat(p,str_+pos+n);
            delete[] str_;
            str_ = p;
            len_ = len_-n+Strlen(s);
        } else {
            char* p = new char[pos+Strlen(s)+1];
            Strncpy(p,str_,pos);
            Strcat(p,s);
            delete[] str_;
            str_ = p;
            len_ = pos+Strlen(s);
            
        }
    }

    void insert(int pos,const char* s) {
        if (pos < 0 || pos > len_-1) return;

        char* p = new char[len_+Strlen(s)+1];

        Strncpy(p,str_,pos);
        Strcat(p,s);
        Strcat(p,str_+pos);
        len_ = len_+Strlen(s);
        delete[] str_;
        str_ = p;
    }

    String substr(int pos,int n) {
        if (pos == 0 || pos > len_) return String(str_);

        if(n <= 1) return String(str_);

        char buf[n+1];
        Strncpy(buf,str_+pos,n);
        buf[n] = '\0';
        return String(buf);
    }

    int find_last_of(const char* s) {
        for (auto i = len_; i>0; --i) {
            if (Strncmp(str_+i, s, Strlen(s))==0) {
                return i;
            }
        }
        return -1;
    }
    
    int find(const char* s) {
        int len = Strlen(s);
        for (auto i=0;i<len;++i) {
            if (Strncmp(str_+i,s,Strlen(s))==0) {
                return i;
            }   
        }
        return -1;
    }

    String operator+(const String& s) {
        char* p = new char[len_+s.len_+1];
        Strcpy(p,str_);
        Strcat(p,s.str_);
        String t(p);
        len_ = Strlen(p);
        delete[] p;
        return t;
    }

    String operator-(const char* s) {
        int ret = find(s);
        if (ret < 0) {
            return String(str_); //显式调用 
        } else {
            String t(str_);
            t.erase(ret,Strlen(s));
            return t;
        }
    }

    String& operator=(const String& s) {
        delete[] str_;
        int len = Strlen(s.str_);
        str_ = s.str_;
        len_ = s.len_;
        return *this;
    }

    bool operator==(const String& s) {
        if(Strcmp(str_,s.str_) == 0) {
            return true;   
        }
        return false;
    }

    bool operator>(const char* s) {
        if(Strcmp(str_,s) > 0) {
            return true;
        }
        return false;
    }

    String& operator+=(const char* s) {
    
    }

    char& operator[](int i) {
        return str_[i];
    }

private:
    int Strlen(const char* s) {
        auto i = 0;
        while(*s++) i++;
        return i;
    }

    char* Strcpy(char* dst, const char* src) {
        if (dst == nullptr || src == nullptr) {
            return nullptr;
        }

        char* tmp_dst = dst;
        if (dst != src) {
            while (*dst++ = *src++);
        }
        return tmp_dst;
    }

    char* Strncpy(char* dst,const char* src,int n) {
        if(src == nullptr || dst == nullptr) {
            return nullptr;
        }

        char* tmp_dst = dst;

        if ((n>0) && (dst != src)) {
            while(n-- && (*dst++ = *src++));
        }
        return tmp_dst;
    }

    char* Strcat(char* dst,const char* src) {
        if((dst == nullptr) || (src== nullptr))
            return nullptr;

        char* tmp_dst = dst;

        while(*dst != '\0')
            *dst++;

        while(*dst++=*src++);

        return tmp_dst;
    }

    int Strncmp(const char* s1,const char* s2,int len) {
        int i;

        if (len > 0) 
            while((len--)&&!(i=(*(s1++)-*(s2++))&&(*s1++)&&(s2++)));
        return i;
    }

    int Strcmp(const char* s1,const char* s2) {
        int i;
        while(!(i=*(s1++)-*(s2++))&&(*s1++)&&(*s2++));
        return i;
    }

private:
    char* str_;
    int len_;
};

ostream& operator<<(ostream& out,const String& s) {
    out << " "<< s.str_ ;
    return out;
}

int main() {
    String a("hello world");
    cout << "a=" << a << endl;

    String b = a;
    cout << "b=" << b << endl;

    String c("welcome to shenzhen");
    c.erase(11,8);
    cout << "c=" << c << endl;

    String d("China and Chinese");
    d.replace(10,7,"shenzhen");
    cout << "d=" << d << endl;

    String e("I love chain");
    d.insert(7,"chinese and ");
    cout << "e=" << e << endl;

    String f("we are family");
    cout << f.substr(7,6) << endl;

    String g("i am here!");
    cout << "am is: " << g.find_last_of("am") << endl;

    cout << a+c << endl;

    cout << d-"China" << endl;
}
