安装git 工具 <br />
    1.sudo apt-get git <br />

安装mysql服务端与C Connector <br />
    1.sudo apt-get install mysql-server libmysqlclient-dev <br />
    mysql > grant all privileges on didi.\* to didi@localhost identified by 'didi123456'; <br />
    mysql > flush privileges; <br/>

安装zlog模块 <br />
    1.sudo git clone https://github.com/bmanojlovic/zlog.git <br />
    2.cd zlog <br />
    3.make  <br />
    4.sudo make install    <br />
    5.sudo vi /etc/ld.so.conf   Add  /usr/local/lib <br />
    6.sudo ldconfig <br />
安装uuid 生成器 <br />
    1.sudo apt-get install uuid-dev <br />

