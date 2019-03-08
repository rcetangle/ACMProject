//
//  fire_net.h
//  AMCProject
//
//  Created by ios on 2019/3/8.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef fire_net_h
#define fire_net_h

void printBoard(int* board, const int n) {
#ifdef PRINT_FLAG
    printf("---------\n");
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", board[i*n+j]);
        }
        printf("\n");
    }
    printf("---------\n");
#endif
}

void setBlockhouse(int* space) {
    *space = 2;
}

void clearBlockhouse(int* space) {
    *space = 0;
}

int checkVertical(int* board, const int n, int row, int col) {
    if (row < 0 || board[row*n+col] == 1) return 1;
    if (board[row*n+col] == 2) {
        int i;
        for (i = col+1; i < n; i++) {
            if (board[row*n+i] == 0 && 1 == checkVertical(board, n, row-1, i)) {
                clearBlockhouse(&board[row*n+col]);
//                printf("%d %d setBlock\n", row, i);
                setBlockhouse(&board[row*n+i]);
                return 1;
            } else if (board[row*n+i] == 2) {
                i = n-1;
            }
        }
        if (i == n) return 0;
    }
    return checkVertical(board, n, row-1, col);
}

void traversalBoard(int* board, const int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int noCastle = 1;
        for (j = 0; j < n; j++) {
            if (board[i*n+j] == 0 && noCastle == 1) {
                if (1 == checkVertical(board, n, i-1, j)) {
//                    printf("%d %d setBlock2s\n", i, j);
                    setBlockhouse(&board[i*n+j]);
                    noCastle = 0;
                }
            }
            if (board[i*n+j] == 1) {
                noCastle = 1;
            }
        }
    }
}

void calculateBoard(int* board, const int n) {
    int ret = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i*n+j] == 2) {
                ret++;
            }
        }
    }
    printf("%d\n", ret);
}

void fire_net() {
#ifdef PRINT_FLAG
    printf("problem Fire Net problemCode=1002\n");
    printf("please input an int(1~4):\n");
#endif
    while(1) {
        int n;
        scanf("%d", &n);
        scanf("%*c"); // flush
        if (n == 0) break;
        int* board = (int*)malloc(sizeof(int)*n*n);
        memset(board, 0, sizeof(int)*n*n);
#ifdef PRINT_FLAG
        printf("please input %d '.'(indicating an open space) or 'X'(indicating a wall) to set up the map:\n", n*n);
#endif
        int i, j;
        char tmp;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%c", &tmp);
                if (tmp == 'X') {
                    board[i*n+j] = 1;
                }
            }
            scanf("%*c"); // flush
        }
        printBoard(board, n);
        traversalBoard(board, n);
        printBoard(board, n);
        calculateBoard(board, n);
        free(board);
        board = NULL;
    }
}

#endif /* fire_net_h */
