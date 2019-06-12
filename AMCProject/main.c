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
#include "trees_made_2_order.h"
#include "fire_net.h"
#include "houseboat.h"
#include "hangover.h"
#include "undercut.h"
#include "enigma.h"
#include "gridland.h"
#include "color_me_less.h"
#include "wooden_sticks.h"
#include "sort.h"

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
        case 10:
            trees_made_2_order(); // unfinished yet
            break;
        case 11:
            fire_net();
            break;
        case 12:
            houseboat();
            break;
        case 13:
            hangover();
            break;
        case 14:
            undercut();
            break;
        case 15:
            enigma(); // segment fault
            break;
        case 16:
            gridland();
            break;
        case 17:
            color_me_less();
            break;
        case 18:
            wooden_sticks();
            break;
        default:
            wooden_sticks();
            break;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    problemFactory(4);
//    testSort();
    return 0;
}
