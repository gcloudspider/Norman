###安装git 工具
    1.sudo apt-get git
###安装mysql服务端与C Connector
    1.sudo apt-get install mysql-server libmysqlclient-dev
    mysql > grant all privileges on didi.\* to didi@localhost identified by 'didi123456';
    mysql > flush privileges;
    mysql > source ./db/didi.sql
###安装zlog模块
    1.sudo git clone https://github.com/bmanojlovic/zlog.git
    2.cd zlog
    3.make
    4.sudo make install
    5.sudo vi /etc/ld.so.conf 添加/usr/local/lib
    6.sudo ldconfig
###安装uuid生成器
    1.sudo apt-get install uuid-dev
    

