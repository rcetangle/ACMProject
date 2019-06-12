//
//  gridland.h
//  AMCProject
//
//  Created by ios on 2019/3/11.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef gridland_h
#define gridland_h

void gridland() {
#ifdef PRINT_FLAG
    printf("problem Gridland problemCode=1037\n");
    printf("please input an int:\n");
#endif
    freopen("/Users/ios/Documents/Anice/AMCProject/AMCProject/test.in","r",stdin);
    int cnt = 0;
    while(scanf("%d", &cnt) != EOF && cnt > 0) {
        int i;
        for (i = 0; i < cnt; i++) {
#ifdef PRINT_FLAG
            printf("Scenario #%d input the grid dimensions(1~50): \n", i+1);
#endif
            int m, n;
            scanf("%d %d", &m, &n);
            float ret = 0;
            if (m%2 != 0 && n%2 != 0) {
                ret = m*n-1+sqrt(2);
            } else {
                ret = m*n;
            }
            printf("Scenario #%d:\n%.2f\n\n", i+1, ret);
        }
    }
}

#endif /* gridland_h */
