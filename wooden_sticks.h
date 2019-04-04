//
//  wooden_sticks.h
//  AMCProject
//
//  Created by ios on 2019/4/3.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef wooden_sticks_h
#define wooden_sticks_h

typedef struct stick {
    int weight;
    int length;
} Stick;
void wooden_sticks() {
#ifdef PRINT_FLAG
    printf("problem Wooden Sticks problemCode=1025\n");
    printf("please input an int for test case:\n");
#endif
    freopen("/Users/ios/Documents/Anice/AMCProject/AMCProject/test.in","r",stdin);
    int cnt = 0, i;
    scanf("%d", &cnt);
    for (i = 0; i < cnt; i++) {
#ifdef PRINT_FLAG
        printf("please input an int for sticks:\n");
#endif
        int n, j;
        scanf("%d", &n);
        Stick** sticks = (Stick**)safe_malloc(sizeof(Stick*)*n);
        for (j = 0; j < n; j++) {
            Stick* s = (Stick*)safe_malloc(sizeof(Stick));
            if (s) {
                sticks[j] = s;
                scanf("%d%*[ ]%d", &s->length, &s->weight);
            }
        }
#ifdef PRINT_FLAG
        for (j = 0; j < n; j++) {
            printf("%d %d ", sticks[j]->length, sticks[j]->weight);
        }
        printf("\n");
#endif
        int ret = 1;
        printf("mins: %d\n", ret);
    }
}

#endif /* wooden_sticks_h */
