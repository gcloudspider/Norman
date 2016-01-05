/*########################################################
##File Name: test_uuid_generate.c
##Created Time:2016年01月05日 星期二 10时13分56秒
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
/*libuuid是一个用于生成UUID的C库，具体用法参考http://linux.die.net/man/3/libuuid，示例如下：*/
//sudo apt-get install uuid-dev

#include <stdio.h>
#include <uuid/uuid.h>
 
int main(int argc, char **argv)
{
    uuid_t uuid;
    char str[36];
             
    uuid_generate(uuid);
    uuid_unparse(uuid, str);
              
    printf("%s\n", str);
                         
    return 0;
}
