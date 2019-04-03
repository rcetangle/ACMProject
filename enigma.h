//
//  enigma.h
//  AMCProject
//
//  Created by ios on 2019/3/21.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef enigma_h
#define enigma_h

#include "link_list.h"

char encryptedEnigma(const char input, LIST* enigma, const int step) {
    int i, ret = 0;
    for (i = 0; enigma && i < enigma->cnt; i++) {
        int offset = (i+*((int*)getListData(enigma, i)))%enigma->cnt;
        if (offset < 0) {
            offset += enigma->cnt;
        }
        /*
#ifdef PRINT_FLAG
        printf("%d ", offset);
#endif
         */
        if (offset == input-'A') {
            ret = i;
        }
    }
    /*
#ifdef PRINT_FLAG
        printf("input %c(%d) ==> %c(%d)\n", input, input-'A', ret+'A', ret);
#endif
     */
    if (enigma && step > 0) {
        shiftRight(enigma, step); /* 右移step位 */
    }
    return ret+'A';
}

void enigma() {
#ifdef PRINT_FLAG
    printf("problem Enigma problemCode=1009\n");
    printf("please input an int for m:\n");
#endif
    freopen("/Users/ios/Documents/Anice/AMCProject/AMCProject/test.in","r",stdin);
    int m = 0;
    while(scanf("%d", &m) != EOF && m > 0) {
#ifdef PRINT_FLAG
        printf("input %d * 3 chars:\n", m);
#endif
        LIST* lists[3];
        int i, j;
        for (i = 0; i < 3; i++) {
            scanf("\n");
            lists[i] = createList(0);
            for (j = 0; lists[i] && j < m; j++) {
                char input;
                scanf("%c", &input);
                int* offset = (int*)safe_malloc(sizeof(int));
                if (offset) {
                    *offset = input-('A'+j);
                    insert2List(lists[i], offset, j);
                }
            }
        }
#ifdef PRINT_FLAG
        printf("input an int for test case cnt:\n");
#endif
        int n, idx;
        int rollCnt = 0;
        int tmpM = 0;
        scanf("%d\n", &n);
        for(idx = 0; idx < n; idx++) {
            printf("Enigma %d:\n", idx+1);
            while(1) {
                char cryptograph;
                scanf("%c", &cryptograph);
                if (cryptograph == '\0' || cryptograph == ' ' || cryptograph == '\n') break;
                /*
#ifdef PRINT_FLAG
                printList(lists[2]);
                printList(lists[1]);
                printList(lists[0]);
#endif
                 */
                int step = rollCnt >= (2+tmpM)*m && rollCnt < (3+tmpM)*m? 1 : 0;
                cryptograph = encryptedEnigma(cryptograph, lists[2], step);
                step = rollCnt >= (1+tmpM)*m && rollCnt < (2+tmpM)*m? 1 : 0;
                cryptograph = encryptedEnigma(cryptograph, lists[1], step);
                step = rollCnt < (1+tmpM)*m? 1 : 0;
                cryptograph = encryptedEnigma(cryptograph, lists[0], step);
                printf("%c", cryptograph-'A'+'a');
                rollCnt++;
                if (rollCnt%(3*m) == 0) tmpM += 3;
            }
            printf("\n");
            if (idx < n-1) {
                printf("\n");
            }
        }
        deleteList(lists[0]);
        deleteList(lists[1]);
        deleteList(lists[2]);
    }
    mem_leak_result();
    fclose(stdin);//关闭文件
}

#endif /* enigma_h */
