//
//  crashing_ballon.h
//  AMCProject
//
//  Created by ios on 2019/2/19.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef crashing_ballon_h
#define crashing_ballon_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CRASH_MAX_CNT 100
typedef struct {
    int data[CRASH_MAX_CNT];
    int current;
    int len;
    int initial;
} DATA;

int isModed(const int a, const int b) {
    if (b <= a && a%b == 0) return 1;
    return 0;
}

int min(const int a, const int b) {
    return a < b? a : b;
}

void printData(const DATA* data) {
    printf("-- ");
    int j;
    for (j = 0; j < data->len; j++) {
        printf(" %d ", data->data[j]);
    }
    printf("\n");
}

int recursion(DATA* data, const int target, const int* except) {
    if (data->current >= target)
        return 1;
    if (data->len < 0)
        return 0;
    
    int ret = 0;
    int m = min(target, CRASH_MAX_CNT);
    int i = data->initial == 1? data->data[data->len] : data->data[data->len-1];
    data->initial = 0;
    for (i = i + 1; i <= m && data->len >= 0; i++) {
        if (except != NULL && except[i-1] > 0) {
            continue;
        }
        if (1 == isModed(target, data->current*i)) {
            data->data[data->len] = i;
            data->len++;
            data->current *= i;
            ret = recursion(data, target, except);
        }
    }
    if (ret == 0) {
        if (data->len > 0) {
            data->current /= data->data[data->len-1];
        }
        data->initial = 1;
        data->len--;
        if (data->len >= 1)
            ret = recursion(data, target, except);
    }

    return ret;
}

int calculateMods(const int a, const int b) {
    int ret = 2;
    int needInitial = 1;
    DATA* now = NULL;
    int lenB = 0;
    int i = 1;
    while (1 == i) {
        i++;
        if (1 == needInitial) {
            if (now != NULL) {
                free(now);
                now = NULL;
            }
            now = (DATA*)malloc(sizeof(DATA));
            now->len = 0;
            now->data[0] = 0;
            now->current = 1;
            now->initial = 1;
        }
        if (0 == needInitial || 1 == (isModed(b, now->current))) {
            needInitial = 1;
            if (1 == recursion(now, b, NULL)) {
                if (now->data[0] > 1) break;
                lenB++;
#ifdef PRINT_FLAG
                printData(now);
#endif
                DATA* dtA = (DATA*)malloc(sizeof(DATA));
                dtA->len = 0;
                dtA->data[0] = 0;
                dtA->current = 1;
                dtA->initial = 1;
                
                int except[CRASH_MAX_CNT];
                memset(except, 0, sizeof(int)*CRASH_MAX_CNT);
                int j;
                for (j = 1; j < now->len; j++) {
//                    if (now->len == 0) {
//                        except[0] = 1;
//                    } else {
                        except[now->data[j]-1] = 1;
//                    }
                }
                if (1 == recursion(dtA, a, except)) {
#ifdef PRINT_FLAG
                    printf("b使用掉了因子之后，还能乘出a，证明a说真的\n");
                    printData(dtA);
#endif
                    ret = 1;
                }
                free(dtA);
                
                if (now->len > 2) {
                    i--;
                    needInitial = 0;
                    DATA* next = (DATA*)malloc(sizeof(DATA));
                    next->len = now->len-2;
                    next->initial = 1;
                    memcpy(next->data, now->data, sizeof(int)*now->len-1);
                    next->current = now->current/(now->data[now->len-1]*now->data[now->len-2]);
                    free(now);
                    now = next;
                }
            } else {
                if (lenB == 0) {
#ifdef PRINT_FLAG
                    printf("b没有任何因子\n");
#endif
                    ret = 1;
                }
            }
        }
    }
    if (now != NULL) {
        free(now);
        now = NULL;
    }
    return ret;
}

void crashing_ballon() {
    printf("problem crashing ballon.\n");
    printf("please input an int:");
    int target, target2 = 0;
    while(EOF != scanf("%d %d", &target, &target2)) {
        int tmp = min(target, target2);
        target = tmp == target? target2 : target;
        target2 = tmp;

        printf("%d VS %d\n", target, target2);
        
        int ret = calculateMods(target, target2);
        
        printf("%d win\n\n", ret==1? target:target2);
    }
}

// 别人家的
int flagA,flagB;
void dfs(int m,int n,int kk)    //运用了深度优先 的搜索策略
{
    int k =kk;
    if(m==1 && n==1)    //在两个数的所有各不相同的因子中，有因子能重新乘出给出的两个数，则A说了真话
    {
        flagA=1; //A说了真话
        return ;
    }
    if(n==1) //在两个数的所有各不相同的因子中，没有任何因子能重新乘出给出的两个数，则B说了真话
        flagB =1;   //B说了真话
    while( (k <  m || k <  n) && (k< 100) )
    {
        k++;
        /*
         *依次找出两个数所有各不相同的因子，如24和12的所有因子为 2，3，4，6，8，12 ，
         再在这些因子中搜索，看是否能重新乘出给出的两个数
         */
        if(m%k ==0)
        {
            dfs(m/k,n,k);
            if(flagA)
                return ;
        }
        if(n%k ==0 )
        {
            dfs(m,n/k,k);
            if(flagA)
                return ;
        }
    }
}
#endif /* crashing_ballon_h */
