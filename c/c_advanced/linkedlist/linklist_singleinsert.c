/*########################################################
##File Name: linklist_singleinsert.c
##Created Time:2015年11月24日 星期二 20时57分44秒
##Author: Norman 
##Description: 
##
##Issue:有序的链表,插入一个节点后依然有序 
##
##Analyze: 
##      1.添加一个节点pn
##      2.根据节点p的num 找到>=p <=p->next
##      3.将p->next = pn
##      4.将pn的pn->next = p->next
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include<stdlib.h>
