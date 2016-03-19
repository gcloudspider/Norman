/**
* Create Date:2016年03月15日星期二 10:09:47
* 
* Author:Norman
* 
* Description: 
*/

1.用二叉树结构来存储每个单词,一个单词对应一个节点
    原因:二叉树先天具有排序功能,不存在重复节点

    结构体:
        struct Node {
            string word;            //单词
            int count;              //单词出现次数
            set<int> lines;         //单词出现所在行号
            Node* left;
            Node* right;
        };

2.循环从文件中读取单词,每次读取一个单词,直到文件末尾
每读一个单词就插入到二叉树中
    函数:
        int getWord(char* word,int maxLen);
            1.返回值表示读取状态(文件末尾返回EOF)
            2.参数 word保存读取的单词
            3.参数 maxLen 为word的长度

        Node* insert(Node* root,string word)

    伪代码如下:


3.用中序的方式遍历二叉树,并按格式要求打印各节点的数据

