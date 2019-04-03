//
//  undercut.h
//  AMCProject
//
//  Created by ios on 2019/3/20.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef undercut_h
#define undercut_h

void undercut() {
#ifdef PRINT_FLAG
    printf("problem Undercut problemCode=1057\n");
    printf("please input an int for n:\n");
#endif
    int cnt;
    int flag = 0;
    while(scanf("%d", &cnt) != EOF && cnt > 0) {
#ifdef PRINT_FLAG
        printf("input %d * 2 ints:\n", cnt);
#endif
        if (flag == 0) {
            flag = 1;
        } else {
            printf("\n");
        }
        int* playerA = (int*)malloc(sizeof(int)*cnt);
        memset(playerA, 0, sizeof(int)*cnt);
        int* playerB = (int*)malloc(sizeof(int)*cnt);
        memset(playerB, 0, sizeof(int)*cnt);
        int i;
        for (i = 0; i < cnt; i++) {
            scanf("%d", playerA+i);
        }
        for (i = 0; i < cnt; i++) {
            scanf("%d", playerB+i);
        }
        int retA = 0;
        int retB = 0;
        for (i = 0; i < cnt; i++) {
            int tmp = playerA[i] - playerB[i];
            int sum = playerA[i] + playerB[i];
            if (tmp == 1) {
                retB += sum <= 3? 6 : sum;
            } else if (tmp == -1) {
                retA += sum <= 3? 6 : sum;
            } else if (tmp < -1) {
                retB += playerB[i];
            } else if (tmp > 1) {
                retA += playerA[i];
            }
        }
        printf("A has %d points. B has %d points.\n", retA, retB);
        free(playerA);
        free(playerB);
    }
}

#endif /* undercut_h */
