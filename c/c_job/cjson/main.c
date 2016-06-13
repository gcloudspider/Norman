#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
int main(int argc, char **argv)
{
    char *s = "[{\"command_id\":0,\"command_param\":\"32625\",\"id\":86,\"is_finished\":1}]\n";
    //char *s = "[{\"name\":\"xiao hong\",\"age\":10}]\n";
    cJSON *root = cJSON_Parse(s);
    printf("%d\n",root->type);
    if(!root) {
        printf("get root faild !\n");
        return -1;
    }
    //cJSON *js_list = cJSON_GetObjectItem(root, "list");
    //if(!js_list){
    //    printf("no list!\n");
    //    return -1;
    //}
    int array_size = cJSON_GetArraySize(root);
    printf("array size is %d\n",array_size);
    int i = 0;
    cJSON *item,*it, *js_name, *js_age;
    char *p  = NULL;
    for(i=0; i< array_size; i++) {
        item = cJSON_GetArrayItem(root, i);
        if(!item) {
            //TODO...
        }
        p = cJSON_PrintUnformatted(item);
        it = cJSON_Parse(p);
        if(!it)
            continue ;
        js_name = cJSON_GetObjectItem(it, "command_id");
        printf("command_id is %s\n",js_name->valueint);
        js_age = cJSON_GetObjectItem(it, "command_param");
        printf("command_param is %d\n",js_age->valueint);

    }

    if(root)
        cJSON_Delete(root);
    return 0;
}
