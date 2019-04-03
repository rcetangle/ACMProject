//
//  fire_net.h
//  AMCProject
//
//  Created by ios on 2019/3/8.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef fire_net_h
#define fire_net_h

void printBoard(char* board, const int n) {
#ifdef PRINT_FLAG
    printf("---------\n");
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c", board[i*n+j]);
        }
        printf("\n");
    }
    printf("---------\n");
#endif
}

void setBlockhouse(char* space) {
    *space = 'O';
}

void clearBlockhouse(char* space) {
    *space = '.';
}

int isBlockhouse(const char space) {
    return space == 'O'? 1 : 0;
}

int isWall(const char space) {
    return space == 'X'? 1 : 0;
}

int isEmpty(const char space) {
    return space == '.'? 1 : 0;
}

int checkVertical(char* board, const int n, int row, int col) {
    if (row < 0 || isWall(board[row*n+col])) return 1;
    if (isBlockhouse(board[row*n+col])) {
        int i;
        for (i = col+1; i < n; i++) {
            if (isEmpty(board[row*n+i]) && checkVertical(board, n, row-1, i)) {
                clearBlockhouse(&board[row*n+col]);
                setBlockhouse(&board[row*n+i]);
                return 1;
            } else if (isBlockhouse(board[row*n+i])) {
                i = n-1;
            }
        }
        if (i == n) return 0;
    }
    return checkVertical(board, n, row-1, col);
}

void searchBoard(char* board, const int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int noBlockhouse = 1;
        for (j = 0; j < n; j++) {
            if (isEmpty(board[i*n+j]) && noBlockhouse == 1) {
                if (checkVertical(board, n, i-1, j)) {
                    setBlockhouse(&board[i*n+j]);
                    noBlockhouse = 0;
                }
            } else if (isWall(board[i*n+j])) {
                noBlockhouse = 1;
            }
        }
    }
}

void calculateBoard(char* board, const int n) {
    int ret = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i*n+j] == 'O') {
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
    int n;
    while(scanf("%d", &n) != EOF && n != 0) {
        char* board = (char*)malloc(sizeof(char)*n*n);
        memset(board, '.', sizeof(char)*n*n);
#ifdef PRINT_FLAG
        printf("please input %d '.'(indicating an open space) or 'X'(indicating a wall) to set up the map:\n", n*n);
#endif
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%c", &board[i*n+j]);
            }
            scanf("%*c"); // flush
        }
        searchBoard(board, n);
        printBoard(board, n);
        calculateBoard(board, n);
        free(board);
        board = NULL;
    }
}

#endif /* fire_net_h */
