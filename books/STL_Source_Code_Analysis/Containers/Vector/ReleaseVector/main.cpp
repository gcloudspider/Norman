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
/*验证vector 内存释放*
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<string> v;
char ch;

int main(){
    for(int i=0;i<1000000;i++){
        v.push_back("abcdefghijklmn");
        //cin>>ch;
    }
    //此时检查内存54M
    cout<<"Vector clear()前容量为"<<v.capacity()<<endl;
    v.clear();
    //cin>>ch;

    cout<<"Vector clear()后容量为"<<v.capacity()<<endl;
    
    vector<string>(v).swap(v);

    cout<<"Vector swap()后容量为"<<v.capacity()<<endl;

    cin>>ch;

    return 0;
}
