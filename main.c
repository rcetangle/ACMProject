//
//  main.c
//  AMCProject
//
//  Created by ios on 2018/12/22.
//  Copyright © 2018 ios. All rights reserved.


#include <stdio.h>
#include <time.h>

#include "main.h"
#include "a_plus_b.h"
#include "html.h"
#include "crashing_ballon.h"
#include "anagrams_by_stack.h"
#include "jugs.h"

void problemFactory(const int type) {
    switch (type) {
        case 1:
            a_plus_b();
            break;
        case 2:
            html();
        case 3:
            crashing_ballon();
        case 4:
            anagrams_by_stack();
        case 5:
            jugs();
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    problemFactory(5);
    return 0;
}
