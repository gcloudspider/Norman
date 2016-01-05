/*########################################################
##File Name: test_uuid_custom.c
##Created Time:2016年01月05日 星期二 10时28分41秒
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
/********方法一**********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Create random UUID
 *
 * @param buf - buffer to be filled with the uuid string
 */

char *random_uuid(char buf[37]) {
    const char *c = "89ab";
    char *p = buf;
    int n;
    for( n = 0; n < 16; ++n ){
        int b = rand()%255;
        switch( n ){
            case 6:
                sprintf(p, "4%x", b%15 );
                break;
            case 8:
                sprintf(p, "%c%x", c[rand()%strlen(c)], b%15 );
                break;
            default:
                sprintf(p, "%02x", b);
                break;
            }
                   
        p += 2;
        switch( n ){
            case 3:
            case 5:
            case 7:
            case 9:
                *p++ = '-';
                break;
        }
    }    
    *p = 0;
    return buf;
}
 
void main()
{
    char guid[37];
    random_uuid(guid);
    printf("guid = %s\n", guid);
    random_uuid(guid);
    printf("guid = %s\n", guid);
    random_uuid(guid);
    printf("guid = %s\n", guid);
    random_uuid(guid);
    printf("guid = %s\n", guid);
}
