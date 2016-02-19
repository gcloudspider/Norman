/**
* Create Date:2016年02月19日 星期五 08时45分39秒
* 
* Author:Norman
* 
* Description: 
*/

####移植ssh步骤:
    配置环境: 
        PC   IP:192.168.7.20
        ARM  IP:192.168.7.226

    1.交叉编译zlib-1.2.8:(此用mini2440为例)
        1.1:下载zlib-1.2.8.tar.gz
        1.2:创建/usr/local/zlib2440
        1.3:./configure --prefix=/usr/local/zlib2440
        1.4:修改Makefile
            CC=arm-linux-gcc
            AR=arm-linux-ar
            RANLIB=arm-linux-ranlib
            LDSHARED=arm-linux-gcc -shared -Wl,-soname,libz.so.1,--version-script,zlib.map
        1.5:make && make install 安装到/usr/local/zlib2440
    2.交叉编译dropbear-2015.71:
        2.1:下载dropbear-2015.71.tar.gz
        2.2:创建/usr/local/dropbear2440
        2.3:./configure --prefix=/usr/local/dropbear2440 --with-zlib=/usr/local/zlib2440 CC=arm-linux-gcc --host=arm
        2.4:make 
        2.5:make scp
        2.6:make install
        2.7:拷贝scp到/usr/local/dropbear2440/bin/
        2.8:将/usr/local/dropbear2440/bin 和sbin 拷贝到/root/rootfs/相对应目录下
        2.9:将/usr/local/zlib2440/include目录 拷贝到/root/rootfs/usr/目录
        2.10:将/usr/local/zlib2440/libz.* 拷贝到/root/rootfs/lib目录中
        2.11:重新制作rootfs.ext2.img(详见mkrootfs)
        2.12:烧录rootfs.ext2.img到开发板
        2.13:在开发板上生成server key
            dropbearkey -t rsa -f dropbear_rsa_host_key
            dropbearkey -t dss -f dropbear_dss_host_key
        2.14:在开发板上执行/usr/sbin/dropbear软件监听22端口
        2.15:在开发板上passwd root 设置root密码
        2.16:在PC机上使用scp -P 22 /root/aa.c root@192.168.7.226:/root/ 将PC机上的aa.c文件推送到192.168.7.226的/root/目录下

