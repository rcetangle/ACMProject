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
#ifdef PRINT_FLAG
    printf("problem Financial Management problemCode=1048\n");
    printf("please input an int:\n");
#endif
    double* inputs = (double*)malloc(sizeof(double)*12);
    memset(inputs, 0, sizeof(double)*12);
    int i;
    for (i = 0; i < 12; i++) {
        scanf("%.2f\n", inputs[i]);
    }

    double ret = 0;
    for (i = 0; i < 12; i++) {
        ret += inputs[i];
    }
    printf("$%.2f", ret/12);
}

#endif /* financial_management */
