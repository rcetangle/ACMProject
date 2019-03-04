//
//  gnome_tetravex.h
//  AMCProject
//
//  Created by ios on 2019/3/1.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef gnome_tetravex_h
#define gnome_tetravex_h

typedef struct square {
    int datas[4]; /* top right bottom left*/
    struct square* adjoins[4]; /* top right bottom left*/
} Square;

void printSquares(Square** squares, const int n) {
#ifdef PRINT_FLAG
    printf("\n---------- square ----------\n");
    int i, j;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            printf("|\t%d\t | ", squares[i+j*n]->datas[0]);
        }
        printf("\n");
        for (i = 0; i < n; i++) {
            printf("|%d\t\t%d| ", squares[i+j*n]->datas[3], squares[i+j*n]->datas[1]);
        }
        printf("\n");
        for (i = 0; i < n; i++) {
            printf("|\t%d\t | ", squares[i+j*n]->datas[2]);
        }
        printf("\n\n");
    }
#endif
}

void findSquares(Square** squares, const int n) {
    int i = 0;
    Square* sq = squares[0];
    for (i = 1; i < n*n; i++) {
        Square* sq2 = squares[i];
        if (sq->adjoins[0] == NULL && sq->datas[0] == sq2->datas[2]) { /* sq2在sq1s上边 */
            sq->adjoins[0] = sq2;
        } else if (sq->adjoins[1] == NULL && sq->datas[1] == sq2->datas[3]) { /* sq2在sq1右边 */
            sq->adjoins[1] = sq2;
        } else if (sq->adjoins[2] == NULL && sq->datas[2] == sq2->datas[0]) { /* sq2在sq1s下边 */
            sq->adjoins[2] = sq2;
        }  else if (sq->adjoins[3] == NULL && sq->datas[3] == sq2->datas[1]) { /* sq2在sq1右边 */
            sq->adjoins[3] = sq2;
        }
    }
}

void gnome_tetravex() {
#ifdef PRINT_FLAG
    printf("problem gnome tetravex problemCode=1008\n");
    printf("please input an int(0~5):\n");
#endif
    while(1) {
        int n = 1;
        scanf("%d", &n);
        if (n == 0) break;
        Square** squares = (Square**)malloc(sizeof(Square*)*n*n);
#ifdef PRINT_FLAG
        printf("input %d ints(0~9) for triangles:\n", n*n*4);
#endif
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                Square* sq = (Square*)malloc(sizeof(Square));
                int k;
                for (k = 0; k < 4; k++)
                    sq->adjoins[k] = NULL;
                scanf("%d %d %d %d", &sq->datas[0], &sq->datas[1], &sq->datas[2], &sq->datas[3]);
                squares[i*n+j] = sq;
            }
        }
        printSquares(squares, n);
        
        findSquares(squares, n);
//        horizentalSwap(squares, n*n);
//        printSquares(squares, n);
//        verticalSwap(squares, n*n);
//        printSquares(squares, n);
    }
}
#endif /* gnome_tetravex_h */
