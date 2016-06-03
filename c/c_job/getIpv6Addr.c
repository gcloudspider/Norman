#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>
#define _PATH_PROCNET_IFINET6 "/proc/net/if_inet6"
        
#ifndef IN6_IS_ADDR_UNSPECIFIED
#define IN6_IS_ADDR_UNSPECIFIED(a) \
        (((__u32 *) (a))[0] == 0 && ((__u32 *) (a))[1] == 0 && \
                 ((__u32 *) (a))[2] == 0 && ((__u32 *) (a))[3] == 0)
#endif

int INET6_rresolve(char *name, struct sockaddr_in6 *sin6, int numeric) {
    int s;

    /* Grmpf. -FvK */
    if (sin6->sin6_family != AF_INET6) {
        fprintf(stderr, ("rresolve: unsupport address family %d !\n"),
                sin6->sin6_family);
        errno = EAFNOSUPPORT;
        return (-1);
    }
    if (numeric & 0x7FFF) {
        inet_ntop(AF_INET6, &sin6->sin6_addr, name, 80);
        return (0);
    }
    if (IN6_IS_ADDR_UNSPECIFIED(&sin6->sin6_addr)) {
        if (numeric & 0x8000)
            strcpy(name, "default");
        else
            strcpy(name, "*");
        return (0);
    }

    if ((s = getnameinfo((struct sockaddr *) sin6, sizeof(struct sockaddr_in6),
                    name, 255 /* !! */ , NULL, 0, 0))) {
        fputs("getnameinfo failed\n", stderr);
        return -1;
    }
    return (0);
}

char *safe_strncpy(char *dst, const char *src, size_t size)
{   
    dst[size-1] = '\0';
    return strncpy(dst,src,size-1);   
}

char* inet6_sprint(struct sockaddr *sap, int numeric)
{
    static char buff[128];

    if (sap->sa_family == 0xFFFF || sap->sa_family == 0)
        return safe_strncpy(buff, ("[NONE SET]"), sizeof(buff));
    if (INET6_rresolve(buff, (struct sockaddr_in6 *) sap, numeric) != 0)
        return safe_strncpy(buff, ("[UNKNOWN]"), sizeof(buff));
    return (buff);
}


int INET6_resolve(char *name, struct sockaddr_in6 *sin6)
{
    struct addrinfo req, *ai;
    int s;

    memset (&req, '\0', sizeof req);
    req.ai_family = AF_INET6;
    if ((s = getaddrinfo(name, NULL, &req, &ai))) {
        fprintf(stderr, "getaddrinfo: %s: %d\n", name, s);
        return -1;
    }
    memcpy(sin6, ai->ai_addr, sizeof(struct sockaddr_in6));

    freeaddrinfo(ai);

    return (0);
}


int INET6_getsock(char *bufp, struct sockaddr *sap)
{
    struct sockaddr_in6 *sin6;

    sin6 = (struct sockaddr_in6 *) sap;
    sin6->sin6_family = AF_INET6;
    sin6->sin6_port = 0;

    if (inet_pton(AF_INET6, bufp, sin6->sin6_addr.s6_addr) <= 0)
        return (-1);

    return 16;
}

int inet6_input(int type, char *bufp, struct sockaddr *sap)
{
    switch (type) {
        case 1:
            return (INET6_getsock(bufp, sap));
        default:
            return (INET6_resolve(bufp, (struct sockaddr_in6 *) sap));
    }
}

struct aftype {
    char *name;
    char *title;
    int af;
    int alen;
    char *(*print) (unsigned char *);
    char *(*sprint) (struct sockaddr *, int numeric);
    int (*input) (int type, char *bufp, struct sockaddr *);
    void (*herror) (char *text);
    int (*rprint) (int options);
    int (*rinput) (int typ, int ext, char **argv);

    /* may modify src */
    int (*getmask) (char *src, struct sockaddr * mask, char *name);

    int fd;
    char *flag_file;
};

int main(){
    FILE *f;
    char addr6[40], devname[20];
    struct sockaddr_in6 sap;
    int plen, scope, dad_status, if_idx;
    struct aftype inet6_aftype;
    char addr6p[8][5];
    if ((f = fopen(_PATH_PROCNET_IFINET6, "r")) != NULL) {
        while (fscanf(f, "%4s%4s%4s%4s%4s%4s%4s%4s %02x %02x %02x %02x %20s\n",
                    addr6p[0], addr6p[1], addr6p[2], addr6p[3],
                    addr6p[4], addr6p[5], addr6p[6], addr6p[7],
                    &if_idx, &plen, &scope, &dad_status, devname) != EOF) {
            if (!strcmp(devname, "eth0")){
                sprintf(addr6, "%s:%s:%s:%s:%s:%s:%s:%s",
                        addr6p[0], addr6p[1], addr6p[2], addr6p[3],
                        addr6p[4], addr6p[5], addr6p[6], addr6p[7]);
                inet6_input(1, addr6, (struct sockaddr *) &sap);
                printf(("inet6 addr: %s/%d\n"),inet6_sprint((struct sockaddr *) &sap, 1), plen);
            }
        }
    }
}
