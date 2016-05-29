#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>

#define CAP_LEN 2048
#define FILENAME "rh"
#define _DEBUG_
int main() {
    bpf_u_int32 localnet,netmask;
    struct bpf_program fcode;
    pcap_handler printer;
    pcap_dumper_t*p;
    char ebuf[PCAP_ERRBUF_SIZE];
    char * device;
    u_char * pcap_userdata;
    pcap_t * pd;
    int dev_flag=1;
    int cap_len=CAP_LEN;
    int i;
    device=pcap_lookupdev(ebuf);
    if (device == NULL)
        exit(printf("%s n", ebuf));
#ifdef _DEBUG_
    printf("device is %s \n",device);
#endif
    pd=pcap_open_live(device,cap_len,dev_flag,1000,ebuf);
    if(pd == NULL)
        exit(printf("%s\n",ebuf));
    i=pcap_snapshot(pd);
    if(cap_len < i) {
        printf("snaplen raised from %d to %d \n", cap_len, i);
        cap_len=i;
    }
    if(pcap_lookupnet(device, &localnet, &netmask, ebuf) < 0) {
        localnet=0;
        netmask=0;
        printf("%s\n", ebuf);
    }
    if (pcap_compile(pd, &fcode, "", 1, netmask) < 0)
        exit(printf("Error %s\n","pcap_compile"));
    if (pcap_setfilter(pd,&fcode) < 0)
        exit(printf("Error %s\n","pcap_setfilter"));
    p=pcap_dump_open(pd,FILENAME);
    if(p == NULL)
        exit(printf("Error:%s\n","pcap_dump_open"));
    printer=pcap_dump;
    pcap_userdata=(u_char *)p;
    if(pcap_loop(pd, -1, printer, pcap_userdata) < 0)
        exit(printf("Error, %s\n","pcap_loop"));
    pcap_close(pd);
    exit(0);
}
