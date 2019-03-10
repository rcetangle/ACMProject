//
//  financial_management.h
//  AMCProject
//
//  Created by ios on 2019/3/8.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef financial_management_h
#define financial_management_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void financial_management() {
    const int max = 12;
#ifdef PRINT_FLAG
    printf("problem Financial Management problemCode=1048\n");
    printf("please input %d floats:\n", max);
#endif
    float* inputs = (float*)malloc(sizeof(float)*max);
    memset(inputs, 0, sizeof(float)*max);
    int i;
    for (i = 0; i < max; i++) {
        scanf("%f", inputs+i);
    }

    float ret = 0.0;
    for (i = 0; i < max; i++) {
        ret += inputs[i];
    }
    printf("$%.2f", ret/max);
}

#endif /* financial_management */
