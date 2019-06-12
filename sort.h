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

void shellSort(void* arr, const int len, const size_t size, Compare func) {
    
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
    sort = quickSort;
    (*sort)(a, len, sizeof(Type), isBigger);
    
    for (i = 0; i < len; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
#endif /* sort_h */
