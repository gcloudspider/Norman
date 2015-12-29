/*########################################################
##File Name: socket_udp_server.c
##Created Time:2015年12月28日 星期一 15时08分21秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include "head.h"
#include <sys/types.h>       
#include <sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(int argc,char* argv[]) {
	int sfd, ret, nfound, i;
	struct sockaddr_in sin;
	struct sockaddr_in cin;
	int len;
	char buf[1024]={0};
	char chat[1024]={0};

	int eh;
	struct epoll_event ev,events[20];

	if(argc<5){
		printf("Usage: command argv1=[local IP] \n\targv2=[local port] \n\targv3=[friend IP] \n\targv4=[friend port]\n");
		return -1;
	}

	eh = epoll_create(100);

	//建立套接字，确定要使用的协议家族
	sfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sfd == -1){
		perror("socket");
		return -1;
	}

	//绑定地址和端口
	sin.sin_family = AF_INET;
	sin.sin_port = htons((unsigned short)atoi(argv[2]));
	if(inet_pton(AF_INET,argv[1],&sin.sin_addr.s_addr) <=0 ){
		perror("inet_pton");
		return -1;
	}
	ret = bind(sfd,(const struct sockaddr*)&sin,(socklen_t)sizeof(sin));
	if(ret == -1){
		perror("bind");
		return -1;
	}

	cin.sin_family = AF_INET;
	cin.sin_port = htons((unsigned short)atoi(argv[4]));
	if(inet_pton(AF_INET,argv[3],&cin.sin_addr.s_addr) <=0 ){
		perror("inet_pton");
		return -1;
	}
	
    ev.data.fd = sfd;
	ev.events = EPOLLIN|EPOLLET;
	epoll_ctl(eh,EPOLL_CTL_ADD,sfd,&ev);

	ev.data.fd = 0;
	ev.events = EPOLLIN|EPOLLET;
	epoll_ctl(eh,EPOLL_CTL_ADD,0,&ev);

	len =sizeof(cin);
	while(1) {
		nfound = epoll_wait(eh,events,20,-1);
		printf("nfound=%d\n",nfound);
		switch(nfound) {
			case 0:
				printf("epoll_wait time out!\n");
				break;
			case -1:
				perror("epoll_wait error");
				break;
			default: {
				for(i=0;i<nfound;i++) {
					if(events[i].data.fd == sfd){
						//有聊天数据来了要处理
						recvfrom(sfd,buf,sizeof(buf),0,
								 (struct sockaddr*)&cin,
								 (socklen_t*)&len);
						printf("client ip=%s,port=%d\ndata: %s",
								inet_ntoa(cin.sin_addr),
								ntohs(cin.sin_port),buf);
					}else if(events[i].data.fd == 0){
						//键盘有聊天内容要发送
						ret = read(0,chat,sizeof(chat));
						sendto(sfd,chat,strlen(chat),0,
								 (struct sockaddr*)&cin,
								 (socklen_t)len);
					}

				}//end for(i<nfound)
			}
			break;
		}
	}
failed:
	close(sfd);
}
