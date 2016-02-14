/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include <stdio.h>
#include <stdlib.h>
#define M 30
#define N 2*M-1
#define MAXWEIGHT 9999
typedef struct{
    int weight;
    int parent;
    int lch;
    int rch;
}Htype;

int k;
void Huftree(Htype hf[]){
    int i,j,m1,m2,n1,n2;
    printf("input the number of leaf:");
    scanf("%d",&k);
    for(i=0;i<2*k-1;i++){
        hf[i].weight = 0;
        hf[i].parent = -1;
        hf[i].lch = -1;
        hf[i].rch = -1;
    }
    printf("input the weight of leaf: ");
    for(i=0;i<k;i++)
        scanf("%d",&hf[i].weight);

    for(i=0;i<k-1;i++){
        m1 = m2 = MAXWEIGHT;
        n1 = n2 = 0;
        for(j=0;j<k+i;j++){
            if(hf[j].parent == -1 && hf[j].weight <m1){
                m2 = m1;
                n2 = n1;
                m1 = hf[j].weight;
                n1 = j;
            }
            else if(hf[j].parent == -1 && hf[j].weight < m2){
                m2 = hf[j].weight;
                n2 = j;
            }
        }

        hf[n1].parent = k+i;
        hf[n2].parent = k+i;
        hf[k+i].weight = hf[n1].weight + hf[n2].weight;

        hf[k+i].lch = n1;
        hf[k+i].rch = n2;
    }
}

int main(){
    Htype hf[N];
    int i = 0;
    //clrscr();
    Huftree(hf);
    for(i=0;i<2*k-1;i++){
        printf("%3d%3d%3d%3d\n",hf[i].weight,hf[i].lch,hf[i].rch,hf[i].parent);
    }
}
