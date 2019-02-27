//
//  main.c
//  AMCProject
//
//  Created by ios on 2018/12/22.
//  Copyright © 2018 ios. All rights reserved.


#include <stdio.h>
#include <time.h>

#include "a_plus_b.h"
#include "html.h"
#include "crashing_ballon.h"

void problemFactory(const int type) {
   switch (type) {
       case 1:
           a_plus_b();
           break;
       case 2:
           html();
       case 3:
           crashing_ballon();
       default:
           break;
   }
}

int main(int argc, const char * argv[]) {
   // insert code here...
   problemFactory(3);
   return 0;
}
