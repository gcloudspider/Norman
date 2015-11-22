/*########################################################
##File Name: point_calloc.c
##Created Time:2015年11月22日 星期日 11时23分14秒
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
#include<stdlib.h>
#include<string.h>

int main() {
    
    int *pi = calloc(5,sizeof(int));            //calloc比malloc慢

    printf("%p\n",pi);

    int *pii = malloc(5*sizeof(int));
    memset(pii,0,5*sizeof(int));

    free(pi);
    free(pii);
    free(pi);

    return 0;
}
