/*########################################################
##File Name: linklist_single.c
##Created Time:2015年11月23日 星期一 10时27分49秒
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

typedef struct student {
    int stu_no;
    char stu_name[64];          //1[warning].char *stu_name; 待测试
    int stu_age;
    int stu_score;
    struct student *next;       //2[warning]: 不能用STU *next
}STU;


int main() {
    
    STU *head = NULL;           //3[warning]: 记得赋值
    STU *pn;

    char ch;                    //4[warning]: getchar() 返回值是char

    //输入数据
    while(1) {
        //申请内存空间   
        pn = malloc(sizeof(struct student)); //5[warning]: mailloc(sizeof())  一定要sizeof()
        if(pn == NULL) {
            printf("malloc pn failed!\n");
            return -1;
        }
        printf("%p\n",pn);
        printf("please input student infomation\n");
        printf("studetnum\tstudentname\tstudentage\tstudentscore\n");

        /*
        *
        * 场景:当输入 1001sdf   zhangs02   100  100 (buff的访问方式)
        *
        * */

        scanf("%d%s%d%d",
              &pn->stu_no,                       //6[warning]: 逗号不是分号
             pn->stu_name,
             &pn->stu_age,
             &pn->stu_score
             );
        while((ch=getchar()) != '\n');
        
        //head->next [error:]
        //head->next 因为此是head初始值为NULL,若去访问next出现段错误
        pn->next = head;
        head = pn;

        printf("Is continue ? please input yes/no(Y/N):\n");
clear_enter:
        ch = getchar();
        if(ch == 'n' || ch =='N')
            break;
        else if(ch == '\n' ||ch == 'y' || ch == 'Y')
            continue;
        else 
            goto clear_enter;
    }

    printf("studetnum\tstudentname\tstudentage\tstudentscore\n");

    pn = head;           //原因

    while(1) {
        printf("%d\t%s\t%d\t%d\n",
              pn->stu_no,
               pn->stu_name,
               pn->stu_age,
               pn->stu_score
              );

        pn = pn->next;
        
        if(pn)
            continue;
        else 
            break;
    }


    return 0;
}
