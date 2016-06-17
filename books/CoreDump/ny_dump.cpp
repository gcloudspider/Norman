#include<stdio.h>
#include<stdlib.h>

int recurse(int num,int level){
    return num+level;
}

int main(){
    int i=0;
    int j =10;
    for(i;i<j;i++){
        printf("%d\n",recurse(i,j--));
    }
    return 0;
}
