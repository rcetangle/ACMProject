//
//  houseboat.h
//  AMCProject
//
//  Created by ios on 2019/3/20.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef houseboat_h
#define houseboat_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void houseboat() {
#ifdef PRINT_FLAG
    printf("problem I Think I Need a Houseboat problemCode=1049\n");
    printf("please input an int for n: ");
#endif
    int cnt;
    scanf("%d", &cnt);
    int idx = 1;
    while(cnt > 0) {
        float x, y;
#ifdef PRINT_FLAG
        printf("input x, y: ");
#endif
        scanf("%f %f", &x, &y);
        int z = 0;
        z = ((x*x+y*y)*3.14)/100 + 1;
        printf("Property %d: This property will begin eroding in year %d.\n", idx, z);
        idx++;
        cnt--;
    }
    printf("END OF OUTPUT.\n");
}

#endif /* houseboat_h */
