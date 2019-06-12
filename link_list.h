//
//  link_list.h
//  AMCProject
//
//  Created by ios on 2019/3/21.
//  Copyright © 2019 ios. All rights reserved.
//
// 一个单向循环链表
#ifndef link_list_h
#define link_list_h

typedef struct data {
    void* c;
    struct data* next;
} LIST_DATA;

typedef struct {
    LIST_DATA* head;
    int needPrint;
    int cnt;
} LIST;

LIST* createList(int needPrint) {
    LIST* ret = (LIST*)safe_malloc(sizeof(LIST));
    if (ret) {
        LIST_DATA* head = (LIST_DATA*)safe_malloc(sizeof(LIST_DATA));
        if (head) {
            ret->head = head;
            head->next = ret->head;
            head->c = NULL;
            ret->needPrint = needPrint;
            ret->cnt = 0;
        } else {
            safe_free(ret);
            ret = NULL;
        }
    }
    return ret;
}

int isListEmpty(LIST* s) {
    return s->head == s->head->next? 1 : 0;
}

void insert2List(LIST* s, void* data, int pos) {
    const int orPos = pos;
    LIST_DATA* next= s->head;
    while (next->next != s->head && pos > 0) {
        next = next->next;
        pos--;
    }
    LIST_DATA* d = (LIST_DATA*)safe_malloc(sizeof(LIST_DATA));
    if (d) {
        d->c = data;
        d->next = next->next;
        next->next = d;
        s->cnt++;
        if (s->needPrint)
            printf("insert: data %d pos %d addr %p cnt %d\n", *((int*)data), orPos, d, s->cnt);
    }
}

void removeFromList(LIST* s, int pos) {
    const int orPos = pos;
    LIST_DATA* next= s->head;
    while (next->next->next != s->head && pos > 0) {
        next = next->next;
        pos--;
    }
    LIST_DATA* target = next->next;
    next->next = next->next->next;
    safe_free(target->c);
    safe_free(target);
    s->cnt--;
    
    if (s->needPrint)
        printf("remove: pos %d addr %p\n", orPos, target);
}

void* getListData(LIST* s, int pos) {
    const int orPos = pos;
    LIST_DATA* next = s->head;
    while (next->next != s->head && pos >= 0) {
        next = next->next;
        pos--;
    }
    
    if (s->needPrint)
        printf("getListData: data %d pos %d addr %p\n", *((int*)next->c), orPos, next);
    return next->c;
}

LIST_DATA* getListTail(LIST* s) {
    LIST_DATA* next = s->head;
    while (next->next != s->head) {
        next = next->next;
    }
    return next;
}

LIST_DATA* getListNode(LIST* s, int pos) {
    const int orPos = pos;
    LIST_DATA* next = s->head;
    while (next->next != s->head && pos >= 0) {
        next = next->next;
        pos--;
    }
    
    if (s->needPrint)
        printf("getListNode: data %d pos %d addr %p\n", *((int*)next->c), orPos, next);
    return next;
}

void clearList(LIST* s) {
    LIST_DATA* next = s->head->next;
    if (s->needPrint)
        printf("clearList: HEAD %p\n", s->head);
    while(next != s->head) {
        LIST_DATA* now = next;
        next = next->next;
        if (s->needPrint)
            printf("free: data %d addr %p next %p\n", *((int*)now->c), now, next);
        safe_free(now->c);
        safe_free(now);
    }
    s->head->next = s->head;
    s->cnt = 0;
}

void deleteList(LIST* s) {
    clearList(s);
    safe_free(s->head);
    safe_free(s);
    s = NULL;
}

void printList(LIST* s) {
    LIST_DATA* next = s->head;
    printf("\n-- ");
    while(next->next != s->head) {
        if (next->c)
            printf("%d(%p) ", *(int*)(next->c), next);
        else
            printf("HEAD(%p) ", next);
            
        next = next->next;
    }
    if (next->c)
        printf("%d(%p) ", *(int*)(next->c), next);
    else
        printf("HEAD(%p) ", next);
    printf("\n-------------\n");
}

void shiftRight(LIST* s, const int step) {
    if (step <= 0) return;
    LIST_DATA* tail = getListTail(s);
    LIST_DATA* node = getListNode(s, s->cnt-step);
    LIST_DATA* before = getListNode(s, s->cnt-step-1);
/*  printf("HEAD %p tail %p node %p before %p\n", s->head, tail, node, before);
    printf("tail->next %p node->next %p before->next %p\n", tail->next, node->next, before->next); */
    tail->next = s->head->next; /* the tail becomes the before node of or head */
    s->head->next = node; /* the node becomes the head. */
    before->next = s->head; /* the before becomes the tail */
}

void shiftLeft(LIST* s, const int step) {
    if (step <= 0) return;
    LIST_DATA* tail = getListTail(s);
    LIST_DATA* node = getListNode(s, step);
    LIST_DATA* before = getListNode(s, step-1);
/*  printf("HEAD %p tail %p node %p before %p\n", s->head, tail, node, before);
    printf("tail->next %p node->next %p before->next %p\n", tail->next, node->next, before->next); */
    s->head->next = node; /* the node becomes the head. */
    before->next = s->head; /* the before becomes the tail */
    tail->next = before; /* the tail becomes the second last of list */
}

void testLinkList() {
    LIST* list = createList(1);
    printf("test create: addr %p head %p\n", list, list->head);
    int i;
    for (i = 0; i < 3; i++) {
        int* data = (int*)safe_malloc(sizeof(int));
        *data = i;
        insert2List(list, data, i);
    }
    printList(list);
    getListData(list, 2);
    removeFromList(list, 2);
    printList(list);
    printf("test clear list");
    clearList(list);
    printList(list);
}

#endif /* link_list_h */
