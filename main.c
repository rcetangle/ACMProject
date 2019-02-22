//
//  main.c
//  AMCProject
//
//  Created by ios on 2018/12/22.
//  Copyright © 2018 ios. All rights reserved.


#include <stdio.h>
#include <time.h>
//
//#include "a_plus_b.h"
//#include "html.h"
#include "crashing_ballon.h"
//
//void problemFactory(const int type) {
//    switch (type) {
//        case 1:
//            a_plus_b();
//            break;
//        case 2:
//            html();
//        case 3:
//            crashing_ballon();
//        default:
//            break;
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    problemFactory(3);
//    return 0;
//}

int flagA,flagB;
void dfs(int m,int n,int kk)    //运用了深度优先 的搜索策略
{
    int k =kk;
    if(m==1 && n==1)    //在两个数的所有各不相同的因子中，有因子能重新乘出给出的两个数，则A说了真话
    {
        flagA=1; //A说了真话
        return ;
    }
    if(n==1) //在两个数的所有各不相同的因子中，没有任何因子能重新乘出给出的两个数，则B说了真话
        flagB =1;   //B说了真话
    while( (k <  m || k <  n) && (k< 100) )
    {
        k++;
        /*
         *依次找出两个数所有各不相同的因子，如24和12的所有因子为 2，3，4，6，8，12 ，
         再在这些因子中搜索，看是否能重新乘出给出的两个数
         */
        if(m%k ==0)
        {
            dfs(m/k,n,k);
            if(flagA)
                return ;
        }
        if(n%k ==0 )
        {
            dfs(m,n/k,k);
            if(flagA)
                return ;
        }
    }
}

void crashing_ballon2() {
    int target, target2 = 0;
    target = 2147342383;
    target2 = 136817;
//    for (target = 2147342383, target2 = 136817; target > 2147483520/2; target--, target2++) {
        long t = time(NULL);
        int tmp = min(target, target2);
        target = tmp == target? target2 : target;
        target2 = tmp;
        printf("start %ld %d %d ", t, target, target2);
        int meRet = calculateMods(target, target2) == 1? target:target2;
        if (time(NULL) - t >= 1) {
            printf("(over 1 seds)");
        }
        printf(" end %ld", time(NULL));
        
        int A = target;
        int B = target2;
    
        flagA =0;   //先假定AB都说假话
        flagB =0;
        dfs(A,B,1); //判断AB矛盾
        
        int result = A;
        if(flagA ==0 && flagB ==1)  //只有证明A说了假话，并且B说了真话，才算B赢
            result = B;
        
        if (meRet != result) {
            printf("%d VS %d not right(me %d others %d)\n", target, target2, meRet, result);
        }
        printf(" end2 %ld\n", time(NULL));
//    }
    printf("END\n");
}


int main(int argc, const char * argv[]) {
//    crashing_ballon();
    crashing_ballon2();
    return 0;
}
