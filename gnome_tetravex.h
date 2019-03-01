//
//  gnome_tetravex.h
//  AMCProject
//
//  Created by ios on 2019/3/1.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef gnome_tetravex_h
#define gnome_tetravex_h

void gnome_tetravex() {
#ifdef PRINT_FLAG
    printf("problem gnome tetravex problemCode=1008\n");
    printf("please input an int(0~5):\n");
#endif
    while(1) {
        int n = 1;
        scanf("%d", &n);
        if (n == 0) break;
        int cnt = n*n*4;
        int* square = (int*)malloc(sizeof(int)*cnt);
        memset(square, -1, sizeof(int)*cnt);
#ifdef PRINT_FLAG
        printf("input %d ints(0~9) for triangles:\n", cnt);
#endif
        int i = 0;
        while (i < cnt) {
            scanf("%d", &square[i]);
            i++;
        }
#ifdef PRINT_FLAG
        printf("\n---------- square ----------\n");
        int j;
        for (i = 0; i < n*n;) {
            /* top */
            for (j = 0; j < n; j++) {
                printf("|\t%d\t | ", square[(i/n)*(n*4)+j*4]);
            }
            printf("\n");
            /* left & right*/
            for (j = 0; j < n; j++) {
                printf("|%d\t\t%d| ", square[(i/n)*(n*4)+j*4+3], square[(i/n)*(n*4)+j*4+1]);
            }
            printf("\n");
            /* bottom */
            for (j = 0; j < n; j++) {
                printf("|\t%d\t | ", square[(i/n)*(n*4)+j*4+2]);
            }
            printf("\n\n");
            i += n;
        }
#endif
    }
}
#endif /* gnome_tetravex_h */
