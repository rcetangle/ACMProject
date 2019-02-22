//
//  html.h
//  AMCProject
//
//  Created by ios on 2019/2/14.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef html_h
#define html_h

#include <stdio.h>
#include <string.h>

#define MAX_CNT 80
int getWord(char* output, int* charactorCnt) {
    int scanRet = 0;
    *charactorCnt = 0;
    while(*charactorCnt < MAX_CNT) {
        char character;
        scanRet = scanf("%c", &character);
        if (scanRet == EOF) { // end of file
            break;
        }
        if (character == ' ' || character == '\t' || character == '\n') {
            break;
        } else {
            output[*charactorCnt] = character;
            (*charactorCnt)++;
        }
    }
    return scanRet;
}

void newLine(int* ret) {
    printf("\n");
    *ret = 0;
}

void printHead() {
    int i;
    for (i = 0; i < MAX_CNT; i++) {
        printf("-");
    }
}

static const char* TAGS[2] = {"<br>", "<hr>"};
void html() {
    printf("------ problem html\n");
    int scanRet = 0;
    int totalCharacterCnt = 0;
    while(scanRet != EOF) {
        char word[MAX_CNT];
        memset(word, 0, MAX_CNT);
        int characterCnt = 0;
        scanRet = getWord(word, &characterCnt);
        if (characterCnt == 0) continue;
        if (0 == strcmp(word, TAGS[0])) {
            newLine(&totalCharacterCnt);
        } else if (0 == strcmp(word, TAGS[1])) {
            if (totalCharacterCnt > 0) {
                newLine(&totalCharacterCnt);
            }
            printHead();
            newLine(&totalCharacterCnt);
        } else {
            if (totalCharacterCnt + characterCnt + 1> MAX_CNT) {
                newLine(&totalCharacterCnt);
            }
            if (totalCharacterCnt == 0) {
                printf("%s", word);
                totalCharacterCnt += characterCnt;
            } else {
                printf(" %s", word);
                totalCharacterCnt += characterCnt + 1;
            }
        }
    }
}
#endif /* html_h */
