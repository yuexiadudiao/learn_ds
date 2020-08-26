/*
 * Author:yin
 * Date  :2020-08-26
 * About :基于数组实现一个堆
 */


#include<stdio.h>

#define HEAP_SIZE_MAX 100

void heap_swap(int heap[], int pos1, int pos2)
{
    int tmp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = tmp;
}

/* 向上调整堆 */
void heap_adjust_up(int heap[], int cur_pos)
{
    if(1 == cur_pos)
        return ;
    
    int father_pos = cur_pos / 2;
    if(heap[cur_pos] > heap[father_pos])
        heap_swap(heap, cur_pos, father_pos);

    heap_adjust_up(heap, father_pos);
}

/* 向堆中插入一个元素 */
void heap_insert(int heap[], int data)
{
    heap[heap[0]+1] = data;
    heap[0]++;

    heap_adjust_up(heap, heap[0]);
}

/* 打印堆 */
void heap_print(int heap[])
{
    printf("heap_size(%d):", heap[0]);
    for(int i = 1; i <= heap[0] ; i++)
    {
        if(i == heap[0])
            printf("%d\n", heap[i]);
        else
            printf("%d ", heap[i]);
    }
}

void heap_pop()
{
    
}

int main()
{
    int myheap[HEAP_SIZE_MAX+1] = {0};

    heap_insert(myheap, 2);
    heap_print(myheap);

    heap_insert(myheap, 3);
    heap_print(myheap);

    heap_insert(myheap, 1);
    heap_print(myheap);

    heap_insert(myheap, 8);
    heap_print(myheap);

    return 0;
}