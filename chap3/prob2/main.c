#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINE 100
#define NUM_STRINGS 5

int main() {
    char lines[NUM_STRINGS][MAXLINE];
    char sortedLines[NUM_STRINGS][MAXLINE];

    int len;
    int max = 0;

    for (int i = 0; i < NUM_STRINGS; ++i) {
        fgets(lines[i], MAXLINE, stdin);
        lines[i][strcspn(lines[i], "\n")] = '\0';
    }


    for (int i = 0; i < NUM_STRINGS; ++i) {
        max = i;
        for (int j = i + 1; j < NUM_STRINGS; ++j) {
            if (strlen(lines[j]) > strlen(lines[max])) {
                max = j;
            }
        }

        if (max != i) {
            strcpy(sortedLines[i], lines[max]);
            strcpy(lines[max], lines[i]);
        } else {
            strcpy(sortedLines[i], lines[i]);
        }
    }


    for (int i = 0; i < NUM_STRINGS; ++i) {
        printf("%s\n", sortedLines[i]);
    }

    return 0;
}

