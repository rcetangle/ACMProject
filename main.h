//
//  main.h
//  AMCProject
//
//  Created by ios on 2019/2/28.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef main_h
#define main_h

#define PRINT_FLAG 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mem_cnt = 0;
void * safe_malloc(size_t size)
{
    void * mem = malloc(size);
    if(mem)
    {
        mem_cnt++;
    }
    return mem;
}

void safe_free(void * ptr)
{
    if(ptr == NULL || mem_cnt == 0) return;
    free(ptr);
    ptr = NULL;
    mem_cnt--;
}

void mem_leak_result()
{
    printf("\ncheck memory leak %d\n", mem_cnt);
}

#endif /* main_h */
