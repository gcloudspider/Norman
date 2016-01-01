安装git 工具 <br />
1.sudo apt-get git <br />

安装mysql服务端与C Connector <br />
2.sudo apt-get install mysql-server libmysqlclient-dev <br />

安装zlog模块 <br />
3.sudo git clone https://github.com/bmanojlovic/zlog.git <br />
4.cd zlog <br />
5.make  <br />
6.sudo make install    <br />
7.sudo vi /etc/ld.so.conf   Add  /usr/local/lib <br />
8.sudo ldconfig <br />

