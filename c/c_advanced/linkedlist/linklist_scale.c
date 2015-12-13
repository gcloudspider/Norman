/*########################################################
##File Name: linklist_scale.c
##Created Time:2015年12月13日 星期日 20时02分06秒
##Author: Norman 
##Description: 标尺快速找到单链表的中间结点
##
##Issue: 
##
##Analyze:  1.设置两个工作指针*search *mid都指向单链表的头节点
##          2.*search的移动速度是*mid的2倍,当*search指向末尾节点时
##          3.mid刚好在中间
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

//初始化链表
Status InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));
    if(!(*L)){
        return 0;
    }
    (*L)->next = NULL;
    return 1;
}

//获取链表长度
int getlength(LinkList L){
    int i=0;
    LinkList p = L->next;
    while(p){
        i++;
        p= p->next;
    }
    return i;
}

//创建链表(头插法)
void create_linklist_head(LinkList *L,int n){
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for(i=0;i<n;i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

int visit(ElemType c){
    printf("->%d",c);
    return 1;
}

void printlinklist(LinkList L){
    LinkList p;
    p = L->next;
    while(p){
        visit(p->data);
        p=p->next;
    }
    printf("\n");
}

//创建链表(尾插法)
void create_linklist_tail(LinkList *L,int n){
    LinkList p,r;
    int i;
    srand(time(0));
    *L = (LinkList) malloc(sizeof(Node));
    r = *L;
    for(i=0;i<n;i++){
        p = (Node*)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

//插入链表
void insert_link_list(LinkList *L,int pos,int value){
    int j;
    LinkList p,s;
    p = *L;
    j= 1;
    while(p&&j<1){
        p = p->next;
        ++j;
    }
    
    if(!p || j>pos)
        return ;
    s = (LinkList)malloc(sizeof(Node));
    s->data = value;
    s->next = p->next;
    p->next = s;
    return ;
}

//删除节点
void del_link_list(LinkList *L,int pos){
    int j;
    LinkList p,q;
    p =*L;
    j =1;
    while(p->next && j<pos){
        p = p->next;
        ++j;
    }
    if(!(p->next)||j>pos)
        return ;
    q = p->next;
    p->next = q->next;
    //*e = q->data;
    free(q);
    return ;
}

//获取链表节点数据
void getdata_link_list(LinkList L,int pos,ElemType *e){
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while(p&&j<pos){
        p = p->next;
        ++j;
    }
    if(!p||j>pos)
        return;
    *e = p->data;
    return ;
}
//查找链表中元素
int locateElem(LinkList L,int pos){
    int i=0;
    LinkList p = L->next;
    while(p){
        i++;
        if(p->data == pos)
            return i;
        p = p->next;
    }
    return 0;
}

//清空链表
int clear_link_list(LinkList* L){
    int j;
    LinkList p,q; 
    return ;
}

int main(){
    LinkList L;
    Status i;
    int j,k,pos,value;
    int opp;
    ElemType e;

    i=InitList(&L);

    printf("链表初始化完成,length=%d\n",getlength(L));
    printf("1.创建链表(头插法)\n");
    printf("2.创建链表(尾插法)\n");
    printf("3.遍历链表\n");
    printf("4.插入链表\n");
    printf("5.删除链表节点\n");
    printf("6.获取节点数据\n");
    printf("7.查找链表中是否存在该数\n");
    printf("8.置空链表\n");
    printf("9.链表反转逆序\n");
    printf("10.求链表倒数第N个数\n");
    printf("11.找到链表的中间节点\n");
    printf("12.退出\n");
    printf("请输入你的选择:");
    while(opp != 12){
        scanf("%d",&opp);
        switch(opp){
        case 1:
            create_linklist_head(&L,10);
            printf("创建链表(头插法):\n");
            printlinklist(L);
            printf("\n");
            break;
        case 2:
            create_linklist_tail(&L,10);
            printf("创建链表(尾插法):\n");
            printlinklist(L);
            printf("\n");
            break;
        case 3:
            printlinklist(L);
            printf("\n");
            break;
        case 4:
            printf("输入要插入链表的位置:");
            scanf("%d",&pos);
            printf("输入要插入的元素:");
            scanf("%d",&value);
            insert_link_list(&L,pos,value);
            printlinklist(L);
            printf("\n");
            break;
        case 5:
            printf("输入要删除的元素:");
            scanf("%d",&pos);
            del_link_list(&L,pos);
            printf("删除第%d个元素成功,现在链表为:\n",pos);
            printlinklist(L);
            printf("\n");
            break;
        case 6:
            printf("输入你需要获取的元素:");
            scanf("%d",&pos);
            getdata_link_list(L,pos,&e);
            printf("第%d个元素的值为:%d\n",pos,e);
            printf("\n");
            break;
        case 7:
            printf("输入要查找的数:");
            scanf("%d",&pos);
            k = locateElem(L,pos);
            if(k){
                printf("第%d个元素的值为:%d\n",k,pos);
            } else {
                printf("没有值为%d的元素\n",pos);
            }
            printf("\n");
            break;
        case 8:
            i = clear_link_list(&L);
            printf("清空链表,length=%d\n",getlength(L));
            printlinklist(L);
            printf("\n");
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            exit(0);
            break;
        default:
            break;
        }   
    }

}

