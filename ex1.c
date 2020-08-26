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

/* 向下调整 */
void heap_adjust_down(int heap[], int cur_pos)
{
    int son_left = (2*cur_pos <= heap[0])?(2*cur_pos):0;
    int son_right = (2*cur_pos+1<=heap[0])?(2*cur_pos+1):0;
    int max_id = 0;

    if(!son_left && !son_right)
        return ;
    
    if(son_left && son_right)
    {
        if(heap[son_left] > heap[son_right])
            max_id = son_left;
        else
            max_id = son_right;
        
        goto out;
    }

    max_id = son_left;
out:
    heap_swap(heap, cur_pos, max_id);
    heap_adjust_down(heap, max_id);
}

void heap_adjust_update(int heap[], int cur_pos, int data)
{
    int old_var = heap[cur_pos];
    heap[cur_pos] = data;

    /* 如果是根节点 */
    if(1 == cur_pos)
        return heap_adjust_down(heap, cur_pos);    

    /* 如果是叶子节点 */
    if(2*cur_pos > heap[0])
        return heap_adjust_up(heap, cur_pos);

    if(data > old_var)
        return heap_adjust_up(heap, cur_pos);
    else if(data < old_var)
        return heap_adjust_down(heap, cur_pos);
}

void heap_pop(int heap[], int* top_data)
{
    if(0 == heap[0])
        return ;
    if(1 != heap[0])
        heap_swap(heap, 1, heap[0]);

    *top_data = heap[heap[0]];
    heap[0]--;

    heap_adjust_down(heap, 1);
}

void heap_delete(int heap[], int cur_pos)
{
    int last_var = heap[heap[0]];
    heap[0]--;

    heap_adjust_update(heap, cur_pos, last_var);
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

    int tmp;
    heap_delete(myheap, 2);
    heap_print(myheap);

    heap_delete(myheap, 1);
    heap_print(myheap);

    heap_delete(myheap, 2);
    heap_print(myheap);

    return 0;
}