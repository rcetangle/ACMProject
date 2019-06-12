//
//  numberical_summation.h
//  AMCProject
//
//  Created by ios on 2019/3/1.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef numberical_summation_h
#define numberical_summation_h

#include <stdio.h>
#include <time.h>
#include <math.h>

void numberical_summation() {
#ifdef PRINT_FLAG
    printf("problem numberical summation of a series problemCode=1007\n");
    double error = 0.5e-12;
    printf("%16.13f\n", error);
#endif
    long start = time(NULL);
    double x = 0.000;
    int maxK = 1.5e6;
    
    double tmp = 0.00;
    int k = maxK;
    while (k > 1e4) {
        tmp += 1.0/((double)k*((double)k)*((double)k+1));
        k--;
    }
    int tmpK = k;
    while (x < 2.000) {
        double y = 0.000;
        k = tmpK;
        while (k >= 1) {
            y += 1.0/((double)k*((double)k+1)*((double)k+x));
            k--;
        }
        y += tmp;
        y *= (1.0-x);
        y += 1.0;
        printf("%5.3f\t%16.12f\n", x, y);
        x += 0.001;
    }
#ifdef PRINT_FLAG
    printf("end %ld\n", time(NULL) - start);
#endif
}
#endif /* numberical_summation_h */
