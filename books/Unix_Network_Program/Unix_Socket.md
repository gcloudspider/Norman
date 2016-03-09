/**
* Create Date:2016年03月 9日星期三 09:10:13
* 
* Author:Norman
* 
* Description: 
*/

####不同计算机远程进程间通信条件:
    1.确定各自节点网络地址(IP)
    2.进程端口号(port)

####Socket套接字:
    1.套接字地址结构:
        struct sockaddr {
            uint8_t sa_len;
            sa_family_t sa_family;
            char        sa_data[14];
        }
    
        struct sockaddr_in {};

        struct sockaddr_out {};
    
    2.字节排序
        计算机内在中数据存储方式:
            1.小端字节序(内存低地址存储数据低字节,内存高地址存储数据高字节)
            2.大端字节序(内存低地址存储数据高字节,内存高地址存储数据低字节)
        
        网络字节序:采用大端字节序
        主机字节序:(可能是大端字节序/也可能是小端字节序)
        字节序转换函数:
            1.uint32_t htonl()  转换为32位网络字节
            2.uint16_t htons()  转换为16位网络字节

            3.uint32_t ntohl()  转换为32位主机字节序
            4.uint16_t ntohs()  转换为16位主机字节序

        地址转换函数(IP地址--把网络字节序转换成可读地址)
            inet_ntop  将网络字节序二进制地址转换成文本字符串格式
            inet_pton   将文本字符串转换成网络字节序二进制地址
        
        读写:
            readn writen readline封装了read write 以更方便读取
