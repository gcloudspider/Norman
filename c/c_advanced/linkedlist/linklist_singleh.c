/*########################################################
##File Name: linklist_single.c
##Created Time:2015年11月23日 星期一 10时27分49秒
##Author: Norman 
##Description: 头插法
##
##Issue: 
##
##Analyze:
##
##      算法分析:
##          创建链表,读入数据,生成新结点,将读入数据存在到新结点数据域。
##          将新结点插入到当前链表的表头结点之后
##
##
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


    printf("please input student infomation\n");
    printf("num\tname\tage\tscore\n");

    //输入数据
    while(1) {
        //申请内存空间   
        pn = malloc(sizeof(STU)); //5[warning]: mailloc(sizeof())  一定要sizeof()
        if(pn == NULL) {
            printf("malloc pn failed!\n");
            return -1;
        }
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

        printf("Is continue ? please input yes/no(Y/N): ");
clear_enter:
        ch = getchar();
        if(ch == 'n' || ch =='N'){
            break;
        } else if(ch == '\n' ||ch == 'y' || ch == 'Y') {
            continue;
        } else { 
            goto clear_enter;
        }   
    }

    printf("num\tname\tage\tscore\n");

    pn = head;           //原因

    while(1) {
        printf("%d\t%s\t%d\t%d\n",
              pn->stu_no,
               pn->stu_name,
               pn->stu_age,
               pn->stu_score
              );
        pn = pn->next;
        
        if(pn) {
            continue;
        } else {
            break;
        } 
    }

    //释放
    while(head) {
        pn = head->next;
        free(head);
        head=pn;
    }

    return 0;
}
