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
    int datas[4]; /* top right bottom left */
    struct square* adjoins[4]; /* pointer of top right bottom left square */
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
        printf("\n");
        for (i = 0; i < n; i++) {
            printf("%p\t", squares[i+j*n]);
        }
        printf("\n");
    }
#endif
}

void markAsHorizentalSquare(Square* a, Square* b) {
    if (a->adjoins[0] == b || b->adjoins[0] == a) return; /* a b已经存在垂直关系 */
    if (a->datas[1] == b->datas[3] && a->adjoins[1] == NULL && b->adjoins[3] == NULL) { /* b在a的右边 */
        a->adjoins[1] = b;
        b->adjoins[3] = a;
    } else if (a->datas[3] == b->datas[1] && a->adjoins[3] == NULL && b->adjoins[1] == NULL) { /* a在b的右边 */
        a->adjoins[3] = b;
        b->adjoins[1] = a;
    }
}

void markAsVerticalSquare(Square* a, Square* b) {
    if (a->adjoins[1] == b || b->adjoins[1] == a) return; /* a b已经存在水平关系 */
    if (a->datas[2] == b->datas[0] && a->adjoins[2] == NULL && b->adjoins[0] == NULL) { /* b在a的下边 */
        a->adjoins[2] = b;
        b->adjoins[0] = a;
    } else if (a->datas[0] == b->datas[2] && a->adjoins[0] == NULL && b->adjoins[2] == NULL) { /* a在b的下边 */
        a->adjoins[0] = b;
        b->adjoins[2] = a;
    }
}

void findSquares(Square** squares, const int n) {
    int i, j;
    for (j = 0; j < n*n-1; j++) {
        Square* sq = squares[j];
        for (i = j+1; i < n*n; i++) {
            Square* sq2 = squares[i];
            markAsHorizentalSquare(sq, sq2); /* 两个正方形的水平关系 */
            markAsVerticalSquare(sq, sq2); /* 两个正方形的垂直关系 */
        }
    }
}

/* 获取头部 */
Square* getHead(Square** squares, const int n) {
    Square* next = squares[0];
    Square* head = NULL;
    while (head == NULL) {
        if (next->adjoins[0] == NULL && next->adjoins[3] == NULL) {
            head = next;
        } else {
            next = next->adjoins[0] == NULL? next->adjoins[3] : next->adjoins[0];
        }
    }
    return head;
}

void printSquares2(Square** squares, const int n) {
#ifdef PRINT_FLAG
    Square* head = getHead(squares, n);

    printf("\n---------- square 2 ----------\n");
    Square* next = head;
    Square* rowHead = NULL;
    char tops[255];
    char middles[255];
    char bottom[255];
    char address[255];
    memset(tops, '\0', 255*sizeof(char));
    memset(middles, '\0', 255*sizeof(char));
    memset(bottom, '\0', 255*sizeof(char));
    memset(address, '\0', 255*sizeof(char));
    int start = 1;
    while (next != NULL) {
        if (next->adjoins[3] == NULL) {
            rowHead = next;
            if (start == 0) {
                printf("%s\n%s\n%s\n%s\n\n", tops, middles, bottom, address);
                memset(tops, '\0', 255*sizeof(char));
                memset(middles, '\0', 255*sizeof(char));
                memset(bottom, '\0', 255*sizeof(char));
                memset(address, '\0', 255*sizeof(char));
            }
            start = 0;
        }
        if (next != NULL) {
            char tmps[20];
            sprintf(tmps,"|\t%d\t | ", next->datas[0]);
            strcat(tops, tmps);
            sprintf(tmps,"|%d\t\t%d| ", next->datas[3], next->datas[1]);
            strcat(middles, tmps);
            sprintf(tmps,"|\t%d\t | ", next->datas[2]);
            strcat(bottom, tmps);
            sprintf(tmps, "%p\t", next);
            strcat(address, tmps);
        }
        next = next->adjoins[1];
        if (next == NULL) {
            next = rowHead->adjoins[2]; // 下一行了
            while (next != NULL && next->adjoins[3] != NULL) {
                next = next->adjoins[3];
            }
        }
    }
    printf("%s\n%s\n%s\n%s\n\n", tops, middles, bottom, address);
#endif
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
        memset(squares, 0, sizeof(Square*)*n*n);
#ifdef PRINT_FLAG
        printf("input %d ints(0~9) for triangles:\n", n*n*4);
#endif
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                Square* sq = (Square*)malloc(sizeof(Square));
                memset(sq->adjoins, 0, sizeof(Square*)*4);
                scanf("%d %d %d %d", &sq->datas[0], &sq->datas[1], &sq->datas[2], &sq->datas[3]);
                squares[i*n+j] = sq;
            }
        }
        printSquares(squares, n);
        
        findSquares(squares, n);
        printSquares2(squares, n);
    }
}
#endif /* gnome_tetravex_h */
