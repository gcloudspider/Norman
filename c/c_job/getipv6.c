#include <stdio.h>
#include <string.h>
#include <error.h>
#include <stdlib.h>

#define DEBUG
//#define UNSUPPORT_IFADDRS

/* struct in6_addr */
#include <netinet/in.h>
/* getifaddrs, freeifaddrs */
#include <sys/types.h>
#ifndef UNSUPPORT_IFADDRS
#include <ifaddrs.h>
#endif
/* inet_ntop, inet_pton */
#include <arpa/inet.h>

#if defined(DEBUG)
#define DG(a, b...) printf("[%s][%s][%d]"a, __FILE__, __func__, __LINE__, ##b)
#else
#define DG(a, b...)
#endif

#define ER(a, b...) printf("[%s][%s][%d]"a, __FILE__, __func__, __LINE__, ##b)

#ifndef UNSUPPORT_IFADDRS
/**
* Whlie head file  is not existed in you include directory, just define
* macro UNSUPPORT_IFADDRS to disable this function.
* Because of function getifaddrs() and freeifaddrs() are declared in this head file,
* the function can't pass compiling process if lack  in your system.
*/
int get_linklocal_ipv6addr(struct in6_addr *addr6, char *iface)
{
        struct ifaddrs *ifa, *p;
        int family;
        char address[200];

        if (!addr6 || !iface) {
                ER("addr6 and iface can't be NULL!\n");
                return -1;
        }

        if (getifaddrs(&ifa)) {
                ER("");
                perror("getifaddrs error");
                return -1;
        }

        for (p = ifa; p != NULL; p = p->ifa_next) {
                DG("ifa_name = %s, family = 0x%X(%s)\n", p->ifa_name, family,
                        (family == AF_PACKET) ? "AF_PACKET" :
                        (family == AF_INET) ?   "AF_INET" :
                        (family == AF_INET6) ?  "AF_INET6" : "");

                family = p->ifa_addr->sa_family;
                /* Just check IPv6 address */
                if (family != AF_INET6)
                        continue;

                *addr6 = ((struct sockaddr_in6 *)(p->ifa_addr))->sin6_addr;
                /* Just get IPv6 linklocal address of the interface */
                if (!strcmp(iface, p->ifa_name) && IN6_IS_ADDR_LINKLOCAL(addr6)) {
                        if (inet_ntop(AF_INET6, addr6, address, sizeof(address))) {
                                DG("find out %s's linklocal IPv6 address: %s\n", iface, address);
                        }
                        break;
                }
        }

        freeifaddrs(ifa);
        return 0;
}
#else
/**
* If head file  is not existed in your system, you could get information of IPv6 address
* in file /proc/net/if_inet6.
*
* Contents of file "/proc/net/if_inet6" like as below:
* 00000000000000000000000000000001 01 80 10 80       lo
* fe8000000000000032469afffe08aa0f 08 40 20 80     ath0
* fe8000000000000032469afffe08aa0f 07 40 20 80    wifi0
* fe8000000000000032469afffe08aa0f 05 40 20 80     eth1
* fe8000000000000032469afffe08aa0f 03 40 20 80      br0
* fe8000000000000032469afffe08aa10 04 40 20 80     eth0
*
* +------------------------------+ ++ ++ ++ ++    +---+
* |                                |  |  |  |     |
* 1                                2  3  4  5     6
*
* There are 6 row items parameters:
* 1 => IPv6 address without ':'
* 2 => Interface index
* 3 => Length of prefix
* 4 => Scope value (see kernel source "include/net/ipv6.h" and "net/ipv6/addrconf.c")
* 5 => Interface flags (see kernel source "include/linux/rtnetlink.h" and "net/ipv6/addrconf.c")
* 6 => Device name
*
* Note that all values of row 1~5 are hexadecimal string
*/
int get_linklocal_ipv6addr(struct in6_addr *addr6, char *iface)
{
#define IF_INET6 "/proc/net/if_inet6"
        char str[128], address[64];
        char *addr, *index, *prefix, *scope, *flags, *name;
        char *delim = " \t\n", *p, *q;
        FILE *fp;
        int count;

        if (!addr6 || !iface) {
                ER("addr6 and iface can't be NULL!\n");
                return -1;
        }

        if (NULL == (fp = fopen(IF_INET6, "r"))) {
                ER("");
                perror("fopen error");
                return -1;
        }

        #define IPV6_ADDR_LINKLOCAL 0x0020U
        while (fgets(str, sizeof(str), fp)) {
                DG("str:%s", str);
                addr = strtok(str, delim);
                index = strtok(NULL, delim);
                prefix = strtok(NULL, delim);
                scope = strtok(NULL, delim);
                flags = strtok(NULL, delim);
                name = strtok(NULL, delim);
                DG("addr:%s, index:0x%s, prefix:0x%s, scope:0x%s, flags:0x%s, name:%s\n",
                        addr, index, prefix, scope, flags, name);

                if (strcmp(name, iface))
                        continue;

                /* Just get IPv6 linklocal address */
                if (IPV6_ADDR_LINKLOCAL != (unsigned int)strtoul(scope, NULL, 16))
                        continue;

                memset(address, 0x00, sizeof(address));
                p = addr;
                q = address;
                count = 0;
                while (*p != '') {
                        if (count == 4) {
                                *q++ = ':';
                                count = 0;
                        }
                        *q++ = *p++;
                        count++;
                }
                DG("find out %s's linklocal IPv6 address: %s\n", iface, address);

                inet_pton(AF_INET6, address, addr6);
                break;
        }
        #undef IPV6_ADDR_LINKLOCAL

        fclose(fp);
        return 0;
}
#endif

int main (int argc, char *argv[])
{
        struct in6_addr addr6;
        char *ifname = "eth0";
        char address[64];

        if (get_linklocal_ipv6addr(&addr6, ifname)) {
                printf("\nGet IPv6 linklocal address of %s failed \n", ifname);
                return -1;
        }
        if (inet_ntop(AF_INET6, &addr6, address, sizeof(address)))
                printf("\nIPv6 linklocal address of %s is %s \n", ifname, address);

        return 0;
}
