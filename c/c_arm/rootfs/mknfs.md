/**
* Create Date:2016年02月17日 星期三 17时16分29秒
* 
* Author:Norman
* 
* Description: 
*/

####安装NFS服务器:
    1.安装nfs服务器:
        sudo apt-get install nfs-kernel-server
    2.安装nfs客户端:
        sudo apt-get install nfs-common
    3.修改服务器配置:
        vi /etc/export
    4.在配置文件中添加:
        /root/rootfs *(rw,sync,no_root_squash,no_subtree_check)
    5.保存退出
    6.启动服务:
        6.1:nfs为RPC程序,使用前需要映射端口
            /etc/init.d/rpcbind restart 
        6.2:重启nfs服务
            /etc/init.d/nfs-kernel-server restart
    7.测试:
        7.1:挂载nfs文件系统:
            mount -t nfs 192.168.7.20:/root/rootfs /mnt
        7.2:查看/mnt目录中与/root/rootfs目录一样
            ls /mnt
        7.3:取消挂载:
        umount /mnt

####开发板上挂载nfs文件系统:
    1.测试服务器:
        ping 192.168.7.20
    2.设置环境变量从nfs服务器加载文件系统
        set bootcmd "ping 192.168.7.20;nand read 0x31000000 0x60000 0x500000;bootm 0x31000000"
        set bootargs "noinitrd root=/dev/nfs nfsroot=192.168.7.20:/root/rootfs,timeo=300,rsize=8192,wsize=8192,retrans=10 ip=192.168.7.226:192.168.7.20::::eth0:off init=/linuxrc console=ttySAC0,115200 mem=64M"
    3.保存
        save





**************************************************************************
####附录：NFS常用参数如下:
    ro 只读访问
    rw 读写访问sync 所有数据在请求时写入共享
    async nfs在写入数据前可以响应请求
    secure nfs通过1024以下的安全TCP/IP端口发送
    insecure nfs通过1024以上的端口发送
    wdelay 如果多个用户要写入nfs目录，则归组写入(默认)
    no_wdelay 如果多个用户要写入nfs目录，则立即写入，当使用async时，无需此设置。
    hide 在nfs共享目录中不共享其子目录
    no_hide 共享nfs目录的子目录
    subtree_check 如果共享/usr/bin之类的子目录时，强制nfs检查父目录的权限(默认)
    no_subtree_check 和上面相对，不检查父目录权限
    all_squash 共享文件的UID和GID映射匿名用户anonymous，适合公用目录。
    no_all_squash 保留共享文件的UID和GID(默认)
    root_squash root用户的所有请求映射成如anonymous用户一样的权限(默认)
    no_root_squas root用户具有根目录的完全管理访问权限
    anonuid=xxx 指定nfs服务器/etc/passwd文件中匿名用户的UID
    anongid=xxx 指定nfs服务器/etc/passwd文件中匿名用户的GID
