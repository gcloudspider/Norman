/*########################################################
##File Name: array_bsearch.c
##Created Time:2015年12月14日 星期一 08时57分54秒
##Author: Norman 
##Description: 二分搜索查找 
##              lfind 与lsearch 当查找关键数据不在base数组中.lfind不做任何事,而lsearch则将该数据添加到base数组
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
#include<string.h>
#include<search.h>

int compare(char ** arg1,char ** arg2){
    return strcmp(*arg1,*arg2);
}

int main(){
    char *arr[]={"dog","pig","horse","cat","human","rat","cow","goat"};
    char **result;
    char *key = "cat";
    int i;
    
    qsort((void*)arr,sizeof(arr)/sizeof(arr[0]),sizeof(char *),(int(*)(const void*,const void*))compare);

    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
        printf("%s",arr[i]);

    result = (char**)bsearch((char*) &key,(char*)arr,sizeof(arr)/sizeof(arr[0]),sizeof(char *),(int(*)(const void*,const void*))compare);

    if(result)
        printf("\n%s found at %Fp\n",*result,result);
    else 
        printf("\nCat not found!\n");

}
