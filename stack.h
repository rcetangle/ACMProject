//
//  stack.h
//  AMCProject
//
//  Created by ios on 2019/2/26.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef stack_h
#define stack_h

typedef struct stack_data {
    char c;
    struct stack_data* next;
} STACK_DATA;

typedef struct {
    STACK_DATA* head;
    int needPrint;
} STACK;

STACK* createStack(int needPrint) {
    STACK* ret = (STACK*)malloc(sizeof(STACK));
    ret->head = NULL;
    ret->needPrint = needPrint;
    return ret;
}

int isStackEmpty(STACK* s) {
    return s->head == NULL? 1 : 0;
}

void stackPrint(STACK* s) {
    STACK_DATA* next = s->head;
    printf("\n-- ");
    while(next != NULL) {
        printf("%c ", next->c);
        next = next->next;
    }
    printf("\n-------------\n");
}

void stackPush(STACK* s, char d) {
    STACK_DATA* data = (STACK_DATA*)malloc(sizeof(STACK_DATA));
    if (data != NULL) {
        data->c = d;
        data->next = NULL;
        STACK_DATA** next = &(s->head);
        while (*next != NULL) {
            next = (STACK_DATA**)&((*next)->next);
        }
        *next = data;
        if (s->needPrint == 1)
            printf("i ");
    }
}

char stackPop(STACK* s) {
    char r = '\0';
    STACK_DATA** next= &(s->head);
    while (*next != NULL && (*next)->next != NULL) {
        next = (STACK_DATA**)&((*next)->next);
    }
    if (*next != NULL) {
        r = (*next)->c;
        free(*next);
        *next = NULL;
    }
    if (s->needPrint == 1)
        printf("o ");
    return r;
}

char stackReadTop(STACK* s) {
    STACK_DATA* next= s->head;
    while (next != NULL && next->next != NULL) {
        next = next->next;
    }
    return next != NULL? next->c : '\0';
}

void stackClear(STACK* s) {
    STACK_DATA* next = s->head;
    while(next != NULL) {
        STACK_DATA* now = next;
        next = next->next;
        free(now);
    }
}
#endif /* stack_h */
