/**
* Create Date:2016年04月21日 星期四 13时56分55秒
* -------------------------------
* Copyright (C) 2016-2016 by NiaoYun (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by NiaoYun
*/
#include <unistd.h>
#include<iostream>
using namespace std;
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <tr1/memory>
using std::tr1::shared_ptr;

class Downloader {
public:
    Downloader():m_percent(0) {}
    void start() {
        m_thread.reset(new boost::thread(boost::bind(&Downloader::download,this)));
//        m_thread.detach();
    }

    void stop() {
        m_thread->interrupt();
    }

    int get_percent() {return m_percent;}

private:
    void download() {
        //try {
            while(m_percent < 100) {
                boost::this_thread::interruption_point();
                ++m_percent;
                boost::this_thread::sleep(boost::posix_time::seconds(1));
                cout << "正在下载到百分比:" << m_percent << "%" << endl;
            }
        //} 
        //catch (boost::thread_interruptede& /*e*/) {
        //    int a = 0;
        //    ++a;
        //}
    }
    shared_ptr<boost::thread> m_thread;
    int m_percent;
};

int main() {
    cout <<"是否进行下载?" << endl;
    char ch;
    cout << "请输入y/n:";
    if(cin >> ch && ch == 'y') {
        Downloader d;
        d.start();
        cout << "正在准备下载!" << endl;
        cout << "是否停止?" << endl;
        if(cin >> ch && ch == 'y') {
            d.stop();
        }
        cout << "已下载百分比:" << d.get_percent() << "%" << endl;
        sleep(10);
        cout << "退出主程序成功!" << endl;
    }
    return 0;
}
