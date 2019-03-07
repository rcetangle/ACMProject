//
//  jugs.h
//  AMCProject
//
//  Created by ios on 2019/2/28.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef jugs_h
#define jugs_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define JUGS_MAX_CNT 1000

typedef struct {
    char* name; // name of jug
    int capacity; // capaticy of jug
    int current; // current gallons in jug
} Jug;

// fill the jug and return gallons that used
int fillJug(Jug* jug, int printTag) {
    int ret = jug->capacity - jug->current;
    jug->current = jug->capacity;
    if (printTag == 1) {
#ifdef PRINT_FLAG
        printf("fill %s with %d gallons, now %d(%d)\n", jug->name, ret, jug->current, jug->capacity);
#else
        printf("fill %s\n", jug->name);
#endif
    }
    return ret;
}

// empty the jug and return gallons that it had
int emptyJug(Jug* jug, int printTag) {
    int ret = jug->current;
    jug->current = 0;
    if (printTag == 1) {
#ifdef PRINT_FLAG
        printf("empty %s with %d gallons, now %d(%d)\n", jug->name, ret, jug->current, jug->capacity);
#else
        printf("empty %s\n", jug->name);
#endif
    }
    return ret;
}

// pour A jug to B jug and return gallons that used
int pourJug(Jug* A, Jug* B, int printTag) {
    int offsetB = B->capacity - B->current;
    int ret = A->current;
    if (ret > offsetB) {
        ret = offsetB;
    }
    A->current -= ret;
    B->current += ret;
    if (1 == printTag) {
#ifdef PRINT_FLAG
        printf("pour %s %s with %d gallons, now %s is %d(%d) %s is %d(%d)\n", A->name, B->name, ret, A->name, A->current, A->capacity, B->name, B->current, B->capacity);
#else
        printf("pour %s %s\n", A->name, B->name);
#endif
    }
    return ret;
}

int isJugFull(Jug* jug) {
    return jug->current == jug->capacity? 1 : 0;
}

int methodB(Jug* A, Jug* B, const int n, const int printTag) {
    int lenB = 0;
    emptyJug(B, 0);
    emptyJug(A, 0);
    while (B->current != n) {
        if (B->current == 0) {
            fillJug(B, printTag);
        } else if (1 == isJugFull(A)) {
            emptyJug(A, printTag);
        } else {
            pourJug(B, A, printTag);
        }
        lenB++;
    }
    return lenB;
}


int methodA(Jug* A, Jug* B, const int n, const int printTag) {
    emptyJug(B, 0);
    emptyJug(A, 0);
    int lenA = 0;
    while (B->current != n) {
        if (A->current == 0) {
            fillJug(A, printTag);
        } else if (1 == isJugFull(B)) {
            emptyJug(B, printTag);
        } else {
            pourJug(A, B, printTag);
        }
        lenA++;
    }
    return lenA;
}
    
void jugs() {
#ifdef PRINT_FLAG
    printf("problem jugs problemCode=1005\n");
    printf("please input three ints Ca Cb N (0 < Ca <= Cb and N <= Cb <=1000 and Ca and Cb are relatively prime to one another):\n");
#endif
    int ca, cb, n;
    while(EOF != scanf("%d %d %d", &ca, &cb, &n)) {
        Jug* A = (Jug*)malloc(sizeof(Jug));
        A->name = "A";
        A->capacity = ca;
        A->current = 0;
        
        Jug* B = (Jug*)malloc(sizeof(Jug));
        B->name = "B";
        B->capacity = cb;
        B->current = 0;
        
        int lenB = methodB(A, B, n, 0);
        int lenA = methodA(A, B, n, 0);
        if (lenA < lenB) {
            methodA(A, B, n, 1);
        } else {
            methodB(A, B, n, 1);
        }
        printf("success\n");
        
        free(B);
        B = NULL;
        free(A);
        A = NULL;
    }
}
#endif /* jugs_h */
