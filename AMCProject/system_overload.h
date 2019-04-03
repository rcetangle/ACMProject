//
//  system_overload.h
//  AMCProject
//
//  Created by ios on 2019/3/7.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef system_overload_h
#define system_overload_h

/*
 解法：
    在数学界有一个经典的约瑟夫环问题（Josephus Problem）。约瑟夫环问题是这样的，有n个人围成一个圈，分别编号为1,2,3…n，从第1个人开始报数，报到偶数的人出列，剩下的人继续，直到仅剩最后一个人位置。那么，如果我想做这个站到最后的人，最开始我应该站在哪个编号的位置？如果是隔2个人报数，我又应该站在哪里？如果是隔k个人呢？我在Google上搜索的时候看到有人推荐一本书《具体数学》。在这本书的第一章（也许第二章）里有详细的分析和证明。
 
    这道题和约瑟夫环的问题也差不多，指是从后往前倒推。要保证坚持到最后的人是2号，起始位置是1号，报数的间隔是多少。间隔数m从2开始往上一个个地试。判断的精髓就是这个递归公式：k=(k+m)%i。如果经过n-1次的递归计算，k的值是0，那么这个m就是所求的答案了。
 */

void josephus_problem(const int n) {
    printf("\njosephus_problem: ");
    int m = 1;
    while(1) {
        int i;
        int k = 0;
        for (i = 2; i < n; i++)
            k = (k + m) % i;
        if (k+1 == 1) {
            break;
        }
        m++;
    }
    printf("%d\n\n", m);
}

void system_overload() {
#ifdef PRINT_FLAG
    printf("problem System Overload problemCode=1088\n");
    printf("please input an int(3~149):\n");
#endif
    while(1) {
        int n = 3;
        scanf("%d", &n);
        if (n == 0) break;
        int* cutoffs = (int*)malloc(sizeof(int)*n);
        
        int m = 2;
        while (1) {
            memset(cutoffs, 0, sizeof(int)*n);
#ifdef PRINT_FLAG
            printf("M=%d [", m);
#endif
            int startIdx = 0;
            int cutoffLen = 0;
            int tmpM;
            while (1) {
#ifdef PRINT_FLAG
                printf("%d ", startIdx+1);
#endif
                if (startIdx == 1 && cutoffLen < n-1) break;
                cutoffs[startIdx] = 1;
                cutoffLen++;
                if (cutoffLen == n-1) break;
                tmpM = m;
                while (tmpM > 0) {
                    startIdx++;
                    if (startIdx >= n) startIdx = 0;
                    if (cutoffs[startIdx] != 0) {
                        continue;
                    }
                    tmpM--;
                }
            }
#ifdef PRINT_FLAG
            if (cutoffLen == n-1) {
                printf("2]\n");
            } else {
                printf("X]\n");
            }
#endif
            if (cutoffLen == n-1) break;
            m++;
        }
        printf("%d\n", m);

        free(cutoffs);
        cutoffs = NULL;
        
        josephus_problem(n);
    }
}


#endif /* system_overload_h */
