/*
 * Author:yin
 * Date  :2020-09-01
 * About :实现一个英语单词的trie树
 */

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<iostream>

#define CHARACTER_NUM 26;

typedef struct TrieTreeNode{
    char ch;
    struct TrieTreeNode *subtree[26];
}TrieTreeNode, *pTrieTreeNode;

void TrieTree_AddWord(char str[])
{

}

/* 创建一个空的trie树 */
void TrieTree_Create(pTrieTreeNode* ppNode)
{
    pTrieTreeNode pCurNode = NULL;
    if(NULL == ppNode)
        return ;

    *ppNode = (pTrieTreeNode)calloc(1, sizeof(TrieTreeNode));
    pCurNode = *ppNode;
    pCurNode->ch = 0;
    memset(pCurNode->subtree, 0, sizeof(pCurNode->subtree));
}

/* 删除一颗trie树 */
void TrieTree_Delete(pTrieTreeNode pTree)
{

}

int main()
{
    pTrieTreeNode mytree = NULL;
    TrieTree_Create(&mytree);

    std::cout<<"ee"<<std::endl;

    return 0;
}