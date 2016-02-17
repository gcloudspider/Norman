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

####开发版上挂载nfs文件系统:
    1.测试服务器:
        ping 192.168.7.20
    2.设置环境变量从nfs服务器加载文件系统
        set bootargs "noinitrd root=/dev/nfs nfsroot=192.168.7.20:/root/rootfs,timeo=300,rsize=8192,wsize=8192,retrans=10 ip=192.168.7.226:192.168.7.20::::eth0:off init=/linuxrc console=ttySAC0,115200 mem=64M"
    3.保存
        save
