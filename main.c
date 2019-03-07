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
#include "do_the_untwist.h"
#include "numberical_summation.h"
#include "gnome_tetravex.h"
#include "system_overload.h"

void problemFactory(const int type) {
    switch (type) {
        case 1:
            a_plus_b();
            break;
        case 2:
            html();
            break;
        case 3:
            crashing_ballon();
            break;
        case 4:
            anagrams_by_stack(); // unfinished yet
            break;
        case 5:
            jugs();
            break;
        case 6:
            do_the_untwist();
            break;
        case 7:
            numberical_summation();
            break;
        case 8:
            gnome_tetravex(); // unfinished yet
            break;
        case 9:
            system_overload();
            break;
        default:
            system_overload();
            break;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    problemFactory(3000);
    return 0;
}
