/**
* Create Date:2016年03月16日星期三 20:43:52
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
#include<stack>


class Calculator {
public:
    Calculator() {
        m = new char[256];   
    }

    ~Calculator() {}

    bool isLeftBrace(char s){
        return (s == '(') ? true : false;
    }

    bool isRightBrace(char s) {
        return (s == ')') ? true : false;
    }

    bool isOperator(char s) {
        return ((s == '+')||(s == '-')||(s == '*')||(s=='/')) ? true : false;
    }

    bool isNum(char s) {
        return (s >='0' && s <= '9') ? true : false;
    }

    int charToInt (char c) {
        return (c - '0');
    }

    int express(int left, int right,char op) {
        int ret = 0;
        switch(op) {
            case '+':
                ret = left + right;
                break;
            case '-':
                ret = left - right;
                break;
            case '*':
                ret = left * right;
                break;
            case '/':
                ret = left/right;
                break;
            default:
                break;
        }
        return ret;
    }

    int priority(char s) {
        if ((s == '+')||(s == '-')) 
            return 1;
        else if ((s == '*')||(s == '/'))
            return 2;
        else 
            return 0;
    }

    int calExpression() {
        stack<int> h;
        int i = 0;
        int j = 0;
        int right = 0;
        int left = 0;
        int result = 0;
        int ret;

        while(m[i] != '\0') {
            if(isNum(m[i])) {
                j = charToInt(m[i]);
                h.push(j);
            } else if (isOperator(m[i])) {
                right = h.top();
                h.pop();
                left = h.top();
                h.pop();
                result = express(left,right,m[i]);
                h.push(result);
            } else {
                cout << "无效的表达式"<< endl;
                break;
            }
            i++;
        }

        if ((h.size() == 1)&& (m[i] == '\0')) {
            ret = h.top();
            h.pop();
        } else {
            cout << "无效的表达式" << endl;
            ret = 0;
        }
        delete m;
        return ret;
    }

    int calcul(char* str) {
        int i = 0;
        int j = 0;
        stack<char> n;
        if(str == nullptr) return 0;

        while(str[i]!= '\0') {
            if(isNum(str[i])) {
                m[j++]  = str[i];      
            } else if (isOperator(str[i])) {
                while((n.size()!=0)&&(priority(str[i])<=priority(n.top()))){
                    m[j++] = n.top();
                    n.pop();
                }
                n.push(str[i]);
            } else if (isLeftBrace(str[i])) {
                n.push(str[i]);
            } else if (isRightBrace(str[i])) {
                while((n.size()!=0)&&(!isLeftBrace(n.top()))){
                    m[j++] = n.top();
                    n.pop();
                }
                n.pop();
            } else {
                cout << "表达式无效!"<<endl;
                break;
            }
            i++;
        }
        while((n.size()>0)&&(str[i] == '\0')) {
            m[j++] = n.top();
            n.pop();
        }
        m[j] = '\0';
        return calExpression();
    }

private:   
    char* m;
};


int main() {
    char* str = new char[256];
    cout << "输入要计算的表达式" << endl;
    cin >> str;
    Calculator cal;
    int ret = cal.calcul(str);
    cout << "计算结果:" << ret << endl;
    return 0;
}
