//
//  system_overload.h
//  AMCProject
//
//  Created by ios on 2019/3/7.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef system_overload_h
#define system_overload_h

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
    }
}


#endif /* system_overload_h */
