//
//  hangover.h
//  AMCProject
//
//  Created by ios on 2019/3/20.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef hangover_h
#define hangover_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hangover() {
#ifdef PRINT_FLAG
    printf("problem HangOver problemCode=1045\n");
    printf("please input float for length: ");
#endif
    float length;
    while(scanf("%f", &length) != EOF && length > 0.00) {
        int c = 1;
        float tmp = 0;
        while (tmp < length) {
            tmp += 1.0/(1.0+c);
            c++;
        }
        printf("%d card(s)\n", c-1);
    }
}


#endif /* hangover_h */
