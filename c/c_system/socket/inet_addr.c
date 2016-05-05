#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
static void usage(char* pro_name) {
  printf("usage : %s ifname \n",pro_name);
  exit(0);
}
char* mac2str(u_int8_t* s) {
  static char buf[20];
  
  sprintf(buf,"0x%02x:%02X:%02X:%02X:%02X:%02x",s[0],s[1],s[2],s[3],s[4],s[5]);
  return buf;
}
int main(int argc,char **argv) {
  struct sockaddr_in *addr;
  struct ifreq ifr;
  char *name,*address;
  int sockfd;
  u_int8_t mac[IFHWADDRLEN];
  if(argc != 2)
    usage(argv[0]);
  else
    name = argv[1];
  sockfd = socket(AF_INET,SOCK_DGRAM,0);
  strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
  if(ioctl(sockfd,SIOCGIFADDR,&ifr) == -1)
    {
      perror("ioctl error");
      exit(1);
    }
   addr = (struct sockaddr_in *)&(ifr.ifr_addr);
   address = inet_ntoa(addr->sin_addr);
   
   printf("inet addr: %s ",address);
   if(ioctl(sockfd,SIOCGIFBRDADDR,&ifr) == -1)
     {
         perror("ioctl error");
         exit(1);
      }  
   
   addr = (struct sockaddr_in *)&ifr.ifr_broadaddr;
   address = inet_ntoa(addr->sin_addr);
   printf("broad addr: %s ",address);
   if(ioctl(sockfd,SIOCGIFNETMASK,&ifr) == -1)
     {
       perror("ioctl error");
       exit(1);
     }

     addr = (struct sockaddr_in *)&ifr.ifr_addr;
     address = inet_ntoa(addr->sin_addr);
     printf("inet mask: %s ",address);
   strncpy(ifr.ifr_name,name,IFNAMSIZ-1);
   if(ioctl(sockfd,SIOCGIFHWADDR,&ifr) == -1)
     {
       perror("ioctl error");
       exit(1);
     }
    
     memcpy(mac,ifr.ifr_hwaddr.sa_data,IFHWADDRLEN);
     printf("mac addr is: %s\n",mac2str(mac));
     return 0;
}
