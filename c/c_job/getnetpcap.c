#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stddef.h>
#define CAPTURE_LENGTH 72
#define ETHERTYPE_IP        0x0800
#define DEFAULT_ETH "eth0"

pcap_t *pd;
pcap_handler packet_handler;
unsigned char if_hw_addr[6];
struct in_addr if_ip_addr;

static void handle_eth_packet(unsigned char* args, const struct pcap_pkthdr* pkthdr, const unsigned char* packet){
    struct ether_header *eptr;
    uint16_t ether_type;
    const unsigned char *payload;
    eptr = (struct ether_header*)packet;
    //ether_type = ntohs(eptr->ether_type);
    //payload = packet + sizeof(struct ether_header);
    //if(ether_type == ETHERTYPE_IP){
        printf("ether type: ETHERTYPE IP");    
   // }
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    int dlt;
    int result;

    //result = get_addrs_ioctl(DEFAULT_ETH, if_hw_addr, &if_ip_addr);
    //if (result < 0) {
    //    exit(1);
    //}

    pd = pcap_open_live(DEFAULT_ETH, CAPTURE_LENGTH, 0, 1000, errbuf);
    if(pd == NULL){
        fprintf(stderr,"pcap_open_live(%s):%s\n",DEFAULT_ETH, errbuf);
        exit(1);
    }

    dlt = pcap_datalink(pd);
    if(dlt == DLT_EN10MB) {
        //printf("DLT_EN10MB\n");
        packet_handler = handle_eth_packet;
    }
    return 0;
}
