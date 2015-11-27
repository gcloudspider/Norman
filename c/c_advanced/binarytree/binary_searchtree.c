/*########################################################
##File Name: binary_searchtree.c
##Created Time:2015年11月26日 星期四 11时00分19秒
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

typedef struct binTree{
    char d;
    struct binTree *l;
    struct binTree *r;
}T;


void create_binary_tree(T** root) {
    char ch;

    ch=getchar();
    while(getchar()!='\n');
    
    if(ch=='#') {
       *root = NULL;
        return ;
    } else {
        *root = malloc(sizeof(T));
        (*root)->d = ch;
        printf("Create %c left child tree:\n",ch);
        create_binary_tree(&(*root)->l);
        printf("Create %c right chile tree:\n",ch);
        create_binary_tree(&(*root)->r);
    }
}

void show_binary_tree(T* root) {
    if(root) {
        printf("%c",root->d);
        show_binary_tree(root->l);
        show_binary_tree(root->r);
    }else {
        printf("#");
    }
}

void search_binary_tree(T* root,int searnum){
    
    if(root == NULL) return ;

    if(root->d == searnum) {
        printf("key is in tree!\n");
        return;
    } else if(root->d > searnum ) {
        search_binary_tree(root->l,searnum);
    } else {
        search_binary_tree(root->r,searnum);
    }
}

int main() {
    T* root = NULL;
    create_binary_tree(&root);

    show_binary_tree(root);
    printf("\n");
    char searnum;
    searnum = getchar();

    search_binary_tree(root,searnum);
    return 0;
}
