/**
* Create Date:Sat 16 Apr 2016 08:10:33 PM CST
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
#include <tr1/memory>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_array.hpp>

class CTest {
public:
    CTest() : m_id(0) {}
    CTest(int id) : m_id(id) {}
    ~CTest() {
        cout << "id : " << m_id << "Destuctor isbeing called\n";
    }

    void SetId(int id) {
        m_id = id;
    }

    int GetId() {
        return m_id;
    }
    void DoSomething() {
        cout << "id : " << m_id << "DoSomething\n";
    }
private:
    int m_id;
};

int main(int argc,char* argv[]) {
    boost::scoped_ptr<CTest> pTest(new CTest);
    pTest->SetId(123);
    pTest->DoSomething();

    boost::scoped_array<CTest> pVecTest(new CTest[2]);
    pVecTest[0].SetId(111);
    pVecTest[0].DoSomething();

    std::tr1::shared_ptr<CTest> pSt(new CTest);
    pSt->SetId(999);
    pSt->DoSomething();

    std::tr1::shared_ptr<CTest> pSt2(pSt);
    pSt2->DoSomething();

    std::tr1::shared_ptr<CTest> pSt3;
    pSt3 = pSt2;
    pSt3->DoSomething();

    //weak_ptr
    std::tr1::weak_ptr<CTest> pWt(pSt);
    std::tr1::shared_ptr<CTest> pWtlock = pWt.lock();

    if (pWtlock == pSt) {
        cout << "pWt up to shared_ptr ok!\n";
        pWtlock->SetId(12345);
        pWtlock->DoSomething();
    }

    //shared_array
    boost::shared_array<CTest> pVecSt(new CTest[2]);
    pVecSt[0].SetId(888);
    pVecSt[0].DoSomething();

    //auto_ptr
    std::auto_ptr<CTest> pAt(new CTest);
    pAt->SetId(789);
    pAt->DoSomething();

    std::auto_ptr<CTest> pAt2(pAt);
    pAt2->DoSomething();

    std::auto_ptr<CTest> pAt3;
    pAt3 = pAt2;
    pAt3->DoSomething();

    cout << "pAt = " << pAt.get() << endl;
    cout << "pAt2 = " << pAt2.get() << endl;

    return 0;
}
