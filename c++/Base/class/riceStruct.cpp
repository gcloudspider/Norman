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

struct Rice {
    int type;               //种类
    double inPrice;         //入库价格
    double outPrice;         //出库价格
    int total;          //库存
    double profit;          //利润
    Rice* pre;
    Rice* next;
};

struct Repository {
public:
    void init() {
        head = nullptr;
        for(auto i=0;i<10;++i){
            create_linklist(i,head);
        }   
    }

    void buy(int type,int total,double inPrice) {
        Rice riceIn;
        riceIn.type = type;
        riceIn.inPrice = inPrice;
        riceIn.total = total;

        insert_linklist(head,riceIn,true);
    }

    void sale(int type,int total,double outPric) {
        Rice riceOut;
        riceOut.type = type;
        riceOut.outPrice = outPric;
        riceOut.total = total;

        insert_linklist(head,riceOut,false);
    }
    
    void showContent(Rice *pn) {
        cout << "品种: " << pn->type << endl;
        cout << "库存量: " << pn->total << endl;
        cout << "利润: " << pn->profit << endl;
        cout << "---------------------" << endl;
    }

    void showAll(){
        Rice *pn = nullptr;
        for(auto i = 0; i < 10;++i) {
            pn = show_linklist(head,i);
            showContent(pn);
        }
    }

    void show(int type) {
        Rice *pn = nullptr;
        pn = show_linklist(head,type);
        showContent(pn);
    }
private:
    
    void create_linklist(int type,Rice*& head){
        auto pn = new Rice;
        pn->type = type;
        pn->total = 0;
        pn->profit = 0.0;
        if (head == nullptr) {
            head = pn;
        } else {
            Rice* p1 = head;
            while(p1->next != nullptr) {
                p1 = p1->next;
            }
            p1->next=pn;
            pn->pre=p1;
        }
    }
    
    void insert_linklist(Rice*& head,Rice& rice,bool isIn) {
        auto pn = head;
        while (pn) {
            if (pn->type == rice.type) {
                if (isIn) {
                    pn->total += rice.total;
                    pn->inPrice = rice.inPrice;
                    pn->profit -= rice.total * rice.inPrice;
                } else {
                    pn->total -= rice.total;
                    pn->outPrice = rice.outPrice;
                    pn->profit += rice.total * rice.outPrice;
                }
            }
            pn = pn->next;
        }
    }

    Rice* show_linklist(Rice*& head,int type) {
        Rice* pn = head;
        while(pn) {
            if(pn->type == type) {
                return pn;
            }
            pn = pn->next;
        }
    }

private:
    Rice* head;
};

int main() {
    Repository ri;
    ri.init();
    ri.buy(0,1000,2.3);
    ri.buy(1,100,2.3);
    ri.buy(9,200,2.1);
    ri.buy(3,300,2.5);
    ri.buy(2,500,2.3);
    ri.buy(4,700,2.7);
    ri.buy(5,400,2.9);
    ri.buy(6,900,3.5);
    ri.buy(7,100,3.0);
    ri.buy(8,50,1.9);
    ri.show(1);
    ri.showAll();
    ri.sale(0,1000,2.3);
    ri.sale(1,100,2.3);
    ri.sale(9,200,2.1);
    ri.sale(3,300,2.5);
    ri.sale(2,500,2.3);
    ri.sale(4,700,2.7);
    ri.sale(5,400,2.9);
    ri.sale(6,900,3.5);
    ri.sale(7,100,3.0);
    ri.sale(8,50,1.9);
    ri.showAll();
    return 0;
}
