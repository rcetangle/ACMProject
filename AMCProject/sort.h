//
//  sort.h
//  AMCProject
//
//  Created by ios on 2019/4/4.
//  Copyright © 2019 ios. All rights reserved.
//  各种排序算法


#ifndef sort_h
#define sort_h

typedef int(*Compare)(void* a, void* b); /* 函数指针 */

void swap(void* a, void* b, const size_t size) {
    void* tmp = malloc(size);
    if (tmp) {
        memcpy(tmp, a, size);
        memcpy(a, b, size);
        memcpy(b, tmp, size);
        
        free(tmp);
        tmp = NULL;
    }
}

void assign(void* a, void*b, const size_t size) {
    memcpy(a, b, size);
}

/*
 冒泡排序，比较并交换相邻两个元素的位置
 */
void bubbleSort(void* arr, const int len, const size_t size, Compare func) {
    int i, j;
    for (i = 0; i < len-1; i++) {
        for (j = i+1; j < len; j++) {
            if (func(arr+i*size, arr+j*size)) {
                swap(arr+i*size, arr+j*size, size);
            }
        }
    }
}

/*
 选择排序，每次从剩余序列中选择最小/大的的元素，放到剩余序列的第一位。
 */
void selectSort(void* arr, const int len, const size_t size, Compare func) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        int minIdx = i;
        for (j = minIdx+1; j < len; j++) {
            if (func(arr+minIdx*size, arr+j*size)) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr+i*size, arr+minIdx*size, size);
        }
    }
}

/*
 插值排序 对第i个元素，在前i-1个位置中找到自己的位置并插入。
 */
void insertSort(void* arr, const int len, const size_t size, Compare func) {
    int i, j;
    for (i = 1; i < len; i++) {
        void* copyI = malloc(size);
        if (!copyI) break; /* 内存不够，还排什么序 */
        assign(copyI, arr+i*size, size);
        j = i-1;
        while(j >= 0 && func(arr+j*size, copyI)) {
            assign(arr+(j+1)*size, arr+j*size, size); /* j的位置后移一位*/
            j--;
        }
        assign(arr+(j+1)*size, copyI, size);
        free(copyI);
        copyI = NULL;
    }
}

/*
 快速排序。每次选择一个基准，把序列分成两个分区，并返回基准在结果中的索引位置。递归分别对两个分区作进一步排序。
 */
int partition(void* arr, const int start, const int end, const size_t size, Compare func) {
    void* pivot = malloc(size); // pivot value == arr[end]
    memcpy(pivot, arr+end*size, size);
    int i, storeIdx = start;
    for (i = start; i < end; i++) {
        if (func(pivot, arr+i*size)) { /* arr[i] 应该在 pivot 左边 */
            swap(arr+storeIdx*size, arr+i*size, size);
            storeIdx++; /* 新的分区的位置 */
        }
    }
    swap(arr+end*size, arr+storeIdx*size, size);
    free(pivot);
    pivot = NULL;
    return storeIdx;
}

void _quickSort(void* arr, const int start, const int end, const size_t size, Compare func) {
    if (start < end) {
        int newIdx = partition(arr, start, end, size, func);
        _quickSort(arr, start, newIdx-1, size, func);
        _quickSort(arr, newIdx+1, end, size, func);
    }
}

void quickSort(void* arr, const int len, const size_t size, Compare func) {
    _quickSort(arr, 0, len-1, size, func);
}

/* 希尔排序（递减增量排序算法）是插入排序的改良。
 插入排序的间隔是1，希尔排序则是先取一个间隔gap，然后再递减gap来进行排序。
 这样可以消除“乌龟”（在阵列尾部的小数值）。
 插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率
 但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位
 已知的最好步长序列是由Sedgewick提出的 (1, 5, 19, 41, 109,…)，该序列的项来自 9*4i-9*2i+1 和 4i-3*2i+1 这两个算式。
 */
void shellSort(void* arr, const int len, const size_t size, Compare func) {
    int gap = 1;
    while(gap < len) {
        gap = gap * 3 + 1; /* 取较优间隔 */
    }
    int i, j;
    while (gap > 0) {
        for (i = gap; i < len; i++) {
            void* copyI = malloc(size);
            assign(copyI, arr+i*size, size);
            j = i - gap;
            while (j >= 0 && func(arr+j*size, copyI)) {
                assign(arr+(j+gap)*size, arr+j*size, size); /* 元素后移gap步 */
                j -= gap;
            }
            assign(arr+(j+gap)*size, copyI, size); /* 把i插入到目标位置 */
            free(copyI);
            copyI = NULL;
        }
        gap = (gap - 1) / 3; /* 递减间隔 */
    }
}

/*  测试各种排序  */
typedef int Type;
int isBigger(void* a, void* b) {
    return *(Type*)a > *(Type*)b? 1 : 0;
}

int isSmaller(void* a, void*b) {
    return *(Type*)a < *(Type*)b? 1 : 0;
}

void testSort() {
    int i;
    const int len = 3;
    Type a[] = {10, 5, 20};
    printf("---- origin:\n");
    for (i = 0; i < len; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n---- sorted:\n");
    
    void (*sort)(void* arr, const int len, const size_t size, Compare func); // function pointer
//    sort = bubbleSort;
//    sort = selectSort;
//    sort = insertSort;
//    sort = quickSort;
    sort = shellSort;
    (*sort)(a, len, sizeof(Type), isBigger);
    
    for (i = 0; i < len; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
#endif /* sort_h */
