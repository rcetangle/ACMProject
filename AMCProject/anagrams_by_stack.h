//
//  anagrams_by_stack .h
//  AMCProject
//
//  Created by ios on 2019/2/26.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef anagrams_by_stack__h
#define anagrams_by_stack__h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void method1(const char* source, const char* target) {
    STACK* sourceStack = createStack(1);
    int tIdx = 0;
    int sIdx = 0;
    char ret[MAX_CNT];
    memset(ret, '\0', sizeof(char)*MAX_CNT);
    int retLen = 0;
    while (target[tIdx] != '\0') {
        while(source[sIdx] != '\0') {
            char c = source[sIdx++];
            stackPush(sourceStack, c);
            if (c == target[tIdx]) {
                break;
            }
        }
        char r = stackPop(sourceStack);
        ret[retLen++] = r;
        tIdx++;
    }
    printf("    ret1: %s\n", ret);
    free(sourceStack);
}


void method2(const char* source, const char* target) {
    STACK* sourceStack = createStack(1);
    int tIdx = 0;
    int sIdx = 0;
    char ret[MAX_CNT];
    memset(ret, '\0', sizeof(char)*MAX_CNT);
    int retLen = 0;
    while (target[tIdx] != '\0') {
        while (source[sIdx] != '\0') {
            char c = source[sIdx++];
            stackPush(sourceStack, c);
            if (c == target[tIdx]) {
                break;
            }
        }
        
        while (target[tIdx] != '\0' && stackReadTop(sourceStack) == target[tIdx]) {
            char r = stackPop(sourceStack);
            ret[retLen++] = r;
            tIdx++;
        }
    }
    printf("    ret2: %s\n", ret);
    free(sourceStack);
}

void method3(const char* source, const char* target) {
    STACK* sourceStack = createStack(1);
    STACK* targetStack = createStack(0);
    int tIdx = 0;
    while(target[tIdx] != '\0') {
        stackPush(targetStack, target[tIdx++]);
    }
    STACK* tmpStack = createStack(0);
    int sIdx = 0;
    char ret[MAX_CNT];
    memset(ret, '\0', sizeof(char)*MAX_CNT);
    int retLen = 0;
    while (source[sIdx] != '\0') {
        char c = source[sIdx];
        char tc = stackPop(targetStack);
        if (c == tc) {
            stackPush(sourceStack, c);
            sIdx++;
        } else if (tc != '\0'){
            stackPush(tmpStack, tc);
        } else {
            while (0 == isStackEmpty(sourceStack)) {
                ret[retLen++] = stackPop(sourceStack);
            }
            tc = stackPop(tmpStack);
            if (c == tc) {
                stackPush(sourceStack, c);
                sIdx++;
            }
        }
    }
    while (0 == isStackEmpty(sourceStack)) {
        ret[retLen++] = stackPop(sourceStack);
    }
    
    printf("    ret3: %s\n", ret);
    free(sourceStack);
    free(targetStack);
    free(tmpStack);
}

void method4(const char* source, const char* target) {
    STACK* sourceStack = createStack(1);
    STACK* targetStack = createStack(0);
    int tIdx = 0;
    while(target[tIdx] != '\0') {
        stackPush(targetStack, target[tIdx++]);
    }
    STACK* tmpStack = createStack(0);
    int sIdx = 0;
    char ret[MAX_CNT];
    memset(ret, '\0', sizeof(char)*MAX_CNT);
    int retLen = 0;
    while (source[sIdx] != '\0') {
        char c = source[sIdx];
        char tc = stackPop(targetStack);
        if (c == tc) {
            stackPush(sourceStack, c);
            sIdx++;
        } else if (tc != '\0') {
            stackPush(tmpStack, tc);
        } else {
            while (0 == isStackEmpty(sourceStack) && stackReadTop(tmpStack) != stackReadTop(sourceStack)) {
                ret[retLen++] = stackPop(sourceStack);
            }
            stackPush(sourceStack, c);
            sIdx++;
            stackPop(tmpStack);
        }
    }
    while (0 == isStackEmpty(sourceStack)) {
        ret[retLen++] = stackPop(sourceStack);
    }
    
    printf("    ret4: %s\n", ret);
    free(sourceStack);
    free(targetStack);
    free(tmpStack);
}

void trashNDfS(const char* source, const char* target) {
    STACK* sourceStack = createStack(1);
    STACK* targetStack = createStack(0);
    int tIdx = 0;
    while(target[tIdx] != '\0') {
        stackPush(targetStack, target[tIdx++]);
    }
    STACK* tmpStack = createStack(0);
    int sIdx = 0;
    char ret[MAX_CNT];
    memset(ret, '\0', sizeof(char)*MAX_CNT);
    int retLen = 0;
    while (source[sIdx] != '\0') {
        char c = source[sIdx];
        char tc = stackPop(targetStack);
        if (c == tc) {
            stackPush(sourceStack, c);
            sIdx++;
        } else if (tc != '\0') {
            stackPush(tmpStack, tc);
        } else {
            while (0 == isStackEmpty(sourceStack) && stackReadTop(tmpStack) != stackReadTop(sourceStack)) {
                ret[retLen++] = stackPop(sourceStack);
            }
            stackPush(sourceStack, c);
            sIdx++;
            stackPop(tmpStack);
        }
    }
    while (0 == isStackEmpty(sourceStack)) {
        ret[retLen++] = stackPop(sourceStack);
    }
    
    printf("    ret4: %s\n", ret);
    free(sourceStack);
    free(targetStack);
    free(tmpStack);
}

void anagrams_by_stack() {
#ifdef PRINT_FLAG
    printf("problem anagrams by stack problemCode=1004\n");
    printf("please input two line, one for source, another for target:\n");
#endif
    char source[MAX_CNT];
    char target[MAX_CNT];
    while(EOF != scanf("%s\n%s", source, target)) {
        printf("[\n");
        trashNDfS(source, target);
//        method4(source, target);
//        method3(source, target);
//        method1(source, target);
//        method2(source, target);
        printf("]\n");
    }
}

#endif /* anagrams_by_stack__h */
