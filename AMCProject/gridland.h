//
//  gridland.h
//  AMCProject
//
//  Created by ios on 2019/3/11.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef gridland_h
#define gridland_h

typedef struct graph {
    
} Graph;

void gridland() {
#ifdef PRINT_FLAG
    printf("problem Gridland problemCode=1037\n");
    printf("please input an int:\n");
#endif
    int cnt;
    while(scanf("%d", &cnt) != EOF && cnt <= 0) {
        int i;
        for (i = 0; i < cnt; cnt++) {
#ifdef PRINT_FLAG
            printf("Scenario #%d input the grid dimensions(1~50): ", i+1);
#endif
            int m, n;
            scanf("%d %d", m, n);
            int* grid = (int*)malloc(sizeof(int)*m*n);
            int j;
            for (j = 0; j < m*n; j++)
                grid[j] = 1;
        }
    }
}

#endif /* gridland_h */
