//
//  do_the_untwist.h
//  AMCProject
//
//  Created by ios on 2019/2/28.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef do_the_untwist_h
#define do_the_untwist_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validCode(const int a, const int b) {
    return a >= 0 && a < 28? a : b;
}

int calculatePlainCode(const int cipherCode, const int idx) {
    return validCode((cipherCode - 28)+idx, cipherCode+idx);
}

char getCharFromCode(const int c) {
    char ret;
    switch (c) {
        case 0:
            ret = 95;
            break;
        case 27:
            ret = 46;
            break;
        default:
            ret = c+96;
            break;
    }
    return ret;
}

int getCodeFromChar(const char c) {
    int ret;
    switch (c) {
        case 95:  /* ascii code for _ */
            ret = 0;
            break;
        case 46: /* ascii code for . */
            ret = 27;
            break;
        default:
            ret = c - 96;
            break;
    }
    return ret;
}

void do_the_untwist() {
#ifdef PRINT_FLAG
    printf("problem do the untwist problemCode=1006\n");
    printf("please input an int(0~300) and a ciphertext(1~70 characters):\n");
    
    /* init plainCode */
    int i = 0;
    printf("text: ");
    for (; i < 28; i++) {
        printf("(%d)%c ", i, getCharFromCode(i));
    }
    printf("\n");
#endif
    while(1) {
        int key = 1;
        scanf("%d", &key);
        if (key == 0) break;
        char cipherText[MAX_CNT];
        scanf(" %s", cipherText);
        
        /* get cipherCodes */
        int n = 0;
        int cipherCode[MAX_CNT];
        while(cipherText[n] != '\0') {
            cipherCode[n] = getCodeFromChar(cipherText[n]);
            n++;
        }
        /* get plainCode indexs */
        int i;
        int* plainIdx = (int*)malloc(sizeof(int)*n);
        memset(plainIdx, 0, sizeof(int)*n);
        for (i = 0; i < n; i++) {
            plainIdx[i] = (key*i)%n;
        }
    
#ifdef PRINT_FLAG
        printf("       idx: ");
        for (i = 0; i < n; i++) {
            printf("%d\t", i);
        }
        printf("\ncipherCode: ");
        for (i = 0; i < n; i++) {
            printf("%d\t", cipherCode[i]);
        }
        printf("\n  plainIdx: ");
        for (i = 0; i < n; i++) {
            printf("%d\t", plainIdx[i]);
        }
#endif
        int* plainCode = (int*)malloc(sizeof(int)*n);
        memset(plainCode, -1, sizeof(int)*n);
        for (i = 0; i < n; i++) {
            plainCode[plainIdx[i]] = calculatePlainCode(cipherCode[i], i);
        }
#ifdef PRINT_FLAG
        printf("\n plainCode: ");
        for (i = 0; i < n; i++) {
            printf("%d\t", plainCode[i]);
        }
        printf("\n plainText: ");
        for (i = 0; i < n; i++) {
            printf("%c\t", getCharFromCode(plainCode[i]));
        }
        printf("\n");
#else
        for (i = 0; i < n; i++) {
            printf("%c", getCharFromCode(plainCode[i]));
        }
        printf("\n");
#endif
        free(plainIdx);
        plainIdx = NULL;
        free(plainCode);
        plainCode = NULL;
    }
}

int calculateCipherCode(const int code) {
    return code < 0? (code+28)%28 : code%28;
}

void encrypt2Twist() {
    printf("please input an int(0~300) and a plainText(1~70 characters):\n");
    int key = 1;
    scanf("%d", &key);
    char plainText[MAX_CNT];
    scanf(" %s", plainText);
    int n = 0;
    int plainCode[MAX_CNT];
    while(plainText[n] != '\0') {
        plainCode[n] = getCodeFromChar(plainText[n]);
        n++;
    }
    
    int* cipherCode = (int*)malloc(sizeof(int)*n);
    memset(cipherCode, -1, sizeof(int)*n);
    int i;
    for (i = 0; i < n; i++) {
        cipherCode[i] = calculateCipherCode(plainCode[(i*key)%n] - i);
        printf("%d ", cipherCode[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%c", getCharFromCode(cipherCode[i]));
    }
    printf("\n");
    free(cipherCode);
    cipherCode = NULL;
}

#endif /* do_the_untwist_h */
