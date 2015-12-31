#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include "../include/iniparser.h"

int main(){
    int status;
    int tmp;
    dictionary * ini;
    ini = iniparser_load("../conf/didi.conf");
    if (ini==NULL){
        fprintf(stderr, "cannot parse file: %s\n", "switch.ini");
        return -1;
    }
    iniparser_dump(ini, stderr);

    /* Get attributes */
    tmp = iniparser_getint(ini, "mirror:mport", -1);
    printf("mport:         [%d]\n", tmp);

    tmp = iniparser_getint(ini, "igmp:mport", -1);
    printf("mport:         [%d]\n", tmp);

    tmp = iniparser_getint(ini, "flooding:multicast", -1);
    printf("multicast:     [%d]\n", tmp);

    tmp = iniparser_getint(ini, "flooding:unicast", -1);
    printf("unicast:       [%d]\n", tmp);
    iniparser_freedict(ini);
    return 0;
} 
