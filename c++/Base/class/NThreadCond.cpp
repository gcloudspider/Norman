/**
* Create Date:2016年03月17日星期四 15:49:34
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//条件变量:
//半同步半异步对象内存池
#include<iostream>
using namespace std;
#include <thread>
#include <mutex>
#include <chrono>
#include <list>
#include <condition_variable>
#include <memory>
template<typename T>
class SyncQueue {
public:
    SyncQueue(int size):size_(size),stop_(false) {}

    void put(const T& x) {
        //unique_lock<mutex> locker(mutex_);  //unique_lock代替lock_guard 
        //while (isFull()) {
        //    notFull_.wait(locker);          //满时等待
        //} 

        //if (stop_) return;
        //queue_.push_back(x);
        //notEmpty_.notify_one();
        Add(x);
    }

    void put(T&& x) {                       //右值引用
        Add(forward<T>(x));                 //完美转发
    }


    void take(list<T>& list) {
        unique_lock<mutex> locker(mutex_);
        notEmpty_.wait(locker,[this]{return stop_ || !isEmpty();});

        if (stop_) {
            return ;
        }

        list = move(queue_);                //将所有任务一次从同步队列中移出    减少了加锁次数,避免数据的复制,提高性能
        notFull_.notify_one();
    }

    void take(T& x) {
        unique_lock<mutex> locker(mutex_);
        //while (isEmpty()) {
            //notEmpty_.wait(locker);         //为空阻塞
        notEmpty_.wait(locker,[this]{return !queue_.empty();});   //通过lambda表达式判断更简洁
        //}

        if (stop_) return;
        x = queue_.front();
        queue_.pop_front();
        notFull_.notify_one();
    }

    bool full() {
        unique_lock<mutex> locker(mutex_);
        return queue_.size() >= size_;
    }

    bool empty() {
        unique_lock<mutex> locker(mutex_);
        return queue_.empty();
    }

    int size() {
        unique_lock<mutex> locker(mutex_);
        return queue_.size();
    }

    void stop() {
        {   //临界区变小 ---- 不加括号临界区的范围为整个函数
            unique_lock<mutex> locker(mutex_);
            stop_ = true;
        }
        notEmpty_.notify_all();                 //优化
        notFull_.notify_all();
    }

private:
    bool isFull() const {
        return queue_.size() >= size_;   
    }

    bool isEmpty() const {
        return queue_.empty();
    }

    template<typename F>
    void Add(F&& x) {
        unique_lock<mutex> locker(mutex_);
        notFull_.wait(locker,[this]{return stop_|| (!isFull());});
        if (stop_) {
            return ;
        }
        queue_.push_back(forward<F>(x));
        notEmpty_.notify_one();
    }

    mutex mutex_;
    list<T> queue_;
    int size_;
    condition_variable_any notFull_;
    condition_variable_any notEmpty_;

    bool stop_;
};

const int maxTaskCount = 100;

class ThreadPool {
public:
    using Task = function<void(void)>;
    //默认线程数为当前cpu核数
    ThreadPool(unsigned int numThreads = thread::hardware_concurrency()):queue_(maxTaskCount){
        start(numThreads);
        /*
        runing_ = true;
        for (auto i = 0; i< numThreads; i++) {
            //thread t(&ThreadPool::runInThread,this);
            auto p = make_shared<thread>(&ThreadPool::runInThread,this);

            threadGroup_.push_back(p);
        }*/
    }

    ~ThreadPool() { 
        //如果没有停止时则主动停止线程池
        stop();
        /*
        queue_.stop();
        runing_ = false;
        for (auto m : threadGroup_) {
            if (m) m->join();
        }
        threadGroup_.clear();
        */
    }

    void stop() {
        //保证多线程情况下只调用一次stopThreadGroup()
        call_once(flag_,[this]{stopThreadGroup();});
    }
    
    void put(const Task& task) {
        queue_.put(task);
    }
    
    void put(Task&& task) {
        queue_.put(forward<Task>(task));
    }

private:
    void start(int numThreads) {
        runing_ = true;
        //创建线程
        for (int i=0; i<numThreads; ++i) {
            threadGroup_.push_back(make_shared<thread>(&ThreadPool::runInThread,this));
        }
    }

    void runInThread() {
        while (runing_) {
            list<Task> list;
            queue_.take(list);
            //Task task;
            //queue_.take(task);
            for (auto& task : list) {
                if (!runing_) {
                    return ;
                }
                task();
            }
        }
    }

    void stopThreadGroup() {
        queue_.stop();
        runing_ = false;

        for (auto thread : threadGroup_) {
            if (thread)
                thread->join();
        }
        threadGroup_.clear();
    }

    bool runing_;
    SyncQueue<Task> queue_;
    //线程组
    list<shared_ptr<thread>> threadGroup_;
    once_flag flag_;
};

mutex m;

int main() {
    cout << "main id = " << this_thread::get_id() << endl;
    ThreadPool pool(8);
    for(int i =0;i<20;i++) {
        pool.put([=](){
                m.lock();
                cout << "thread id = " << this_thread::get_id() << endl;
                cout << "i         = " << i << endl;
                this_thread::sleep_for(chrono::seconds(1));
                m.unlock();
                });
    }

    this_thread::sleep_for(chrono::seconds(20));
    return 0;
}
