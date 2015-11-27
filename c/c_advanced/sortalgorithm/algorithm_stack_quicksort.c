/*########################################################
##File Name: algorithm_quicksortq.c
##Created Time:2015年11月27日 星期五 08时29分17秒
##Author: Norman 
##Description: 快速排序问题
##
##Issue: 在linux系统下定义NUM 10000000时出现段错误!而使用NUM 1000000会正常
##
##Analyze: 
##      1.在linux系统下用ulimit -s 查看8192
##      2.系统默认给每个程序分配的大概是8M的栈空间
##
##Induction:
##      测试:使用非递归方式实现快速排序算法(用栈来消除递归)
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define MAX_TOP 100
#define NUM 500L

struct Region {
    long left;
    long right;
};

struct Stack{
    struct Region reg[MAX_TOP+1];
    long top;
};

void init_stack(struct Stack *s) {
    s->top = -1;
}


void push_stack(struct Stack *s,struct Region r) {
    if(s->top == MAX_TOP) {
        fprintf(stderr,"Stack overflow!\n");
        exit(0);
    }
    s->reg[++s->top] = r;
}

struct Region pop_stack(struct Stack *s) {
    if(s->top == -1) {
        fprintf(stderr,"Stack underflow!\n");
        exit(0);
    }
}

int is_stack_empty(struct Stack *s) {
    return (s->top == -1);
}

long partition(double a[],long left,long right) {
    double base = a[left];

    while(left<right) {
        while(left<right && a[right] >base)
            --right;
        a[left] = a[right];
        while(left<right && a[left] <base)
            ++left;
        a[right] = a[left];
    }
    a[left] = base;

    return left;
}

void nr_qsort(double a[],long left,long right) {
    struct Stack s;
    struct Region region,regionlow,regionhi;
    long p;

    init_stack(&s);
    region.left = left;
    region.right = right;
    push_stack(&s,region);

    while(!is_stack_empty(&s)) {
        region = pop_stack(&s);
        p = partition(a,region.left,region.right);
        if(p-1 >region.left) {
            regionlow.left = region.left;
            regionlow.right = p-1;
            push_stack(&s,regionlow);
        }
        if(region.right >p +1) {
            regionhi.left = p+1;
            regionhi.right = region.right;
            push_stack(&s,regionhi);
        }
    }
}


/* ----递归实现快速排序
void quick_sort(double a[],long left,long right) {
    long i = left;
    long j = right;
    double mid = a[(i+j)/2];

    while(i<=j) {
        while(a[i]<mid)
            ++i;
        while(mid < a[j])
            --j;
        if(i <= j) {
            double t = a[i];
            a[i] = a[j];
            a[j] = t;
            ++i;
            --j;
        }
    }

    if(i<right) quick_sort(a,i,right);
    if(left<j) quick_sort(a,left,j);
}
*/
int main() {
    clock_t t_s,t_e;
    long i;
    double a[NUM];

    srand(time(NULL));
    for(i=0;i<NUM;++i) {
        //a[i] = rand();
        a[i] = rand() % 1000000;
    }

    t_s = clock();
    //quick_sort(a,0,NUM-1);
    nr_qsort(a,0,NUM-1);
    t_e = clock();
    double t = (t_e-t_s)/(double)CLOCKS_PER_SEC;

    printf("Non Recursive Quick sort %ld items used time:%fs\n",NUM,t);
    //printf("Quick sort %d items used time:%fs\n",NUM,t);
    return 0;
}
