//
//  color_me_less.h
//  AMCProject
//
//  Created by ios on 2019/4/3.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef color_me_less_h
#define color_me_less_h

typedef struct c3b {
    int r;
    int g;
    int b;
} C3B;

void color_me_less() {
#ifdef PRINT_FLAG
    printf("problem Color Me Less problemCode=1067\n");
#endif
    freopen("/Users/ios/Documents/Anice/AMCProject/AMCProject/test.in","r",stdin);
    int r = -1, g = -1, b = -1;
    int cnt = 0, i = 0;
    C3B* targets[16];
    while(scanf("%d %d %d", &r, &g, &b) != EOF && r >= 0 && g >= 0 && b >= 0) {
        if (cnt < 16) {
            C3B* tg = (C3B*)safe_malloc(sizeof(C3B));
            if (tg) {
                tg->r = r;
                tg->g = g;
                tg->b = b;
                targets[cnt] = tg;
                cnt++;
            }
        } else {
            float minDis = 3*pow(255, 3);
            int minIdx = 0;
            for (i = 0; i < cnt; i++) {
                float dis = pow(targets[i]->r-r, 2)+pow(targets[i]->g-g, 2)+pow(targets[i]->b-b, 2);
                if (dis < minDis) {
                    minDis = dis;
                    minIdx = i;
                }
            }
            printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, targets[minIdx]->r, targets[minIdx]->g, targets[minIdx]->b);
        }
    }
}

#endif /* color_me_less_h */
