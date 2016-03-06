
####表格驱动对象模型
    把所有与memebers相关信息抽出来,放在一个data member table和一个member function table中
    class object 本身则内含指向这两个表格的指针
    
    Member function table是一系列的solts
    每一个slot指出一个member function;

    Data member table 则直接含有data本身

    member function table 成为支持virtual functions的一个有效方案
