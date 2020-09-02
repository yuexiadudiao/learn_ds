/*
 * Author:yin
 * Date  :2020-09-01
 * About :实现一个英语单词的trie树
 */

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<iostream>

#define CHARACTER_NUM 26

typedef struct TrieTreeNode{
    char ch;
    struct TrieTreeNode *subtree[26];
}TrieTreeNode, *pTrieTreeNode;

/* 插入一个单词 */
void TrieTree_AddWord(char str[])
{

}

/* 查找一个单词 */
void TrieTree_FindWord(char str[])
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
    if(NULL == pTree)
        return ;

    for(int i=0 ; i < CHARACTER_NUM ; i++)
    {
        if(NULL != pTree->subtree[i])
        {
            TrieTree_Delete(pTree->subtree[i]);
        }        
    }

    free(pTree);
}

int main()
{
    pTrieTreeNode mytree = NULL;
    TrieTree_Create(&mytree);

    

    return 0;
}