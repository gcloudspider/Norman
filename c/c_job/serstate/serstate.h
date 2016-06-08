#ifndef LINUXSERVERSTATE_H 
#define LINUXSERVERSTATE_H 
#include <sys/types.h> 
#include <unistd.h> 
#include <string> 
#include <vector> 
#include <pthread.h> 
namespace LINUXSERV_STATE 
{ 
#pragma pack(push) 
#pragma pack(8) 
    struct SysMemInfo 
    { 
        unsigned long total;//单位：M 
        unsigned long free;//单位：M 
    }; 
    struct SysDiskInfo 
    { 
        std::string   name;//sda1,sad2等等 
        unsigned long total;//单位：M，不包括交换分区、CDROM等 
        unsigned long free;//单位：M 
    }; 
    struct SysNetInfo 
    { 
        float send;//kb 
        float recv;//kb 
        float total;//kb 
    }; 
    struct SysProcInfo 
    { 
        std::string   name;//进程名字 
        int           pid;//进程id 
        int           cpu;//cpu使用率 
        long      mem;//内存使用，单位Kb，linux内存指的是vm<a href="http://www.it165.net/design/wrss/" target="_blank" class="keylink">rss</a>，即程序正在使用的物理内存，-1表示未获取到或获取错误 
    }; 
    struct SysProcTimeInfo 
    { 
        unsigned long user;//进程在用户态执行的时间 
        unsigned long kernel;//进程在内核态执行的时间 
    }; 
    //linux src目录中的include/net/tcp_states.h，source目录一般位于/usr/src/linux＊目录中 
    enum SysNetState{ 
        TCP_ESTABLISHED = 1, 
        TCP_SYN_SENT, 
        TCP_SYN_RECV, 
        TCP_FIN_WAIT1, 
        TCP_FIN_WAIT2, 
        TCP_TIME_WAIT, 
        TCP_CLOSE, 
        TCP_CLOSE_WAIT, 
        TCP_LAST_ACK, 
        TCP_LISTEN, 
        TCP_CLOSING,    /* Now a valid state */
        TCP_MAX_STATES  /* Leave at the end! */
    }; 
    enum SockType{UNKNOWN=0,TCP , UDP, TCP6, UDP6}; 
    struct SysNetConnInfo 
    { 
        int               id; 
        SockType  protocol; 
        std::string   localAddr; 
        int               localPort; 
        std::string   remoteAddr; 
        int               remotePort; 
        SysNetState   state; 
    }; 
#pragma pack(pop) 
    void* CPUNetProcessCount(void* arg); 
    class LinuxServerState 
    { 
        public: 
            LinuxServerState(); 
            virtual     ~LinuxServerState(); 

            int     GetMemInfo(SysMemInfo& memInfo); 
            int     GetDiskInfo(std::vector<SysDiskInfo>& diskInfo,unsigned long &total,unsigned long &available); 
            //返回cpu的利用率，返回－1表示超时或者其他错误 
            int     GetCpuUsage(); 
            //sys net info 
            SysNetInfo  GetNetInfo(); 
            //process info 
            void    GetProcInfo(std::vector<SysProcInfo>& procInfo); 
            //net connection info 
            void    GetNetConnectionInfo(std::vector<SysNetConnInfo>& netConnInfo); 
        private: 
            void    initialize(); 
            friend  void* CPUNetProcessCount(void* arg); 
            int     m_cpuUsage; //多个CPU的总的使用率 
            pthread_mutex_t m_mutex; 
            SysNetInfo  m_netInfo; 
            pthread_t   m_countThread; 
            std::vector<SysProcInfo>  m_procInfo; 
            void*   m_threadRet; 
            LinuxServerState(const LinuxServerState& other); 
            virtual     LinuxServerState& operator=(const LinuxServerState& other); 
            virtual     bool operator==(const LinuxServerState& other) const; 
    }; 
} 
#endif // LINUXSERVERSTATE_H
