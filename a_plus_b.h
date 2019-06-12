//
//  a_plus_b.h
//  AMCProject
//
//  Created by ios on 2018/12/22.
//  Copyright © 2018 ios. All rights reserved.
//

#ifndef a_plus_b_h
#define a_plus_b_h

#include <stdio.h>

void a_plus_b() {
    printf("problem a+b\n");
    int a, b;
    printf("input two numbers separated by a space: ");
    int scanRet = 2;
    while(scanRet != EOF) {
        scanRet = scanf("%d %d", &a, &b);
        if (scanRet < 2) {
            printf("input error\n");
            char tmp;
            while (scanf("%c", &tmp) != EOF && tmp != '\n'); // flush the input buffer
        } else {
            printf("%d\n", a+b);
        }
    }
}

#endif /* a_plus_b_h */
